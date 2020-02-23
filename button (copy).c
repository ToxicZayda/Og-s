#include "header.h"
#include "menu.h"



int in=0;

Button init_button(int x, int y, char name1[], char name2[])
{
    Button bu;
    bu.positionButton.x = x;
    bu.positionButton.y = y;
    bu.image1 = IMG_Load(name1);
    bu.image2 = IMG_Load(name2);
    return bu;
}

void aff_button(Button *bu, int n)
{
    if (n == 1)
        SDL_BlitSurface(bu->image1, NULL, ecran, &bu->positionButton);
    if (n == 2)
        SDL_BlitSurface(bu->image2, NULL, ecran, &bu->positionButton);
}

void souris(SDL_Event event, Button *bu1, Button *bu2, Button *bu3, Button *bu4, int *continu, int *continuer, Menu *m)
{

    Mix_Chunk *sound_but;
    sound_but = Mix_LoadWAV("menu/s.wav");
    SDL_WaitEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        (*continu) = 0;
        (*continuer) = 0;
        Mix_FreeChunk(sound_but);
        break;
    case SDL_MOUSEMOTION:
        if(event.button.x >= 960 && event.button.x <= 960 + bu1->positionButton.w)
        {
            if(event.button.y >= 160 && event.button.y <= 160 + bu1->positionButton.h)
            {
                aff_button(bu1, 2);
                if(in!=1)
                Mix_PlayChannel(1, sound_but, 0);
                in=1;
            }
            else
            {
                if(event.button.y >= 230 && event.button.y <= 230 + bu1->positionButton.h)
                {
                    aff_button(bu2, 2);
                    if(in!=1)
                    Mix_PlayChannel(1, sound_but, 0);
                    in=1;
                }
                else
                {
                    if(event.button.y >= 300 && event.button.y <= 300 + bu1->positionButton.h)
                    {
                        aff_button(bu3, 2);
                        if(in!=1)
                        Mix_PlayChannel(1, sound_but, 0);
                        in=1;
                    }
                    else
                    {
                        if(event.button.y >= 370 && event.button.y <= 370 + bu1->positionButton.h)
                        {
                            aff_button(bu4, 2);
                            if(in!=1)
                            Mix_PlayChannel(1, sound_but, 0);
                            in=1;
                        }
                        else
                        {
                            aff_button(bu1, 1);
                            aff_button(bu2, 1);
                            aff_button(bu3, 1);
                            aff_button(bu4, 1);
                            in=0;
                        }
                    }

                }

            }

        }
        else
        {
            aff_button(bu1, 1);
            aff_button(bu2, 1);
            aff_button(bu3, 1);
            aff_button(bu4, 1);

        }
        break;
    case SDL_MOUSEBUTTONUP:
        if(event.button.x >= 960 && event.button.x <= 1160 && event.button.y >= 160 && event.button.y <= 220 )
            (*continu) = 0;
        if(event.button.x >= 960 && event.button.x <= 1160 && event.button.y >= 400 && event.button.y <= 460)
        {
            (*continu) = 0;
            (*continuer) = 0;
        }
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_UP: // Flèche haut
            m->selected_button--;
            if(m->selected_button < 0)
            {
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                m->selected_button = m->nbre + 1 ;
            }
            switch(m->selected_button)
            {
            case 0:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                m->selected_button = m->nbre + 1;
                break;
            case 1:
                aff_button(bu1, 2);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                break;
            case 2:
                aff_button(bu1, 1);
                aff_button(bu2, 2);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                break;
            case 3:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 2);
                aff_button(bu4, 1);
                break;
            case 4:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 2);
                break;
            }
            break;
        case SDLK_DOWN: // Flèche bas
            m->selected_button++;
            if(m->selected_button > 4)
            {
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                m->selected_button = 0;
            }
            switch(m->selected_button)
            {
            case 0:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                m->selected_button = 0;
                break;
            case 1:
                aff_button(bu1, 2);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                break;
            case 2:
                aff_button(bu1, 1);
                aff_button(bu2, 2);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                break;
            case 3:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 2);
                aff_button(bu4, 1);
                break;
            case 4:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 2);
                break;
            case 5:
                aff_button(bu1, 1);
                aff_button(bu2, 1);
                aff_button(bu3, 1);
                aff_button(bu4, 1);
                m->selected_button = 0;
                break;
            }
            break;
        }
        break;

    }
}