#include "hero.h"
#include "header.h"
void init_hero(Hero *h)
{
    h->positionhero.x = 640;
    h->positionhero.y = 260;
    h->sprite[0]=IMG_Load("mvt/r1.png");
	h->sprite[1]=IMG_Load("mvt/r2.png");
	h->sprite[2]=IMG_Load("mvt/r4.png");
	h->sprite[3]=IMG_Load("mvt/r5.png");
	h->sprite[4]=IMG_Load("mvt/r6.png");
	h->sprite[5]=IMG_Load("mvt/flip.png");
	h->sprite[6]=IMG_Load("mvt/l1.png");
	h->sprite[7]=IMG_Load("mvt/l2.png");
	h->sprite[8]=IMG_Load("mvt/l4.png");
	h->sprite[9]=IMG_Load("mvt/l5.png");
	h->sprite[10]=IMG_Load("mvt/l6.png");
	h->frame=0;
	h->direction = 'r';
}
void aff_hero(Hero *h)
{
    SDL_BlitSurface(h->sprite[h->frame] , NULL, ecran, &h->positionhero);
}
void free_hero(Hero *h)
{
	int i;
	for(i=0;i<11;i++)
	{
	SDL_FreeSurface(h->sprite[i]);
	}
}