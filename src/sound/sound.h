#ifndef SOUND_H
#define SOUND_H

#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>


void enableSound();
void playMusic();
void resetMusic();

extern int timerCounter;
extern int currentBeat;

#endif
