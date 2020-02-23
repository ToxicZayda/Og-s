#include "header.h"

background init_back(char background_name[])
{
    background b;
    b.imageDeFond = IMG_Load(background_name);
    b.positionFond.x = 0;
    b.positionFond.y = 0;
    
    return b;
}
void  init_SDL()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("tanit.png"), NULL);
    ecran = SDL_SetVideoMode(1280, 590, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("The Call Of Justice", NULL);
    music = Mix_LoadMUS("catching-a-killer.mp3");
    Mix_PlayMusic(music, -1);

}
void aff_back(background b)
{
    SDL_BlitSurface(b.imageDeFond, NULL, ecran, &b.positionFond);
}