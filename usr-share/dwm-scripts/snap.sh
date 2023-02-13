#!/usr/bin/env bash

# ----------------------------------------------------------------------------
# --- Simple screenshot script using maim and AwesomeWM API
# --
# -- Accepts `area` and `full` string args
# --
# -- For more details check `man maim`
# --
# -- @author manilarome &lt;gerome.matilla07@gmail.com&gt;
# -- @copyright 2020 manilarome
# -- @script snap
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# -- QR Code From:
# -- https://github.com/jayden-chan/dotfiles/blob/7f4ab0257604a52b3f5befe73cf21a5f95a19f54/scripts/screenshot.sh#L13
# ----------------------------------------------------------------------------

screenshot_dir=$(xdg-user-dir PICTURES)/Screenshots/

# Check save directory
# Create it if it doesn't exist
function check_dir() {
	if [ ! -d "$screenshot_dir" ];
	then
		mkdir -p "$screenshot_dir"
	fi
}

# Main function
function shot() {

	check_dir

	file_loc="${screenshot_dir}$(date +%Y%m%d_%H%M%S).png"
	
	maim_command="$1"

	# Execute maim command
	${maim_command} "${file_loc}"

	# Exit if the user cancels the screenshot
	# So it means there's no new screenshot image file
	if [ ! -f "${file_loc}" ];
	then
		exit;
	fi

	# Copy to clipboard
	xclip -selection clipboard -t image/png -i "${screenshot_dir}"/`ls -1 -t "${screenshot_dir}" | head -1` &

}

# qr function
function qr_code() {
	
	maim_command="$1"
	tmp_file=$(mktemp -t QR-XXXXXX)
	
	# Execute maim command
	${maim_command} ${tmp_file}

	# Covert qr code and copy to clipboard	
	zbarimg --quiet --raw $tmp_file | tr -d '\n' | xclip -selection clipboard

	rm "$tmp_file"

}

# Check the args passed
if [ -z "$1" ] || ([ "$1" != 'full' ] && [ "$1" != 'area' ] && [ "$1" != 'qr' ]);
then
	echo "
	Requires an argument:
	area 	- Area screenshot
	full 	- Fullscreen screenshot
	qr		- QR screenshot and process

	Example:
	./snap area
	./snap full
	./snap qr
	"
elif [ "$1" = 'full' ];
then
	shot 'maim -o -u -m 1'
elif [ "$1" = 'area' ];
then
	shot 'maim -o -u -s -n -m 1'
elif [ "$1" = 'qr' ];
then
	qr_code 'maim -o -u -s -n -m 1'
fi

