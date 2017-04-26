/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminus:size=8" };
static const char dmenufont[]       = "Terminus:size=8";
static const char normbordercolor[] = "#073642";
static const char normbgcolor[]     = "#002b36";
static const char normfgcolor[]     = "#839496";
static const char selbordercolor[]  = "#93a1a1";
static const char selbgcolor[]      = "#073642";
static const char selfgcolor[]      = "#93a1a1";

static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel] =  { selfgcolor,  selbgcolor,  selbordercolor },
};

/* tagging */
static const char *tags[] = { "1" };
 
static const char pp_moni[]  = "pdfpc - presenter";
static const char pp_proj[]  = "pdfpc - presentation";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered  isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            False,      True,        -1 },
	{ NULL,       NULL,       "Scratch",  0,            True,       True,        -1 },
	{ NULL,       NULL,       "mail",     1 << 3,       False,      False,       -1 },
	{ NULL,       NULL,       "irc",      1 << 2,       False,      False,       -1 },
	{ NULL,       NULL,       "Terminal", 1,            False,      False,       -1 },
	{ "Firefox",  NULL,       NULL,       1 << 1,       False,      False,       -1 },
	{ NULL, "Tor Browser",    NULL,       1 << 1,       False,      False,       -1 },
	{ "Spotify",  NULL,       NULL,       1 << 5,       False,      False,       -1 },
	{ NULL,       NULL,       pp_moni,    0,            False,      True,       2  },
	{ NULL,       NULL,       pp_proj,    0,            False,      True,       1  },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TK(KEY,TAG) \
	{ KeyPress, MODKEY,                         KEY,  view,        {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static const char *mpdmenu_library[]  = { "mpdmenu", "-l", "::", "-i", "-l", "3", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *mpdmenu_playlist[] = { "mpdmenu", "-p", "::", "-i", "-l", "3", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *clipmenu[]         = { "clipmenu", "-i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *passmenu[]         = { "passmenu", "-i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static Key keys[] = {
  TK(                     XK_i,            0               )
	{ KeyPress,   MODKEY|ShiftMask,   XK_space,        togglefloating, {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* vim: set noexpandtab: */
