typedef struct player
{
   UBYTE x;
   UBYTE y;

   UBYTE w;
   UBYTE h;
} Player;

void renderPlayer(Player *p);
void updatePlayer(Player *p);
