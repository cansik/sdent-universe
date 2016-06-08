#ifndef SCORE_H
#define SCORE_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>

#include "scoreTiles.h"

typedef struct score
{
   UBYTE score;
   BYTE fail;
} Score;

void displayScore();
void renderScore(Score *s);

#endif
