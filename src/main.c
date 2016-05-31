#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "menu/menu.h"
#include "game/game.h"
#include "about/about.h"
#include "story/story.h"

void main() {
    UBYTE choice;
    
    displayStory();
    
    while(1)
    {
        choice = mainMenu();
        switch(choice) {
          case 1:
              play();
              break;
          case 2:
              //Highscore
              break;
          case 3:
              displayAbout();
              break;
      }
      

      wait_vbl_done();
    }
}
