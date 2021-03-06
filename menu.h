#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
    SDL_Surface *image1,*image2 ;
    SDL_Rect positionButton;
    int state;
}Button;

typedef struct
{
    SDL_Surface *image_menu ;
    SDL_Rect positionMenu;
    int nbre;
    Button B[10];
    int selected_button;
    int muted;
}Menu;
typedef struct
{
    SDL_Surface *animation[32] ;
    SDL_Rect position;
    int frame;
}animated;

void hover_button(Menu *m,int pos);
int mouse_input(SDL_Event event,Menu *m);
Menu init_menu(char name[],int n);
void aff_menu(Menu *m);
Button init_button(int x, int y, char *name1, char *name2 );
void aff_button(Menu *m);
void souris(SDL_Event event,int *destination,int *continu,Menu *m);
int MenuOp();
int MenuP();
void souris_MenuOp(SDL_Event event, int *destination, int *continu, Menu *m);
void free_menu(Menu *m);

void init_animation(animated *a);
void aff_animation(animated *a);
void animation(animated *a);
void free_animation(animated *a);

#endif 