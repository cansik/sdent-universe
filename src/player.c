#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/drawing.h>

#include "player.h"

typedef struct player
{
   UBYTE x;
   UBYTE y;

   UBYTE w;
   UBYTE h;
};

void renderPlayer(Player *p)
{
  box(p->x, p->y, p->x + p->w, p->y + p->h, M_FILL);
  box(20, 20, 50, 50, M_FILL);
  //plot_point(p->x, p->y);
}

void updatePlayer(Player *p)
{
  UBYTE x,y,i;

  i = joypad();

  x = p->x;
  y = p->y;

  if(i & J_UP)
     y -= 1;
  if(i & J_DOWN)
     y += 1;
  if(i & J_LEFT)
     x -= 1;
  if(i & J_RIGHT)
     x += 1;

  // check bounds
  if(x > 0 && x + p->w < GRAPHICS_WIDTH)
  {
      p->x = x;
  }

  if(y > 0 && y + p->h < GRAPHICS_HEIGHT)
  {
      p->y = y;
  }
}
