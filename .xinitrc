#!/bin/sh

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs
setxkbmap -layout gb &
systemctl --user import-environment DISPLAY &
lxsession -e DWM -s DWM &
sh -c 'xrandr --output HDMI-A-0 --mode 1920x1080 --rate 60.00 --output DisplayPort-2 --mode 2560x1440 --rate 144 --left-of HDMI-A-0' &
redshift -t 6500:3500 -l "Lat":"Lon" &
slstatus &
steam-native &
discord &
thunderbird &
#vivaldi-stable --use-vulkan --enable-native-gpu-memory-buffers --use-gl=desktop --ignore-gpu-blocklist --enable-gpu-rasterization --enable-oop-rasterization --enable-zero-copy --enable-features=VaapiVideoDecoder &
vivaldi-stable &
cider &
#$HOME/.BuildFiles/linux-wallpaperengine/build/wallengine --screen-root DP-0 --screen-root HDMI-0 2076369304 &
sh $HOME/.fehbg &
numlockx &
exec dwm
