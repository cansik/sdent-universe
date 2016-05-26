#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <rand.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "trash.h"
#define NUMOFTRASH 10 

Trash trashes[NUMOFTRASH];
UBYTE seed = 0;

void initTrash() {
    UBYTE i, z;
    if (seed >= 255) {
        seed = 1;
    }
    initarand(seed);
    seed++;
    for(i = 0; i < NUMOFTRASH; i++)
     {   
         z = rand();
         if (z > 160) {
             z -= 160;
         }
         trashes[i].x = z;
         z = rand();
         if (z > 160) {
             z -= 160;
         }
         trashes[i].y = z;
         trashes[i].sprite = i+1;
         trashes[i].value = 1;
         
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
