#include "hero.h"
#include "header.h"
void mouvement(SDL_Event event, Hero *h)
{
    char direction;
    int deplacement = 15;
    if(event.type == SDL_KEYDOWN)
    {
        h->frame++;
        if(event.key.keysym.sym == SDLK_RIGHT)
        {
            deplacement = 15;
            if(h->frame >= 5)
                h->frame = 0;
            direction = 'r';
        }
        else
        {
            deplacement = -15;
            if(h->frame <= 5 || h->frame >= 10)
                h->frame = 6;
            direction = 'l';
        }
        if(h->direction != direction)
        {
            h->frame = 5;
            h->direction = direction;
        }
        h->positionhero.x += deplacement;
    }
    else
    {
        if(h->direction == 'r')
        {
            h->frame = 0;
        }
        if(h->direction == 'l')
        {
            h->frame = 6;
        }
    }
}
void jump(SDL_Event event, Hero *h)
{
    int i;
    for(i=0;i<20;i++){
        h->positionhero.y-=2;
        SDL_BlitSurface(h->sprite[h->frame], NULL, ecran, &h->positionhero);
        SDL_Flip(ecran);
        SDL_Delay(20);
    }
    for(i=0;i<20;i++){
        h->positionhero.y+=2;
        SDL_BlitSurface(h->sprite[h->frame], NULL, ecran, &h->positionhero);
        SDL_Flip(ecran);
        SDL_Delay(20);
    }
}
void getInput(SDL_Event event, int *continuer, Hero *h)
{
    int i;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        (*continuer) = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        
        case SDLK_UP: // Flèche haut
          // jump(event, h);
           break;
        /*case SDLK_DOWN: // Flèche bas
           break;*/
        case SDLK_RIGHT:
            mouvement(event, h);
            break;
        case SDLK_LEFT: // Flèche gauche
            mouvement(event, h);
            break;
        }
        break;
    case SDL_KEYUP:

        switch(event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            mouvement(event, h);
            break;
        case SDLK_LEFT: // Flèche gauche
            mouvement(event, h);
            break;
        }
        break;
    }
}