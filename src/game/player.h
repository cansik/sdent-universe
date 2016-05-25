typedef struct player
{
   UBYTE x;
   UBYTE y;

   UBYTE w;
   UBYTE h;
} Player;

void initPlayer();
void renderPlayer(Player *p);
UBYTE updatePlayer(Player *p);
