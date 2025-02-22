static const struct arg args[] = {
	{ run_command, "^c#ddc7a1^^b#32302f^   ^b#252423^%s", "~/.local/bin/moc.sh", NULL },
/*  { run_command, "^b#32302f^ 󰼱  ^b#252423^ %s ", "curl wttr.in/Tartu?format=1 | cut -c 8-14" },*/
  { netspeed_rx, "^b#32302f^   ^b#252423^ %s ", "wlan0" },
  { run_command, "^b#32302f^   ^b#252423^ %s ", "free -h | awk '/^Mem/ {print $3}' | sed s/i//g" },
  { run_command, "^b#32302f^   ^b#252423^ %s ", "df -h | awk 'NR==7{print $4}'" },
  { run_command, "^b#32302f^   ^b#252423^ %s ", "amixer get Master | awk -F'[][]' 'END{ print $7 $2 }'" },
  { run_command, "^c#4c6766^^b#32302f^   ^b#252423^ %s ", "brightnessctl | grep -oP '[^()]+%'" },
  { run_command, "^b#32302f^   ^b#252423^ %s ", "checkupdates | wc -l" },
  { keymap,      "^b#32302f^   ^b#252423^ %s ", NULL },
  { datetime,    "^b#32302f^   ^b#252423^ %s ", "%H:%M" },
/*  { run_command, "^b#32302f^ 󰁺 ^b#252423^ %s ", "acpi -b | cut -c 18-21" },*/
/*  { battery_perc, "^b#32302f^   ^b#252423^ %s%% ", "BAT1" },*/
  { run_command, "^c#b24f42^^b#32302f^  ^b#252423^ %s   ", "bluetoothctl info E1:6A:CA:98:35:9B | awk 'NR==21{print $4}' | cut -c 2-3" },
};
