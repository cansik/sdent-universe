#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "player.h"
#include "menu.h"

void main() {
    UBYTE state;
    Player p = {50, 50, 5, 5};
    Menu m = {20, 20, 50, 50, 0};

    //0 = menu, 1 = play
    state = 0;

    printf("Trasher");
    printf("\nPress Start");
    waitpad(J_START);

    color(LTGREY,WHITE,SOLID);

    while(1)
    {
      //draw
      if(state == 0)
      {

        renderMenu(&m);
        if (updateMenu(&m) == 1)
        {
          // warning: could be written better
          state = 1;
        }
      }

      if(state == 1)
      {
        renderPlayer(&p);
        updatePlayer(&p);
      }

      wait_vbl_done();
    }
}
