#!/bin/sh
###github.com/aquaverso2077
case "$(echo -e "Shutdown-\nRestart--\nLogout---\nSuspend--\nLock-----" | dmenu \
    -nb "${COLOR_BACKGROUND:-#252423}" \
    -nf "${COLOR_DEFAULT:-#ddc7a1}" \
    -sf "${COLOR_HIGHLIGHT:-#93947b}" \
    -sb "#1a1a1a" \
    -b -i -p \
    " Power:" -l 5)" in
        Shutdown-) exec loginctl poweroff;;
        Restart--) exec loginctl reboot;;
        Logout---) pkill -KILL -u $USER;;
        Suspend--) exec loginctl suspend;;
        Lock-----) exec slock;;
esac
