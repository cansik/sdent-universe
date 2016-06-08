#include "game.h"


void play() {
    Player p = {50, 50, 5, 5};
    UBYTE score = 0;
    Score s = {0, 0};
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
    initScore();

    resetMusic();

    while(1) {
        renderPlayer(&p);
        if (updatePlayer(&p) || s.fail >= 20) {
            saveScore(&s);
            cleanupTrash();
            cleanupPlayer();
            return;
        }
        updateTrash(p.x, p.y, &s);
        renderScore(&s);

        playMusic(10);

        delay(10);
    }
}
