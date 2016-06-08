#include "trash.h"


#define NUMOFTRASH 10
#define X_MARGIN 8
#define Y_MARGIN 8

Trash trashes[NUMOFTRASH];
UBYTE seed = 0;
UBYTE level = 1;

void trash(Trash *t) {
    UBYTE z;
    z = rand();
    if (z > 160) {
        z -= 160;
    }
    if (z < PADDING_WIDTH) {
        z = PADDING_WIDTH;
    }
    t->x = z;
    t->y = 0;
    t->speed = (rand() & 1) + 1; //Alternative 7
    t->value = 1;
}

void initTrash() {
    UBYTE i;
    if (seed >= 255) {
        seed = 1;
    }
    initarand(seed);
    seed++;
    for(i = 0; i < NUMOFTRASH; i++)
    {
        trashes[i].value = 1;
        trashes[i].speed = (rand() & 1) + 1;
        trashes[i].sprite = i+4;
        trashes[i].x = 0;
        trashes[i].y = 0;
        set_sprite_tile(trashes[i].sprite,i%2+4);
        move_sprite(trashes[i].sprite,trashes[i].x,trashes[i].y);
     }
}

void cleanupTrash() {
    UBYTE i;
    for (i = 0; i < NUMOFTRASH; i++) {
        move_sprite(trashes[i].sprite, 0, 0); //Move them out of view, is there a better way?
    }
    level = 1;
}

void updateTrash(UBYTE x, UBYTE y, Score *s) {
    UBYTE i;
    for (i = 0; i < level; i++) {
        if(trashes[i].x <= x + X_MARGIN && trashes[i].x >= x && trashes[i].y <= y + Y_MARGIN && trashes[i].y >= y) {
          trashes[i].x = 0;
          trashes[i].y = 0;
          move_sprite(trashes[i].sprite, 0, 0);
          s->score++;
          s->fail--;
        } else {
            trashes[i].y+=trashes[i].speed;
            if (trashes[i].x != 0 && trashes[i].y > GRAPHICS_HEIGHT+PADDING_HEIGHT) {
                trash(&trashes[i]);
                s->fail++;
            }
            move_sprite(trashes[i].sprite, trashes[i].x, trashes[i].y);
        }
    }
}
