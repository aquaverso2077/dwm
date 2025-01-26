#!/bin/sh

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
pulseaudio &
dunst &
xset r rate 250 30 &
nitrogen --restore &
slstatus &
setxkbmap -layout us,ru -option 'grp:ctrl_shift_toggle' &
#xsetroot -name "Good Morning, AquaVerso!" &

## soft
#telegram-desktop &
#zen-browser &
#pcmanfm &
#chromium &
#qutebrowser &

#xautolock -time 10 -locker slock &

exec dbus-run-session -- dwm
