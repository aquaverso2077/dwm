static const char col_gray1[]       = "#ddc7a1";
static const char col_gray2[]       = "#252423";
static const char col_gray3[]       = "#32302f";
static const char col_gray4[]       = "#ea6962";
static const char col_cyan[]        = "#63645c";
static const char col_blue[]        = "#93947b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray1, col_gray2, col_cyan },
	[SchemeSel]  = { col_gray4, col_gray2,  col_blue  }, /*title */
};
