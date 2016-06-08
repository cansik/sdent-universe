#ifndef TRASH_H
#define TRASH_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <rand.h>
#include <gb/console.h>
#include <gb/drawing.h>
#include "../score/score.h"

#include "constants.h"

typedef struct trash
{
   UBYTE x;
   UBYTE y;
   UBYTE speed;

   UBYTE sprite;
   UBYTE value;
} Trash;

void initTrash();
void cleanupTrash();

void updateTrash(UBYTE x, UBYTE y, Score *s);

#endif
