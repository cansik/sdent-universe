#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "sound/sound.h"

void main() {
    int t = 0;
    enableSound();

    while(1)
    {
      if(t == 16)
      {
        playMusic();
        t = 0;
      }
      t++;
    }
}
