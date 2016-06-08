#include "score.h"

void displayScore() {
    int joy;

	DISPLAY_OFF;
	HIDE_BKG;
    HIDE_SPRITES;


  /*************************************************************************/
  /* Next, the tile-data is send to the display;
  /*************************************************************************/

  //set_bkg_data( 0, 213, aboutTiles );

  /*************************************************************************/
  /* Now it's time to send the map-data to the display. Again, in two      */
  /* steps, as the tiles and attributes reside in different banks.         */
  /* The data is send to the display by using the command:                 */
  /*   set_bkg_tiles( Left, Top, Width, Height, Map-data )                 */
  /*************************************************************************/

  VBK_REG = 1;

  VBK_REG = 0;
  //set_bkg_tiles(0,0,aboutMapWidth,aboutMapHeight,aboutMap);



  /*************************************************************************/
  /* the remaining code init the Gameboy and makes it wait untill you turn */
  /* it off..                                                              */
  /*************************************************************************/

  //SHOW_BKG;
  DISPLAY_ON;

   do
   {
   	joy = joypad();
   } while (!joy);
	waitpadup();

  	HIDE_BKG;
      
    return;
}


UBYTE getTileNumberFromNumber(UBYTE num) {
    return num + 24;
}

void initScore() {
    SPRITES_8x8;      /* sets sprites to, yep you guessed it, 8x16 mode */

    set_sprite_data(20, 14, scoreTiles);   /* defines the sprite data */
    set_sprite_tile(20,20);
    set_sprite_tile(21,21);
    set_sprite_tile(22,22);
    set_sprite_tile(23,23);
    set_sprite_tile(24,getTileNumberFromNumber(0));
    set_sprite_tile(25,getTileNumberFromNumber(0));
    set_sprite_tile(26,getTileNumberFromNumber(0));

    move_sprite(20,108,148);
    move_sprite(21,116,148);
    move_sprite(22,124,148);
    move_sprite(23,132,148);
    move_sprite(24,140,148);
    move_sprite(25,148,148);
    move_sprite(26,156,148);
}

void renderScore(Score *s) {

    UBYTE h = s->score/100;
    set_sprite_tile(24,getTileNumberFromNumber(h));
    set_sprite_tile(25,getTileNumberFromNumber((s->score-h)/10));
    set_sprite_tile(26,getTileNumberFromNumber(s->score%10));
}

void saveScore(Score *s) {
    lastscore = s->score;
    if (lastscore > highscore) {
        highscore = lastscore;
    }
}
