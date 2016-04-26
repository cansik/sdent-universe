#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>

#include "menu.h"
#include "menuTiles.h"
#include "menuMap.h"
#include "pointerTiles.h"

#define ITEMCOUNT 0x03

UBYTE pointerX = 36;
UBYTE currSelection = 1;
UBYTE pointerY[] =
{
  0, /*unused */
  80,  /*PLAY*/
  92,  /*HIGHSCORE*/
  104  /*Third Point*/
};

void setupPointer() {
  SPRITES_8x8;

   set_sprite_data(0, 1, pointerTiles);

   set_sprite_tile(0, 0);

   move_sprite(0, pointerX, pointerY[currSelection]);

   SHOW_SPRITES;
}

void movePointer() {
  move_sprite(0, pointerX, pointerY[currSelection]);
}

UBYTE checkInput() {
  UBYTE i;
  static UBYTE lastButton;
  i = joypad();
  if (!i) {
    lastButton = 0;
  }

  if(i & J_UP && lastButton != J_UP) {
      currSelection -= 1;
      if (currSelection < 1) {
        currSelection = ITEMCOUNT;
      }
      lastButton = J_UP;
  }

  if(i & J_DOWN && lastButton != J_DOWN) {
    currSelection += 1;
    if (currSelection > ITEMCOUNT) {
      currSelection = 1;
    }
    lastButton = J_DOWN;
  }
  

  if(i & J_START || i & J_A)
    return currSelection;

  return 0;
}

UBYTE mainMenu() {
  UBYTE selection;
  DISPLAY_OFF;
  HIDE_BKG;

  move_bkg(0,0);
  
  set_bkg_data( 0, 110, menuTiles );
  // Switch to VRAM
  VBK_REG = 1;

  // Switch out of VRAM
  VBK_REG = 0;
  set_bkg_tiles(0,0,menuMapWidth,menuMapHeight,menuMap);

  SHOW_BKG;
  DISPLAY_ON;
  
  setupPointer();
  
  while(1) {
    selection = checkInput();
    movePointer();
    if (selection > 0) {
      return selection;
    }
  }
}
