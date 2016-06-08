#include "score.h"

void displayScore() {}

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
