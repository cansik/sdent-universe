#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/drawing.h>

#include "player.h"

#define WINSZX    0x80                  /* Size of the picture in the window */
#define WINSZY    0x50

void main() {
    UBYTE c;
    Player p = {50, 50, 10, 10};

    c=50;

    printf("The Vacuumizor");
    printf("\nPress Start");
    waitpad(J_START);

    color(LTGREY,WHITE,SOLID);

    while(1)
    {
      //draw
      renderPlayer(&p);
      updatePlayer(&p);

      wait_vbl_done();
    }
}
