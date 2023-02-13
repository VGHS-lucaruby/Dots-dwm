#!/usr/bin/env bash

# Check the args passed and change vol
if [ -z "$1" ] || ([ "$1" != 'volupam' ] && [ "$1" != 'voldwnam' ] && [ "$1" != 'volupvi' ] && [ "$1" != 'voldwnvi' ] && [ "$1" != 'volrst' ]);
then
	echo "
	Requires an argument:
	volupam 	- raise apple-music-electron volume
    voldwnam 	- lower apple-music-electron volume
	volupcb 	- raise vivaldi volume
    voldwncb 	- lower vivladi volume
	volrst      - resets volume of chromium (super hacky)

	Example:
	./vol volup
    ./vol voldwn
    "
elif [ "$1" = 'volupam' ];
then
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep cider | sed 's/[a-zA-Z|"-]//g') +1%

elif [ "$1" = 'voldwnam' ];
then
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep cider | sed 's/[a-zA-Z|"-]//g') -1%

elif [ "$1" = 'volupvi' ];
then
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep 'vivaldi-bin' | sed 's/[a-zA-Z()|"-]//g') +1%

elif [ "$1" = 'voldwnvi' ];
then
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep 'vivaldi-bin' | sed 's/[a-zA-Z()|"-]//g') -1%


elif [ "$1" = 'volrst' ];
then
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep 'vivaldi-bin' | sed 's/[a-zA-Z()|"-]//g') 100%
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.process.binary)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep cider | sed 's/[a-zA-Z()|"-]//g') 100%
	pactl set-sink-input-volume $(pactl list sink-inputs | sed -r -n '/^Sink Input/{s@^[^#]+#@@g;p};/^[[:space:]]*(application.name)/{s@^[^=]+=[[:space:]]*@@g;p};/^:/{s@.*?[[:space:]]+([[:digit:]]+)%.*@\1@g;p};/^$/{s@.*@---@g;p}' | sed ':a;N;$!ba;s@\n@|@g' | sed -r -n 's@\|?---\|?@\n@g;p' | grep 'WEBRTC VoiceEngine' | sed 's/[a-zA-Z()|"-]//g') 100%
fi
