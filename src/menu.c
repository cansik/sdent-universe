#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

#include "menu.h"

#define ITEMCOUNT 0x03

void renderMenu(Menu *m)
{
  box(m->x, m->y, m->x + m->w, m->y + m->h, M_FILL);
  //box(20, 20, 50, 50, M_FILL);
  //plot_point(p->x, p->y);

  //gotoxy(9, posy());
  //printf("Play");
}

UBYTE updateMenu(Menu *m)
{
  UBYTE s,i;

  i = joypad();

  if(i & J_UP)
      s = m->selectedItem - 1;

  if(i & J_DOWN)
     s = m->selectedItem + 1;

  m->selectedItem = s % ITEMCOUNT;

  if(i & J_START)
    return 1;

  return 0;
}
