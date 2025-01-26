#!/bin/bash
#https://github.com/aquaverso2077
## Укажите путь к каталогу с обоями
wallpaper_dir="/home/av/git/wallpapers"
#
## Получите список всех файлов в каталоге и подкаталогах
wallpapers=$(find "$wallpaper_dir" -type f -name "*.jpg")
#
## Случайным образом выберите один из файлов
wallpaper=$(echo "$wallpapers" | shuf -n 1)
#
## Установите обои
nitrogen --set-zoom-fill "$wallpaper"
