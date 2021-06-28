#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "jeu.h"

int DeplacementTourBlanche (plateau board, SDL_Rect PositionClicDestination, int n);
int DeplacementRoiBlanc(plateau board, SDL_Rect destination, int n);
int DeplacementCavalierBlanc(plateau board, SDL_Rect destination, int n);
int DeplacementPionBlanc (plateau board, SDL_Rect PositionClicDestination, int n);
int DeplacementFouBlanc (plateau board, SDL_Rect PositionClicDestination, int n);
int DeplacementDameBlanche(plateau board, SDL_Rect destination, int n);

int DeplacementTourNoire (plateau board, SDL_Rect destination, int n);
int DeplacementRoiNoir(plateau board, SDL_Rect destination, int n);
int DeplacementCavalierNoir(plateau board, SDL_Rect destination, int n);
int DeplacementPionNoir (plateau board, SDL_Rect PositionClicDestination, int n);
int DeplacementFouNoir (plateau board, SDL_Rect PositionClicDestination, int n);
int DeplacementDameNoire(plateau board, SDL_Rect destination, int n);




#endif // DEPLACEMENT_H_INCLUDED
