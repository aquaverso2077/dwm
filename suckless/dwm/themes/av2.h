/* color */
static const char col_gray1[]       = "#ddc7a1";
static const char col_gray2[]       = "#252423";
static const char col_gray3[]       = "#32302f";
static const char col_gray4[]       = "#ea6962";
static const char col_cyan[]        = "#63645c";
/*color status */
static const char col_blue[]        = "#93947b";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray1, col_gray2, col_cyan },
	[SchemeSel]  = { col_gray2, col_blue,  col_blue  }, /*title */
    [SchemeTagsSel]  = { col_gray4, col_gray2 },
    [SchemeTagsNorm]  = { col_gray1, col_gray2 },
 /* [SchemeStatus] = { col_gray1, col_green },*/
/*  [SchemeTagsSel]  = { col_gray4, col_cyan },
  [SchemeTagsNorm]  = { col_gray4, col_blue },*/
};
