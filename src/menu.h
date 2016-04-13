typedef struct menu
{
  UBYTE x;
  UBYTE y;
  UBYTE w;
  UBYTE h;

  UBYTE selectedItem;
} Menu;

void renderMenu(Menu *m);
UBYTE updateMenu(Menu *m);
