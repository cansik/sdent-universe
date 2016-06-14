#include "score.h"

UBYTE getTileNumberFromNumber(UBYTE num) {
    return num + 24;
}

void displayScore() {
    int joy;
    UBYTE h, k;

	DISPLAY_OFF;
	HIDE_BKG;
    HIDE_SPRITES;


  /*************************************************************************/
  /* Next, the tile-data is send to the display;
  /*************************************************************************/

  set_bkg_data( 0, 94, scoreMapTiles );

  /*************************************************************************/
  /* Now it's time to send the map-data to the display. Again, in two      */
  /* steps, as the tiles and attributes reside in different banks.         */
  /* The data is send to the display by using the command:                 */
  /*   set_bkg_tiles( Left, Top, Width, Height, Map-data )                 */
  /*************************************************************************/

  VBK_REG = 1;

  VBK_REG = 0;
  set_bkg_tiles(0,0,scoreMapWidth,scoreMapHeight,scoreMap);



  /*************************************************************************/
  /* the remaining code init the Gameboy and makes it wait untill you turn */
  /* it off..                                                              */
  /*************************************************************************/

  SHOW_BKG;
  DISPLAY_ON;
  SPRITES_8x8;
  set_sprite_data(20, 14, scoreTiles);   /* defines the sprite data */
  h = highscore[0]/100;
  set_sprite_tile(0,getTileNumberFromNumber(h));
  set_sprite_tile(1,getTileNumberFromNumber((highscore[0]-(h*100))/10));
  set_sprite_tile(2,getTileNumberFromNumber(highscore[0]%10));
  k = lastscore[0]/100;
  set_sprite_tile(3,getTileNumberFromNumber(k));
  set_sprite_tile(4,getTileNumberFromNumber((lastscore[0]-(k*100))/10));
  set_sprite_tile(5,getTileNumberFromNumber(lastscore[0]%10));

  move_sprite(0, 88, 45);
  move_sprite(1, 96, 45);
  move_sprite(2, 104, 45);

  move_sprite(3, 88, 93);
  move_sprite(4, 96, 93);
  move_sprite(5, 104, 93);

  SHOW_SPRITES;

   do
   {
   	joy = joypad();
   } while (!joy);
	waitpadup();

  	HIDE_BKG;
      
    return;
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
    set_sprite_tile(25,getTileNumberFromNumber((s->score-(h*100))/10));
    set_sprite_tile(26,getTileNumberFromNumber(s->score%10));
}

void saveScore(Score *s) {
    lastscore[0] = s->score;
    if (lastscore[0] > highscore[0] || highscore[0] == 255) {
        highscore[0] = lastscore[0];
    }
}

void cleanupScore() {
    UBYTE i;
    for (i = 20; i<27;i++) {
        move_sprite(i,0,0);
    }
}
