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
    UBYTE i;
    initarand(seed);
    seed += 1;
    for(i = 0; i < NUMOFTRASH; i++)
     {
         trashes[i].x = rand() & 159;
         trashes[i].y = rand() & 143;
         trashes[i].sprite = i+1;
         trashes[i].value = 1;
         
         set_sprite_tile(trashes[i].sprite,i%3+3); 
         move_sprite(trashes[i].sprite,trashes[i].x,trashes[i].y);   
     }
}