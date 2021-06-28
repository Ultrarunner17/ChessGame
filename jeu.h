#ifndef JEU_H_
#define JEU_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***************** STRUCTURES *****************/

typedef enum {BLANC,NOIR} couleur;

typedef enum {ALIVE,DEAD} etat;

typedef enum {PION,TOUR,CAVALIER,FOU,DAME,ROI} typePiece;

typedef struct piece
{
    couleur color;
    typePiece type;
    SDL_Rect coordinate;
    etat state;
}piece;


typedef struct plateau
{
    piece* tabPiece;
}plateau;

//**********FONCTIONS**********//

void pause();
plateau initialisePlateau();
void creationCadriage(SDL_Surface* ecran, SDL_Surface* tabRectangles[8][8]);
void placementPieces(plateau board, SDL_Surface* ecran,SDL_Surface* surfacePieces[]);
SDL_Rect getClicPosition();
int selectionnerPiece(plateau board,SDL_Surface* ecran, SDL_Surface* caseSelectionnee, couleur joueurQuiJoue);
void affichePiecesMortes(plateau board, SDL_Surface* ecran, TTF_Font *policeT15, SDL_Color couleurTexte, SDL_Color couleurtexte2);
int echecBlanc(plateau board, int n);
int echecNoir(plateau board, int n);
int echecEtMatBlanc (plateau board);
int echecEtMatNoir (plateau board);




#endif // JEU_H_INCLUDED
