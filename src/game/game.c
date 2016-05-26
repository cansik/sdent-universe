#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>

#include "game.h"
#include "player.h"
#include "spaceTiles.h"
#include "spaceMap.h"
#include "trash.h"

void play() {
    Player p = {50, 50, 5, 5};
    
    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    
    move_bkg(0,0);
 
    set_bkg_data( 0, 76, spaceTiles );
  // Switch to VRAM
    VBK_REG = 1;

  // Switch out of VRAM
    VBK_REG = 0;
    set_bkg_tiles(0,0,spaceMapWidth,spaceMapHeight,spaceMap);

    SHOW_BKG;
    
    DISPLAY_ON;
    initPlayer();
    initTrash();
    while(1) {
        renderPlayer(&p);
        if (updatePlayer(&p)) {
            cleanupTrash();
            return;
        }
        updateTrash();
        delay(15);
    }
}
