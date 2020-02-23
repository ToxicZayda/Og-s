#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


typedef struct
{
    SDL_Surface *sprite[50] ;
    SDL_Rect positionhero;
    int frame;
    char direction;

} Hero;

void init_hero(Hero *h);
void aff_hero(Hero *h);
void getInput(SDL_Event event, int *continuer, Hero *h);
void free_hero(Hero *h);

#endif // HEADER_H_INCLUDED