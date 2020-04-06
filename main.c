#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

int main(int argc, char *argv[])
{

    SDL_Window *pWindow=NULL;           //Pointeur sur la fen�tre, ref d'un window win32
    SDL_Renderer *pRenderer=NULL;       //Pointeur sur le Rendus, ref rendu encapsul� dans window
    SDL_Texture *pTexture=NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)    //INIT_EVERYTHING = initialise l'audio, la vid�o, les contr�les,... cf; SDL wiki/API by name/SDL_Init
    {
        //succ�s, cr�er window
        pWindow=SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 780, SDL_WINDOW_SHOWN);//x,y,width,eight

        //si succ�s, cr�er window et renderer
        if(pWindow!=NULL)
        {
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
            SDL_SetRenderTarget(pRenderer, NULL); //red�finitions de la zone de travail
            SDL_Surface* pPng = IMG_Load("WoodCrate.png");
            SDL_Texture* Image = SDL_CreateTextureFromSurface(pRenderer,pPng);

            SDL_FreeSurface(pPng);

            if (Image == NULL)
              printf("erreur");

            SDL_Rect myRect;
            myRect.x = 0;
            myRect.y = 0;
            SDL_QueryTexture(Image, NULL, NULL, &myRect.w, &myRect.h);//R�cup�re le format de l'image

            SDL_RenderCopy(pRenderer, Image, NULL, &myRect);
            SDL_RenderPresent(pRenderer);

            SDL_Delay(10000);

            SDL_DestroyRenderer(pRenderer); //On supprime tout ce qui � �t� cr��
            SDL_DestroyWindow(pWindow);
            SDL_Quit();

            }
        }

    return 0;
}
