#include "about.h"

#define INPUT_DELAY 150

void displayAbout() {
    int joy;

	DISPLAY_OFF;
	HIDE_BKG;
    HIDE_SPRITES;


  /*************************************************************************/
  /* Next, the tile-data is send to the display;
  /*************************************************************************/

  set_bkg_data( 0, 213, aboutTiles );

  /*************************************************************************/
  /* Now it's time to send the map-data to the display. Again, in two      */
  /* steps, as the tiles and attributes reside in different banks.         */
  /* The data is send to the display by using the command:                 */
  /*   set_bkg_tiles( Left, Top, Width, Height, Map-data )                 */
  /*************************************************************************/

  VBK_REG = 1;

  VBK_REG = 0;
  set_bkg_tiles(0,0,aboutMapWidth,aboutMapHeight,aboutMap);



  /*************************************************************************/
  /* the remaining code init the Gameboy and makes it wait untill you turn */
  /* it off..                                                              */
  /*************************************************************************/

  SHOW_BKG;
  DISPLAY_ON;

  delay(INPUT_DELAY);

   do
   {
   	joy = joypad();
   } while (!joy);
	waitpadup();

  	HIDE_BKG;

   return;
}
