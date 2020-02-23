#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
    SDL_Surface *imageDeFond ;
    SDL_Rect positionFond;

} background;
SDL_Surface *ecran;
Mix_Music *music;
int Game();
background init_back(char background_name[]);
void init_SDL();
void aff_back(background b);

#endif // HEADER_H_INCLUDED
