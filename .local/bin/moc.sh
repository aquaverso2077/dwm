#!/bin/bash
##https://github.com/aquaverso2077
. /tmp/mocp_popup.txt
. /tmp/mocp_state.txt
 
# Переменная хранит разделитель между артистом и названием
# Для радио это как правило ' - '
SEPARATOR=" - "
 
# Блок отвечает за формирование строк
# Если в воспроизводимом файле есть http://, значит проигрыватся радио
if [ $(mocp -Q %file | grep http://) ]
  then
    PLAYER="Radio"
    # Если нет названия песни
    if [ -z "$(mocp -Q %song)" ]
      then
        # Выводим адрес с которого идет проигрывание
        FIRST_LINE="RadioSite"
        SECOND_LINE="$(mocp -Q %file | sed 's/http:\/\///g')"
      else
        # Если название песни присутствует
        SONG="$(mocp -Q %song)"
        # Выводим артиста
        FIRST_LINE="${SONG%*$SEPARATOR*}"
        # Выводим название
        SECOND_LINE="${SONG#*$SEPARATOR*}"
    fi
  else
    # Если воспроизводится не радио
#    PLAYER="MoC"
    if [ -z "$(mocp -Q %song)" ]
      then
        # Выводим что тегов нет
        FIRST_LINE="No Title"
        SECOND_LINE="No Title"
      else
        # Выводим артиста
        FIRST_LINE="$(mocp -Q %artist)"
        # Выводим название
        SECOND_LINE="$(mocp -Q %song)"
    fi
fi
 
NEWNAME="$FIRST_LINE - $SECOND_LINE"
NEWNAME="$(echo $NEWNAME | sed 's/\&/And/g' | sed 's/\`//g')"
NEWSTATE="$(mocp --info | grep State: | awk '{print $2}')"
 
if [ $NEWSTATE == STOP ]; then
  exit 1
fi
 
# Выводим информацию в conky
if [[ $NEWSTATE == "PLAY" ]]; then
  echo "$PLAYER" "$NEWNAME "
  else
    echo "$PLAYER N/A" "$OLDNAME"
fi
