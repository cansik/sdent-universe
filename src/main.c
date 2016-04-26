#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "menu/menu.h"
#include "game/game.h"

void main() {
  UBYTE choice;
    


    while(1)
    {
      choice = mainMenu();
      switch(choice) {
        case 1:
          play();
          break;
        case 2:
          play();
          break;
      }
      

      wait_vbl_done();
    }
}
