#! /bin/bash
## https://github.com/aquaverso2077/
track=`mocp -Q %title | cut -d " " -f 1`
if [ $(echo $track | wc -L) -lt 2 ] && [ "$(echo $track | grep [0-9])" = "$track" ] ; then track="0$track" ; fi
notify-send -i "$HOME/.icons/av2/devices/48/media-tape.svg" \
"$track $(mocp -Q '%song -')" "$(mocp -Q '%artist') $(mocp -Q '[%tt]')"
