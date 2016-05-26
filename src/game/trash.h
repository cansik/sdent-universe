typedef struct trash
{
   UBYTE x;
   UBYTE y;
   UBYTE speed;

   UBYTE sprite;
   UBYTE value;
} Trash;

void initTrash();
void cleanupTrash();

void updateTrash();