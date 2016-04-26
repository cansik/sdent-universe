#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>

#include "game.h"
#include "player.h"


void play() {
    Player p = {50, 50, 5, 5};
    
    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    
    DISPLAY_ON;
    
    while(1) {
        renderPlayer(&p);
        if (updatePlayer(&p)) {
            return;
        }
    }
}