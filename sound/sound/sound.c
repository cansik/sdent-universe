#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>

#include "sound.h"

INT16 timerCounter = 0;
int currentBeat = 0;
int chainCounter = 0;

/* Here's a look at how I created a quick music player for use with GBDK.
It basically defines how to play a note, and then stores an array of notes
to be played as a timer interates through the beats */

//Define note names
typedef enum {
  C3, Cd3, D3, Dd3, E3, F3, Fd3, G3, Gd3, A3, Ad3, B3,
  C4, Cd4, D4, Dd4, E4, F4, Fd4, G4, Gd4, A4, Ad4, B4,
  C5, Cd5, D5, Dd5, E5, F5, Fd5, G5, Gd5, A5, Ad5, B5,
  C6, Cd6, D6, Dd6, E6, F6, Fd6, G6, Gd6, A6, Ad6, B6,
  C7, Cd7, D7, Dd7, E7, F7, Fd7, G7, Gd7, A7, Ad7, B7,
  C8, Cd8, D8, Dd8, E8, F8, Fd8, G8, Gd8, A8, Ad8, B8,
  SILENCE
} pitch;

const UWORD frequencies[] = { //values based on a formula used by the GB processor
  44, 156, 262, 363, 457, 547, 631, 710, 786, 854, 923, 986,
  1046, 1102, 1155, 1205, 1253, 1297, 1339, 1379, 1417, 1452, 1486, 1517,
  1546, 1575, 1602, 1627, 1650, 1673, 1694, 1714, 1732, 1750, 1767, 1783,
  1798, 1812, 1825, 1837, 1849, 1860, 1871, 1881, 1890, 1899, 1907, 1915,
  1923, 1930, 1936, 1943, 1949, 1954, 1959, 1964, 1969, 1974, 1978, 1982,
  1985, 1988, 1992, 1995, 1998, 2001, 2004, 2006, 2009, 2011, 2013, 2015,
  0
};

//Define Instrument names
//Instruments should be confined to one channel
//due to different registers used between ch1, 2, 3, 4
typedef enum {
	NONE,
	MELODY,  //channel 1
	HARMONY, //channel 1
  BASS,    //channel 2
  BASSDRUM, //channel 4
	SNARE,   //channel 4
	CYMBAL,   //channel 4
  HIHAT    //channel 4
} instrument;

//Define a note as having a pitch, instrument, and volume envelope
typedef struct {
	instrument i;
	pitch p;
	UBYTE env;
} note;

typedef struct {
  UBYTE c1;
  UBYTE c2;
  UBYTE c3;
  UBYTE c4;
} chain;

chain menu_track[8] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {1, 1, 0, 0},
  {1, 1, 0, 1},

  {0, 1, 0, 1},
  {0, 1, 0, 0},
  {1, 1, 0, 1},
  {1, 0, 0, 1},
};

//define a song as a series of note structs
//This song is a 16 note loop on channel 1
//each channel should have its own array, so
//that multiple notes can be played simultaneously
note song_ch1[32] = { //notes to be played on channel 1
  {MELODY, F4, 0x83U},
  {MELODY, A4, 0x83U},
  {MELODY, D4, 0x83U},
  {NONE, SILENCE, 0x00U},

  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {MELODY, F4, 0x83U},
  {MELODY, A4, 0x83U},
  {MELODY, G4, 0x83U},
  {NONE, SILENCE, 0x00U},

  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {MELODY, F4, 0x83U},
  {MELODY, A4, 0x83U},
  {MELODY, C5, 0x83U},
  {NONE, SILENCE, 0x00U},

  {MELODY, G4, 0x83U},
  {NONE, SILENCE, 0x00U},
  {MELODY, F4, 0x83U},
  {MELODY, D4, 0x83U},

  {MELODY, F4, 0x83U},
  {MELODY, A4, 0x83U},
  {MELODY, G4, 0x83U},
  {NONE, SILENCE, 0x00U},

  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U}
};

note song_ch2[32] = { //notes to be played on channel 2
  {BASS, C3, 0x83U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},

  {BASS, C3, 0x83U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},

  {BASS, C3, 0x83U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},

  {BASS, C3, 0x83U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},
  {BASS, C3, 0x51U},

  {BASS, D3, 0x83U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},

  {BASS, D3, 0x83U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},

  {BASS, D3, 0x83U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},

  {BASS, D3, 0x83U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U},
  {BASS, D3, 0x51U}
};

note song_ch4[32] = { //notes to be played on channel 4
  {BASSDRUM, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {SNARE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {BASSDRUM, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {SNARE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {BASSDRUM, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {SNARE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {NONE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {BASSDRUM, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},

  {SNARE, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U},
  {HIHAT, SILENCE, 0x00U},
  {NONE, SILENCE, 0x00U}
};

//function to set sound registers based on notes chosen
void setNote(note *n){
	switch((*n).i){
		case MELODY:
			NR10_REG = 0x00U; //pitch sweep
			NR11_REG = 0x81U; //wave duty
			NR12_REG = (*n).env; //envelope
			NR13_REG = (UBYTE)frequencies[(*n).p]; //low bits of frequency
			NR14_REG = 0x80U | ((UWORD)frequencies[(*n).p]>>8); //high bits of frequency (and sound reset)
		break;
    case BASS:
			NR21_REG = 0x84U;
			NR22_REG = (*n).env;
			NR23_REG = (UBYTE)frequencies[(*n).p];
			NR24_REG = 0x80U | ((UWORD)frequencies[(*n).p]>>8);
      break;
		case BASSDRUM:
      NR41_REG = 0x07U;
      NR42_REG = 0x72U;
      NR43_REG = 0x6FU;
      NR44_REG = 0x80U;
		break;
    case SNARE:
      NR41_REG = 0x07U;
      NR42_REG = 0x72U;
      NR43_REG = 0x37U;
      NR44_REG = 0x80U;
    break;
		case HIHAT:
      NR41_REG = 0x07U;
      NR42_REG = 0x71U;
      NR43_REG = 0x11U;
      NR44_REG = 0x80U;
		break;
    case CYMBAL:
      NR41_REG = 0x07U;
      NR42_REG = 0x73U;
      NR43_REG = 0x11U;
      NR44_REG = 0x80U;
    break;
	}
}

void playChannel1(){
	setNote(&song_ch1[currentBeat]);
	NR51_REG |= 0x11U; //enable sound on channel 1
}

void playChannel2(){
	setNote(&song_ch2[currentBeat]);
	NR51_REG |= 0x22U; //enable sound on channel 2
}

void playChannel4(){
  setNote(&song_ch4[currentBeat]);
  NR51_REG |= 0x88U; //enable sound on channel 3
}

void playChannels(chain *c)
{
  if((*c).c1 == 1) {
    playChannel1();
  }

  if((*c).c2 == 1) {
    playChannel2();
  }

  //if((*n).c3) {playChannel3();}
  if((*c).c4 == 1) {
    playChannel4();
  }
}

void playMusic(){
  // only play all 512 updates
	if (timerCounter == 480)
  {
		timerCounter=0;

    // check which channel to fire
    playChannels(&menu_track[chainCounter]);

    if(currentBeat == 31)
    {
      currentBeat = 0;

      // increase chain counter
      chainCounter = chainCounter == 7 ? 0 : chainCounter+1;
    }
    else
    {
      currentBeat++;
    }
	}
	timerCounter++;
}

void enableSound()
{
  NR52_REG = 0x80; // All channels on
  NR50_REG = 0xFF; // Vin SO01 & Vin S002 On -> Volume Max
}

void resetMusic()
{
  currentBeat = 0;
  timerCounter = 0;
  chainCounter = 0;
}
