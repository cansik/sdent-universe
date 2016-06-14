#include "main.h"

void main() {
    UBYTE choice;
    enableSound();

    ENABLE_RAM_MBC1;

    while(1)
    {
        resetMusic();

        choice = mainMenu();
        switch(choice) {
          case 1:
              displayStory();
              play();
              break;
          case 2:
              displayScore();
              break;
          case 3:
              displayAbout();
              break;
      }

      wait_vbl_done();
    }

    DISABLE_RAM_MBC1;
    
    return;
}
