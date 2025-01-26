/* settings */
static const unsigned int borderpx  = 2;
static const unsigned int snap      = 24;
static const int showbar            = 1;
static const int topbar             = 0;
static const unsigned int gappx     = 4;
static const char *fonts[]          = { "Terminess Nerd Font:size=14" };
static const int vertpad            = 8;       /* vertical padding of bar */
static const int sidepad            = 8;       /* horizontal padding of bar */
static const int user_bh						= 48;

/* theme */
#include "themes/av2.h"

/* XF86* keys */
#include <X11/XF86keysym.h>
/* Movestack */
#include "movestack.c"

/* workspace */
static const char *tags[] = { "󱗝", "󱗝", "󱗝", "󱗝", "󱗝" };
static const char *alttags[] = { "󱗜", "󱗜", "󱗜", "󱗜", "󱗜" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",             NULL,       NULL,       1 << 4,       0,           -1 },
	{ "librewolf-bin",    NULL,       NULL,       1 << 1,       0,           -1 },
	{ "zen",				NULL,       NULL,       1 << 1,       0,           -1 },
	{ "qutebrowser",      NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Chromium",      NULL,       NULL,       1 << 1,       0,           -1 },
	{ "vifm",             NULL,       NULL,       1 << 2,       0,           -1 },
	{ "Pcmanfm",          NULL,       NULL,       1 << 2,       0,           -1 },
	{ "TelegramDesktop",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Popcorn-Time",     NULL,       NULL,       1 << 4,       0,           -1 },
	{ "steam",     	      NULL,       NULL,       1 << 4,       0,           -1 },
  { "Nl.hjdskes.gcolor3",          NULL,       NULL,       0,            1,           -1 },
  { "Lxappearance",     NULL,       NULL,       0,            1,           -1 },
  { "Viewnior",         NULL,       NULL,       0,            1,           -1 },
  { "Nitrogen",         NULL,       NULL,       0,            1,           -1 },
  { "VSCodium",         NULL,       NULL,       1 << 4,       0,           -1 },
  { "photoshop.exe",    NULL,       NULL,       1 << 4,       0,           -1 },
  { "Galculator",       NULL,       NULL,       0,            1,           -1 },
  { "pavucontrol",      NULL,       NULL,       0,            1,           -1 },
  { "fragments",				NULL,       NULL,       1,            1,           -1 },
  { "Pulseaudio-equalizer-gtk",				NULL,       NULL,       1,            1,           -1 },
  { "pulsemixer",				NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	{ "󰝥",      tile },
	{ "󰝦",      NULL },   
	{ "▲",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]    = { "dmenu_run", NULL };
static const char *termcmd[]     = { "st", NULL };
static const char *webcmd[]      = { "qutebrowser", NULL };

/* filemanager */
static const char *filcmd[]      = { "st", "-c", "vifm", "-e", "vifm", NULL };
/*static const char *filcmd[]      = { "kitty", "--class", "vifm", "vifm", NULL };*/

/*pulsemixer*/
static const char *pulsecmd[]      = { "st", "-c", "pulsemixer", "-e", "pulsemixer", NULL };

/* bluetooth */
static const char *bluetoothcmd[]  = { "st", "-e", "bluetuith", NULL };

/* vol */
static const char *upvol[]       = { "amixer", "set", "Master", "5%+",		NULL };
static const char *downvol[]     = { "amixer", "set", "Master", "5%-",		NULL };
static const char *mutevol[]     = { "amixer", "set", "Master", "toggle", NULL };

/* playerctl */
static const char *player1cmd[]       = { "playerctl", "play-pause", NULL };
static const char *player2cmd[]       = { "playerctl", "previous", NULL };
static const char *player3cmd[]       = { "playerctl", "next", NULL };

/* brightness */
static const char *brupcmd[]     = { "brightnessctl", "set", "10%+", NULL };
static const char *brdowncmd[]   = { "brightnessctl", "set", "60%-", NULL };

/* screenshot */
static const char *cmdprint[]    = { "scrot", "-q 100", "/home/av/Scrot/%Y-%m-%d-%s.png", NULL };
static const char *cmdprint2[]    = { "scrot", "-s", "-q 100", "/home/av/Scrot/%Y-%m-%d-%s.png", NULL };

/* quit */
static const char *powermcmd[]   = { "/home/av/.local/bin/powermenu.sh", NULL };

/* wallchange */
static const char *wallcmd[]     = { "/home/av/.local/bin/wallpaper.sh", NULL };

static const char *mocp1cmd[]     = { "mocp", "--next", NULL };
static const char *mocp2cmd[]     = { "mocp", "--previous", NULL };
static const char *mocp3cmd[]     = { "mocp", "--toggle-pause", NULL };

static const Key keys[] = {
  
  { 0,                  XF86XK_AudioPlay,                   spawn, { .v = player1cmd } },
  { 0,                  XF86XK_AudioPrev,                   spawn, { .v = player2cmd } },
  { 0,                  XF86XK_AudioNext,                   spawn, { .v = player3cmd } },
  { MODKEY,                  XK_c,													spawn, { .v = bluetoothcmd } },
	{ MODKEY,                 XK_KP_End,											spawn, { .v = mocp2cmd } },
  { MODKEY,                 XK_KP_Next,											spawn, { .v = mocp1cmd } },
  { MODKEY,                 XK_KP_Down,											spawn, { .v = mocp3cmd } },
  { 0,                       XK_F11,												spawn, { .v = wallcmd } },
  { MODKEY,                  XK_F11,					 spawn,       SHCMD("killall slstatus || slstatus &") },
  { 0,                  XF86XK_TouchpadOn,     spawn,       SHCMD("notify-send '[Touchpad is ON]'") },
  { 0,                  XF86XK_TouchpadOff,    spawn,       SHCMD("notify-send '[Touchpad is OFF]'") },
  { MODKEY,                  XK_x,						 spawn,          { .v = powermcmd } },
  { MODKEY,                  XK_F10,					 spawn,       SHCMD("redshift -P -O 3500 || notify-send '[NightMode]'") },
  { 0,       XF86XK_MonBrightnessUp,					 spawn,          { .v = brupcmd } },
  { 0,       XF86XK_MonBrightnessDown,				 spawn,          { .v = brdowncmd } },
	{ 0,                       XK_Print,				 spawn,          { .v = cmdprint } },
	{ MODKEY,                  XK_Print,				 spawn,          { .v = cmdprint2 } },
  { MODKEY,                       XK_F2,       spawn,          { .v = webcmd } },
  { MODKEY,                       XK_F3,       spawn,          { .v = filcmd } },
  { 0,          XF86XK_AudioRaiseVolume,       spawn,					 { .v = upvol } },
  { 0,          XF86XK_AudioLowerVolume,       spawn,          { .v = downvol } },
  { 0,                 XF86XK_AudioMute,       spawn,          { .v = mutevol } },
	/* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          { .v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          { .v = termcmd } },
	{ MODKEY,                       XK_v,			 spawn,          { .v = pulsecmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
/*	{ MODKEY|ShiftMask,             XK_x,      quit,           {0} },*/
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
