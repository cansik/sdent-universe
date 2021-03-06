#include "player.h"

UBYTE x_bound;
UBYTE y_bound;
unsigned char satelite[] =
{
  /* Player top left */
  0x01,0x01,0x03,0x03,0x02,0x03,0x02,0x03,
  0x06,0x07,0x06,0x07,0x0C,0x0F,0x0D,0x0E,
  /* Player top right */
  0x80,0x80,0xC0,0xC0,0x40,0xC0,0x40,0xC0,
  0x60,0xE0,0x60,0xE0,0x30,0xF0,0xB0,0x70,
  /* Player bottom left */
  0x1B,0x1C,0x1B,0x1C,0xF2,0xFC,0x86,0xF8,
  0x83,0xFC,0xF8,0xFF,0x0F,0x0F,0x0E,0x0A,
  /* Player bottom right */
  0xD8,0x38,0xD8,0x38,0x4F,0x3F,0x61,0x1F,
  0xC1,0x3F,0x1F,0xFF,0xF0,0xF0,0x70,0x50,
  /* Trash 01 */
  0x40,0x40,0xAC,0xEC,0x5E,0x7E,0x3E,0x2E,
  0x7C,0x74,0x7A,0x7E,0x35,0x37,0x02,0x02,
  /* Trash 02 */
  0x02,0x02,0x35,0x37,0x7A,0x7E,0x7C,0x74,
  0x3E,0x2E,0x5E,0x7E,0xAC,0xEC,0x40,0x40
};

void initPlayer() {
    x_bound = GRAPHICS_WIDTH+PADDING_WIDTH - 8;
    y_bound = GRAPHICS_HEIGHT+PADDING_HEIGHT - 8;

    SPRITES_8x8;      /* sets sprites to, yep you guessed it, 8x16 mode */

    set_sprite_data(0, 6,satelite);   /* defines the sprite data */
    set_sprite_tile(0,0);
    set_sprite_tile(1,1);
    set_sprite_tile(2,2);
    set_sprite_tile(3,3);
}

void renderPlayer(Player *p)
{
  move_sprite(0,p->x,p->y);         /* puts the first sprite on screen */
  move_sprite(1,p->x+8,p->y);
  move_sprite(2,p->x,p->y+8);
  move_sprite(3,p->x+8,p->y+8);

  SHOW_SPRITES;
}

UBYTE updatePlayer(Player *p)
{
  UBYTE x,y,i,speed;

  i = joypad();
  speed = 1;
  x = p->x;
  y = p->y;
  if( i & J_A){
    speed = 3;
  }
  if (i & J_SELECT) {
    return 1;
  }

  if(i & J_UP && y > 0) {
     y -= speed;
  }
  if(i & J_DOWN) {
     y += speed;
  }
  if(i & J_LEFT && x > 0) {
     x -= speed;
  }
  if(i & J_RIGHT) {
     x += speed;
  }

  // check bounds
  if(x >= PADDING_WIDTH && x + p->w < x_bound)
  {
      p->x = x;
  }

  if(y >= PADDING_HEIGHT && y + p->h < y_bound)
  {
      p->y = y;
  }

  return 0;
}

void cleanupPlayer() {
  move_sprite(0,0,0);         /* puts the first sprite on screen */
  move_sprite(1,0,0);
  move_sprite(2,0,0);
  move_sprite(3,0,0);
}
