#include "header.h"
#include "menu.h"
#include "hero.h"

animated an;
int MenuP()
{

    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m0 = init_menu("menu/menu.png", 4);
    //initialisation des boutons
    m0.B[0] = init_button(340, 200, "menu/play.png", "menu/play_active.png");
    m0.B[1] = init_button(340, 290, "menu/options.png", "menu/options_active.png");
    m0.B[2] = init_button(590, 200, "menu/credits.png", "menu/credits_active.png");
    m0.B[3] = init_button(590, 290, "menu/quit.png", "menu/quit_active.png");
    //iniinitialisation du SDL

    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    init_animation(&an);
    SDL_Event even;
    

    while(continu)
    {

        SDL_FillRect(ecran, NULL, 0x000000);
        aff_menu(&m0);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m0);
        aff_animation(&an);
        //Gestion de l'input
        souris(even, &destination, &continu, &m0);
        SDL_Flip(ecran);
    }
    free_menu(&m0);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Flip(ecran);

    return destination;
}
int MenuOp()
{
    int destination;
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleur = {0, 0, 0};
    police = TTF_OpenFont("Ghost Writer - Demo.ttf", 30);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Copyright 2020 - Imperium ", couleur);
    position.x = 1000;
    position.y = 550;

    Menu m1 = init_menu("menu/menu.png", 2);

    //initialisation des boutons
    m1.B[0] = init_button(340, 200, "menu/sound.png", "menu/sound_active.png");
    m1.B[1] = init_button(590, 200, "menu/back.png", "menu/back_active.png");
    //iniinitialisation du SDL
    int continu = 1;
    //Affiche le menu
    //Affiche les boutons initials du menu
    SDL_Event even;
    while(continu)
    {
        SDL_FillRect(ecran, NULL, 0x000000);
        aff_menu(&m1);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        aff_button(&m1);
        aff_animation(&an);
        //Gestion de l'input
        souris_MenuOp(even, &destination, &continu, &m1);
        SDL_Flip(ecran);
    }
    free_menu(&m1);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    return destination;
}
int Game()
{
    free_animation(&an);
    SDL_CloseAudio();
    Mix_FreeMusic(music);
    int destination =  0;
    background b;
    Hero h;
    b = init_back("back.png");
    aff_back(b);
    int continuer = 1;
    init_hero(&h);
    aff_hero(&h);
    SDL_Flip(ecran);
    SDL_Event event;
    SDL_EnableKeyRepeat(100, 100);
    while (continuer)
    {
        getInput(event, &continuer, &h);
        SDL_BlitSurface(b.imageDeFond, NULL, ecran, &b.positionFond);
        SDL_BlitSurface(h.sprite[h.frame], NULL, ecran, &h.positionhero);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(b.imageDeFond);
    free_hero(&h);
    return destination;
}




