#!/bin/sh
sed -i \
         -e 's/#282828/rgb(0%,0%,0%)/g' \
         -e 's/#8f8b7c/rgb(100%,100%,100%)/g' \
    -e 's/#282828/rgb(50%,0%,0%)/g' \
     -e 's/#caa374/rgb(0%,50%,0%)/g' \
     -e 's/#282828/rgb(50%,0%,50%)/g' \
     -e 's/#8f8b7c/rgb(0%,0%,50%)/g' \
	"$@"
