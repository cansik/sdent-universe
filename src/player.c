#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/drawing.h>

#include "player.h"

unsigned char satelite[] =
{
  /* Normal Top */
  0x18,0x00,0x18,0x18,0x18,0x18,0x99,0x7E,
  0x99,0x7E,0x18,0x18,0x18,0x18,0x00,0x00,
  /* 45° Tile */
  0x43,0x02,0x87,0x67,0x0E,0x7E,0x1C,0x3C,
  0x38,0x3C,0x70,0x7E,0x61,0x66,0x02,0x00,
  /* Right */
  0x18,0x00,0x00,0x18,0x00,0x18,0x7F,0x7E,
  0x7F,0x7E,0x00,0x18,0x00,0x18,0x18,0x00
};


void renderPlayer(Player *p)
{
  SPRITES_8x8;      /* sets sprites to, yep you guessed it, 8x16 mode */

  set_sprite_data(0, 3,satelite);   /* defines the sprite data */

  move_sprite(0,p->x,p->y);         /* puts the first sprite on screen */

  SHOW_SPRITES;
}

void updatePlayer(Player *p)
{
  UBYTE x,y,i;

  i = joypad();

  x = p->x;
  y = p->y;

  if(i & J_UP && y > 0) {
     y -= 1;
     set_sprite_tile(0,0); 
     set_sprite_prop(0,0);
  }
  if(i & J_DOWN) {
     y += 1;
     set_sprite_tile(0,0); 
     set_sprite_prop(0,S_FLIPX | 0x01);
  }
  if(i & J_LEFT && x > 0) {
     x -= 1;
     set_sprite_tile(0,2); 
     set_sprite_prop(0,S_FLIPY | 0x01);
  }
  if(i & J_RIGHT) {
     x += 1;
     set_sprite_tile(0,2); 
     set_sprite_prop(0,0);
  }

  // check bounds
  if(x >= 0 && x + p->w < GRAPHICS_WIDTH)
  {
      p->x = x;
  }

  if(y >= 0 && y + p->h < GRAPHICS_HEIGHT)
  {
      p->y = y;
  }
}
