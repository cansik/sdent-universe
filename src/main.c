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
  //plot_point(p->x, p->y);
}

void main() {
    UBYTE c,x,y,i;
    Player p = {50, 50, 10, 10};

    c=50;

    printf("The Vacuumizor");
    printf("\nPress Start");
    waitpad(J_START);  // other keys are J_A, J_UP, J_SELECT, etc.

    color(LTGREY,WHITE,SOLID);

    while(1)
    {
      //draw
      renderPlayer(&p);

      i = joypad();
      x = p.x;
      y = p.y;
      if(i & J_UP)
	       y -= 1;
      if(i & J_DOWN)
	       y += 1;
      if(i & J_LEFT)
	       x -= 1;
      if(i & J_RIGHT)
	       x += 1;

      // check bounds
      if(x > 0 && x + p.w < GRAPHICS_WIDTH)
      {
          p.x = x;
      }

      if(y > 0 && y + p.h < GRAPHICS_HEIGHT)
      {
          p.y = y;
      }

      wait_vbl_done();

      /*
      for (c=0; c<=10; c++) {
        box(140,c*10+15+x,15, 15 + x,M_NOFILL);
        //gprintf("%c",c++);
      }

      //color(WHITE,LTGREY,SOLID);
      //box(0, 0, WINSZX, WINSZY, M_FILL);

      x++;
      //x *= -1;
      */
    }
}
