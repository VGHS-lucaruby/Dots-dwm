/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  			 = 2;        /* border pixel of windows */
static const unsigned int gappx     	 = 9;        /* gaps between windows */
static unsigned int snap      			 = 32;       /* snap pixel */
static int showbar           			 = 1;        /* 0 means no bar */
static int topbar             			 = 1;        /* 0 means bottom bar */
static const char *fonts[]          	 = { "MesloLGS NF:size=10" };
static const char dmenufont[]       	 = "MesloLGS NF:size=10";
static char normbgcolor[]           	 = "#282828";
static char normbordercolor[]       	 = "#504945";
static char normfgcolor[]           	 = "#ebdbb2";
static char selfgcolor[]            	 = "#282828";
static char selbordercolor[]        	 = "#fe8019";
static char selbgcolor[]            	 = "#fe8019";
static char *colors[][3] 				 = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
	[SchemeHid] = { normfgcolor,  normbgcolor, normbordercolor  },
};

static const char *const autostart[] = {
	// "setxkbmap", "-layout", "gb", NULL,
	// "lxsession", NULL,
	// "redshift", "-t", "6500:3500", "-l", "52.95:-1.14", NULL,
	// "slstatus", NULL,
	// "steam-native", NULL,
	// "discord", NULL,
	// "thunderbird", NULL,
	// "vivaldi-stable", "--use-vulkan", "--enable-native-gpu-memory-buffers", "--use-gl=desktop", "--ignore-gpu-blocklist", "--enable-gpu-rasterization", "--enable-oop-rasterization", "--enable-zero-copy", "--enable-features=VaapiVideoDecoder", NULL,
	// "cider", NULL,
	/*	"obs", "--startreplaybuffer", NULL,*/
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "爵", "", "", "", "ﭮ", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      	   		      instance    				title       			  tags mask      isfloating   monitor */
	{ "Vivaldi",       		      NULL,	   	 				NULL,       			  1 << 0,        0,           -1 },
	{ "microsoft-edge",       	  NULL,	   	 				NULL,       			  1 << 0,        0,           -1 },
	{ "Nemo",  	       			  NULL,       				NULL,       			  1 << 1,        0,           -1 },
	{ "File-roller",   		      NULL,       				NULL,       			  1 << 1,        0,           -1 },
	{ "Wine",  	       		      NULL,       				NULL,       			  1 << 2,        0,            0 },
	{ ".exe",   				  NULL, 		 			NULL, 		 			  1 << 2, 	     0, 		   0 },
	{ "steam_app_",   			  NULL, 		 			NULL, 		 			  1 << 2, 	     0, 		   0 },
	{ "steam_proton",  		      NULL,       				NULL,       			  1 << 2,        0,            0 },
	{ "DRAG",  	       		      NULL,       				NULL,       			  1 << 2,        0,            0 },
	{ "Civ6", 		     		  NULL, 		 			NULL, 		 			  1 << 2, 	     0, 		   0 },
	{ "factorio", 		     	  NULL, 		 			NULL, 		 			  1 << 2, 	     0, 		   0 },
	{ "portal2_linux", 		      NULL,       				NULL,       			  1 << 2,        0,            0 },
	{ "Portal",					  NULL,                     NULL,					  1 << 2,		 0,			   0 },
	{ "Shenzhen",      			  NULL,       				NULL,       			  1 << 2,        0,            0 },
	{ "valheim",			  	  NULL,	 	 				NULL,		 			  1 << 2,		 0,			   0 },
	{ "War Thunder",			  NULL,						NULL,					  1 << 2,		 0,			   0 },
	{ "artofrally",				  NULL,						NULL,					  1 << 2,		 0,			   0 },
	{ "Dirt4",					  NULL,						NULL,					  1 << 2,		 0,			   0 },
	{ "PokeMMO", 			      NULL, 		 			NULL, 		 			  1 << 2, 	     0, 		   0 },
	{ "nestopia",				  NULL,		 				NULL,		 			  1 << 2, 		 0,			   0 },
	{ "minecraft",				  NULL,		 				NULL,		 			  1 << 2, 		 0,			   0 },
	{ "Minecraft",				  NULL,		 				NULL,		 			  1 << 2, 		 0,			   0 },
	{ "War",				  	  NULL,		 				NULL,		 			  1 << 2, 		 0,			   0 },
	{ "obs",				 	  NULL,		 				NULL,		 			  1 << 2, 		 0,			   1 },
	{ "Steam",  	   		      NULL,       				NULL,       			  1 << 3,        0,            0 },
	{ "Lutris",  	   		      NULL,       				NULL,       			  1 << 3,        0,            0 },
	{ "org.remmina.Remmina",	  NULL,						NULL,					  1 << 3,		 0,			   0 },
	{ "PrismLauncher",			  NULL,						NULL,					  1 << 3,		 0,			   0 },
	{ "discord",  	   		      NULL,       				NULL,       			  1 << 4,        0,            0 },
	{ "teams-for-linux",  	   	  NULL,       				NULL,       			  1 << 4,        0,            0 },
	{ "thunderbird",			  NULL,						NULL,       			  1 << 5,        0,            0 },
	{ "vlc",  	       		      NULL,       				NULL,       			  1 << 6,        0,           -1 },
	{ "Cider",		     	      NULL,  			    	NULL,	  		  	  	  1 << 6,        0,            1 },
	{ "mpv",     	      		  NULL,  			    	NULL,	  		  	  	  1 << 6,        0,            0 },
	{ "St",  	       		      "st",       				NULL,       			  1 << 7,        0,           -1 },
	{ "Code",  	   		      	  NULL,       				NULL,       			  1 << 8,        0,           -1 },
};

/* window swallowing */
static const int swaldecay = 3;
static const int swalretroactive = 1;
static const char swalsymbol[] = "";

/* layout(s) */
static float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",     dwindle },
	{ "HHH",      grid },
};

/* key definitions */
#include <X11/XF86keysym.h>
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]   = { "st", NULL };
static const char *nemo[]      = { "nemo", NULL };
// static const char *vivaldi[]   = { "vivaldi-stable", "--use-vulkan", "--enable-native-gpu-memory-buffers", "--use-gl=desktop", "--ignore-gpu-blocklist", "--enable-gpu-rasterization", "--enable-oop-rasterization", "--enable-zero-copy", "--enable-features=VaapiVideoDecoder", NULL, };
static const char *vivaldi[]   = { "vivaldi-stable", NULL, };
static const char *snaparea[]  = { "sh", "/usr/share/dwm-scripts/snap.sh", "area", NULL };
static const char *snapfull[]  = { "sh", "/usr/share/dwm-scripts/snap.sh", "full", NULL };
static const char *snapqr[]    = { "sh", "/usr/share/dwm-scripts/snap.sh", "qr", NULL };
static const char *previous[]  = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.cider", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.Previous", NULL };
static const char *playpause[] = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.cider", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.PlayPause", NULL };
static const char *next[]      = { "dbus-send", "--print-reply", "--dest=org.mpris.MediaPlayer2.cider", "/org/mpris/MediaPlayer2", "org.mpris.MediaPlayer2.Player.Next", NULL };
static const char *volupam[]   = { "sh", "/usr/share/dwm-scripts/vol.sh", "volupam", NULL };
static const char *voldwnam[]  = { "sh", "/usr/share/dwm-scripts/vol.sh", "voldwnam", NULL };
static const char *volupvi[]   = { "sh", "/usr/share/dwm-scripts/vol.sh", "volupvi", NULL };
static const char *voldwnvi[]  = { "sh", "/usr/share/dwm-scripts/vol.sh", "voldwnvi", NULL };
static const char *volrst[]    = { "sh", "/usr/share/dwm-scripts/vol.sh", "volrst", NULL };
static const char *slock[]	   = { "slock"};
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "normbgcolor",         STRING,  &normbgcolor },
		{ "normbordercolor",     STRING,  &normbordercolor },
		{ "normfgcolor",         STRING,  &normfgcolor },
		{ "selbgcolor", 	     STRING,  &selbgcolor },
		{ "selbordercolor",		 STRING,  &selbordercolor },
		{ "selfgcolor",          STRING,  &selfgcolor },
};

static Key keys[] = {
	/* modifier                     key        					function        argument */
	{ MODKEY,                       XK_r,      					spawn,          {.v = dmenucmd } },
	{ MODKEY,             			XK_Return, 					spawn,          {.v = termcmd } },
	{ MODKEY,		           		XK_e, 	   					spawn,          {.v = nemo } },
	{ MODKEY,		           		XK_b, 	   					spawn,          {.v = vivaldi } },
	{ MODKEY|ShiftMask,             XK_b,      					togglebar,      {0} },
	{ MODKEY,                       XK_j,      					focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      					focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      					focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      					focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      					incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      					incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask, 			XK_h,      					setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,				XK_l,      					setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Tab, 					zoom,           {0} },
	{ MODKEY,                       XK_Tab,    					view,           {0} },
	{ MODKEY,			            XK_q,      					killclient,     {0} },
	{ MODKEY,                       XK_t,      					setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_c,      					setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      					setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_a,      					setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_a,      					setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_g,      					setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  					setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  					togglefloating, {0} },
	{ MODKEY,                       XK_f,      					togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      					view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      					tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  					focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 					focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_p,      					tagmon,         {.i = -1 } },
	{ MODKEY,		                XK_o,      					tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  					setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  					setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  					setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_s,      					show,           {0} },
	{ MODKEY|ShiftMask,             XK_h,      					hide,           {0} },
	{ MODKEY,                       XK_u,      					swalstopsel,    {0} },
	TAGKEYS(                        XK_1,      					                0)
	TAGKEYS(                        XK_2,      					                1)
	TAGKEYS(                        XK_3,      					                2)
	TAGKEYS(                        XK_4,      					                3)
	TAGKEYS(                        XK_5,      					                4)
	TAGKEYS(                        XK_6,      					                5)
	TAGKEYS(                        XK_7,      					                6)
	TAGKEYS(                        XK_8,      					                7)
	TAGKEYS(                        XK_9,      					                8)
	{ MODKEY|ControlMask,           XK_t,      					quit,           {0} },
	{ MODKEY|ControlMask,			XK_r,     					quit,           {1} }, 
	{ MODKEY|ShiftMask,        		XK_s, 	   					spawn,      	{.v = snaparea } },
	{ MODKEY|ShiftMask,        		XK_f, 	   					spawn,      	{.v = snapfull } },
	{ MODKEY|ShiftMask,        		XK_d, 	   					spawn,      	{.v = snapqr } },
	{ 0,							XF86XK_AudioMute,		    spawn, 		    {.v = volrst } },	
	{ 0,		    				XF86XK_AudioPrev,		    spawn,          {.v = previous } },
	{ 0,							XF86XK_AudioPlay,		    spawn, 		    {.v = playpause } },
	{ 0,							XF86XK_AudioNext,		    spawn, 		    {.v = next } },
	{ 0,							XF86XK_AudioRaiseVolume,    spawn, 		    {.v = volupam } },
	{ 0,							XF86XK_AudioLowerVolume,    spawn, 		    {.v = voldwnam } },
	{ MODKEY,						XF86XK_AudioRaiseVolume,    spawn, 		    {.v = volupvi } },
	{ MODKEY,						XF86XK_AudioLowerVolume,    spawn, 		    {.v = voldwnvi } },
	{ MODKEY,						XK_l,						spawn,			{.v = slock } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask          button          function        argument */
	{ ClkLtSymbol,          0,                  Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                  Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                  Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                  Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                  Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,             Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,             Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,             Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button1,        swalmouse,      {0} },
	{ ClkTagBar,            0,                  Button1,        view,           {0} },
	{ ClkTagBar,            0,                  Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,             Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,             Button3,        toggletag,      {0} },
};

