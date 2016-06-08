#ifndef PLAYER_H
#define PLAYER_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/drawing.h>

#include "constants.h"


typedef struct player
{
   UBYTE x;
   UBYTE y;

   UBYTE w;
   UBYTE h;
} Player;

void initPlayer();
void renderPlayer(Player *p);
UBYTE updatePlayer(Player *p);
void cleanupPlayer();

#endif
