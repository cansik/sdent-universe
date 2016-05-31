#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <rand.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "trash.h"
#include "constants.h"

#define NUMOFTRASH 10
#define X_MARGIN 3
#define Y_MARGIN 6

Trash trashes[NUMOFTRASH];
UBYTE seed = 0;

void trash(Trash *t, UBYTE i) {
    UBYTE z;
    z = rand();
    if (z > 160) {
        z -= 160;
    }
    if (z < PADDING_WIDTH) {
        z = PADDING_WIDTH;
    }
    t->x = z;
    t->y = 0;
    t->speed = rand() & 3; //Alternative 7
    t->sprite = i+1;
    t->value = 1;
}

void initTrash() {
    UBYTE i;
    if (seed >= 255) {
        seed = 1;
    }
    initarand(seed);
    seed++;
    for(i = 0; i < NUMOFTRASH; i++)
     {
        trash(&trashes[i], i);

         set_sprite_tile(trashes[i].sprite,i%3+3);
         move_sprite(trashes[i].sprite,trashes[i].x,trashes[i].y);
     }
}

void cleanupTrash() {
    UBYTE i;
    for (i = 0; i < NUMOFTRASH; i++) {
        move_sprite(trashes[i].sprite, 0, 0); //Move them out of view, is there a better way?
    }
}

void updateTrash(UBYTE x, UBYTE y) {
    UBYTE i;
    for (i = 0; i < NUMOFTRASH; i++) {
        if(trashes[i].x <= x + X_MARGIN && trashes[i].x >= x - X_MARGIN && trashes[i].y <= y + Y_MARGIN && trashes[i].y >= y) {
          trashes[i].x = 0;
          trashes[i].y = 0;
          move_sprite(trashes[i].sprite, 0, 0);
        } else {
            trashes[i].y+=trashes[i].speed;
            if (trashes[i].y > GRAPHICS_HEIGHT+PADDING_HEIGHT) {
                trash(&trashes[i], i);
            }
            move_sprite(trashes[i].sprite, trashes[i].x, trashes[i].y);
        }
    }
}
