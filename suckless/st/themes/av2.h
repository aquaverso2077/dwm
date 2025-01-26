static const char *colorname[] = {
	/* 8 normal colors */
	[0] = "#282828", /* hard contrast: #1d2021 / soft contrast: #32302f */
	[1] = "#ea6962", /* red     */
	[2] = "#a9b665", /* green   */
	[3] = "#d8a657", /* yellow  */
	[4] = "#7daea3", /* blue    */
	[5] = "#d3869b", /* magenta */
	[6] = "#89b482", /* cyan    */
	[7] = "#d4be98", /* white   */

	/* 8 bright colors */
	[8]  = "#928374", /* black   */
	[9]  = "#ef938e", /* red     */
	[10] = "#bbc585", /* green   */
	[11] = "#e1bb7e", /* yellow  */
	[12] = "#9dc2ba", /* blue    */
	[13] = "#e1acbb", /* magenta */
	[14] = "#a7c7a2", /* cyan    */
	[15] = "#e2d3ba", /* white   */
};
/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 15;
unsigned int defaultbg = 0;
unsigned int defaultcs = 15;
static unsigned int defaultrcs = 257;