#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>

#include "storyTiles.h"
#include "storyMap.h"

#define STORY_DELAY 150

void loadStory1() {
    DISPLAY_OFF;
	HIDE_BKG;
    HIDE_SPRITES;

    set_bkg_data( 0, STORY1COUNT, story1Tiles );
    VBK_REG = 1;

    VBK_REG = 0;
    set_bkg_tiles(0,0,storyMapWidth,storyMapHeight,story1Map);

    SHOW_BKG;
    DISPLAY_ON;
    delay(STORY_DELAY);
}

void loadStory2() {
    DISPLAY_OFF;
	  HIDE_BKG;
    HIDE_SPRITES;

    set_bkg_data( 0, STORY2COUNT, story2Tiles );

    VBK_REG = 1;

    VBK_REG = 0;
    set_bkg_tiles(0,0,storyMapWidth,storyMapHeight,story2Map);

    SHOW_BKG;
    DISPLAY_ON;
    delay(STORY_DELAY);

}

void loadStory3() {
    DISPLAY_OFF;
	  HIDE_BKG;
    HIDE_SPRITES;

    set_bkg_data( 0, STORY3COUNT, story3Tiles );

    VBK_REG = 1;

    VBK_REG = 0;
    set_bkg_tiles(0,0,storyMapWidth,storyMapHeight,story3Map);

    SHOW_BKG;
    DISPLAY_ON;
    delay(STORY_DELAY);
}

void loadStory(UBYTE i) {
    if (i == 1) {
        loadStory1();
        return;
    }
    if (i == 2) {
        loadStory2();
        return;
    }
    if (i == 3) {
        loadStory3();
        return;
    }
}

void displayStory() {
    int joy, curr, ch;

	loadStory1();
    curr = 1;

    do
    {
        ch = 0;
        joy = joypad();
        if(joy & J_DOWN) {
            curr++;
            ch = 1;
        }
        if(joy & J_UP) {
            --curr;
            ch = 1;
        }
        if (curr == 0) {
            curr = 1;
            ch = 0;
        }
        if (curr > 3) {
            HIDE_BKG;
            return;
        }
        if (ch == 1) {
            loadStory(curr);
        }
    } while (1);
}
