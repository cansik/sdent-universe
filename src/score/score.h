#ifndef SCORE_H
#define SCORE_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>

#include "scoreTiles.h"
#include "saveScore.h"

typedef struct score
{
   UBYTE score;
   UBYTE fail;
} Score;

void displayScore();
void renderScore(Score *s);
void saveScore(Score *s);
void initScore();

#endif
