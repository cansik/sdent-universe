#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/drawing.h>

#define WINSZX    0x80                  /* Size of the picture in the window */
#define WINSZY    0x50

typedef struct player
{
   UBYTE x;
   UBYTE y;

   UBYTE w;
   UBYTE h;
} Player;

void renderPlayer(Player *p)
{
  box(p->x, p->y, p->x + p->w, p->y + p->h, M_FILL);
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

void main() {
    UBYTE c;
    Player p = {50, 50, 10, 10};

    c=50;

    printf("The Vacuumizor");
    printf("\nPress Start");
    waitpad(J_START);

    color(LTGREY,WHITE,SOLID);

    while(1)
    {
      //draw
      renderPlayer(&p);
      updatePlayer(&p);

      wait_vbl_done();
    }
}
