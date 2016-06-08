#include "score.h"

void displayScore() {}

UBYTE getTileNumberFromNumber(UBYTE num) {
    return num + 14;
}

void initScore() {
    SPRITES_8x8;      /* sets sprites to, yep you guessed it, 8x16 mode */

    set_sprite_data(10, 14, scoreTiles);   /* defines the sprite data */
    set_sprite_tile(10,10);
    set_sprite_tile(11,11);
    set_sprite_tile(12,12);
    set_sprite_tile(13,13);
    set_sprite_tile(14,getTileNumberFromNumber(0));
    set_sprite_tile(15,getTileNumberFromNumber(0));
    set_sprite_tile(16,getTileNumberFromNumber(0));
}

void renderScore(Score *s) {
    if (s->score < 10) {
        set_sprite_tile(16, getTileNumberFromNumber(s->score));
    }


    move_sprite(10,108,148); 
    move_sprite(11,116,148); 
    move_sprite(12,124,148); 
    move_sprite(13,132,148); 
    move_sprite(14,140,148); 
    move_sprite(15,148,148); 
    move_sprite(16,156,148); 


}

