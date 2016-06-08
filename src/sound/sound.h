#ifndef SOUND_H
#define SOUND_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>


void enableSound();
void playMusic(INT16 speed);
void resetMusic();

extern int timerCounter;
extern int currentBeat;
extern int loopCount;

#endif
