#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <SDL/SDL_ttf.h>

#include "jeu.h"
#include "deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>




int main (int argc, char** argv )
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    //**********INITIALISATION DU PLATEAU**********//
    plateau board;
    board = initialisePlateau();

    //**********ECRAN**********//
    SDL_Surface* ecran = NULL;
    ecran = SDL_SetVideoMode(700, 400, 32, SDL_HWSURFACE);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 189, 195, 199));
    SDL_WM_SetCaption("Chess game", NULL);

    //**********CADRILLAGE**********//
    SDL_Surface* tabRectangles[8][8];
    creationCadriage(ecran, tabRectangles);

    //**********SDL_TTF**********//
    TTF_Font *policeT20 = NULL;
    policeT20 = TTF_OpenFont("Roboto-Black.ttf", 20);
    TTF_Font *policeT15 = NULL;
    policeT15 = TTF_OpenFont("Roboto-Black.ttf", 15);


    //**********ASSOCIATION DES VARIABLES AUX IMAGES**********//
    SDL_Surface* surfacePieces[12];

    surfacePieces[0] = SDL_LoadBMP("fou_noir.bmp");
    surfacePieces[1] = SDL_LoadBMP("fou_blanc.bmp");
    surfacePieces[2] = SDL_LoadBMP("dame_noir.bmp");
    surfacePieces[3] = SDL_LoadBMP("dame_blanc.bmp");
    surfacePieces[4] = SDL_LoadBMP("cavalier_noir.bmp");
    surfacePieces[5] = SDL_LoadBMP("cavalier_blanc.bmp");
    surfacePieces[6] = SDL_LoadBMP("roi_noir.bmp");
    surfacePieces[7] = SDL_LoadBMP("roi_blanc.bmp");
    surfacePieces[8] = SDL_LoadBMP("tour_noir.bmp");
    surfacePieces[9] = SDL_LoadBMP("tour_blanc.bmp");
    surfacePieces[10] = SDL_LoadBMP("pion_noir.bmp");
    surfacePieces[11] = SDL_LoadBMP("pion_blanc.bmp");

    SDL_Surface* caseSelectionnee = SDL_LoadBMP("caseSelectionnee.bmp");
    SDL_Surface* caseDestination = SDL_LoadBMP("caseDestination.bmp");
    SDL_SetAlpha(caseSelectionnee, SDL_SRCALPHA, 75);
    SDL_SetAlpha(caseDestination, SDL_SRCALPHA, 75);

    //**********DISPARTION DU VERT**********//
    SDL_SetColorKey(surfacePieces[0], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[0]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[1], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[1]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[2], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[2]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[3], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[3]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[4], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[4]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[5], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[5]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[6], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[6]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[7], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[7]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[8], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[8]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[9], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[9]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[10], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[10]->format, 0,255, 0));
    SDL_SetColorKey(surfacePieces[11], SDL_SRCCOLORKEY, SDL_MapRGB(surfacePieces[11]->format, 0,255, 0));

    placementPieces(board, ecran, surfacePieces);

    //**********VARIABLES**********//
    int i, j, echecEtMat = 0, jouer = 0, continuer, n, testEchec, pieceTue, pieceAenlever=-1;
    SDL_Rect destinationPiece, positionTexte, positionTexteEchec, positionInit;
    SDL_Event event;
    SDL_Surface* texte;
    SDL_Surface* texteEchec;
    SDL_Color couleurTexte = {52, 73, 94};
    SDL_Color couleurtexte2 = {189, 195, 199};
    couleur joueurQuiJoue = BLANC;

    //**********Definition des positions**********//
    positionTexte.x = 410;
    positionTexte.y = 10;

    positionTexteEchec.x = 410;
    positionTexteEchec.y = 50;


    while(!echecEtMat)//Boucle de la partie
    {
        jouer = 0;

        if(joueurQuiJoue == BLANC)//Indication du joueur qui joue avec la variable joueurQuiJoue
        {
            texte = TTF_RenderText_Shaded(policeT20, "Aux blancs de jouer!", couleurTexte, couleurtexte2);
        }
        else
        {
            texte = TTF_RenderText_Shaded(policeT20, "Aux noirs de jouer!", couleurTexte, couleurtexte2);
        }
        SDL_BlitSurface(texte,NULL,ecran,&positionTexte);
        affichePiecesMortes(board, ecran, policeT15, couleurTexte, couleurtexte2);
        SDL_Flip(ecran);


        while(!jouer)//Tant que le joueurQuiJoue n'a pas validé son déplacement ou que le deplacement n'est pas valide
        {
            n = selectionnerPiece( board, ecran, caseSelectionnee, joueurQuiJoue);//Le joueur selectionne une de ses pièces
            destinationPiece = getClicPosition( ecran, tabRectangles[8][8], surfacePieces[12], caseSelectionnee);//Le joueur selectionne une destination (pas là où il y a une de ses pièces)
            destinationPiece.x = (destinationPiece.x/50)*50;
            destinationPiece.y = (destinationPiece.y/50)*50;
            SDL_BlitSurface(caseDestination, NULL, ecran, &destinationPiece);
            SDL_Flip(ecran);

            continuer = 1;
            while(continuer)//Boucle évennement pour valider ou non le déplacement
            {
                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT://Cliquer sur la croix rouge
                        //Free surface
                        SDL_FreeSurface(ecran);
                        for(i=0;i<8;i++)
                        {
                            for(j=0;j<8;j++)
                            {
                                SDL_FreeSurface(tabRectangles[i][j]);
                            }
                        }

                        for(i=0;i<12;i++)
                        {
                            SDL_FreeSurface(surfacePieces[i]);
                        }

                        SDL_FreeSurface(caseSelectionnee);
                        exit(EXIT_SUCCESS);
                        break;

                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE://Annuler (echap): rien ne se passe. On sort de la boucle
                                creationCadriage(ecran, tabRectangles);
                                placementPieces(board, ecran, surfacePieces);
                                continuer = 0;
                                break;

                            case SDLK_SPACE://Valider (espace): le joueur a joué donc jouer = 1 si le deplacement est valide

                                switch(board.tabPiece[n].type)//Appelle des defferentes fonctions déplacement en fonction du type de piece
                                {
                                    case PION:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementPionBlanc(board, destinationPiece,n) == 1)
                                            {
                                                jouer =1;//Si la mouvement est validé alors le joueur a joué => jouer=1
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementPionNoir(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        break;

                                    case TOUR:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementTourBlanche(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementTourNoire(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        break;

                                    case FOU:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementFouBlanc(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementFouNoir(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        break;

                                    case CAVALIER:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementCavalierBlanc(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementCavalierNoir(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        break;

                                    case DAME:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementDameBlanche(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementDameNoire(board, destinationPiece,n) == 1)
                                            {
                                                jouer = 1;
                                            }
                                        }
                                        break;

                                    case ROI:
                                        if(joueurQuiJoue == BLANC)
                                        {
                                            if(DeplacementRoiBlanc(board, destinationPiece,n) == 1)//Le Roi peut se déplacer (pas de pièces amies, pas d'echec sans manger de pièces)
                                            {
                                                positionInit.x = board.tabPiece[7].coordinate.x;//Sauvegarde de la position du roi
                                                positionInit.y = board.tabPiece[7].coordinate.y;
                                                board.tabPiece[7].coordinate.x = destinationPiece.x/50+1;//On place le roi à la destination
                                                board.tabPiece[7].coordinate.x = destinationPiece.x/50+1;
                                                for(i=16; i<32; i++)//On regarde si il existe une pièce ennemie sur la destination
                                                {
                                                    if(board.tabPiece[i].state == ALIVE)
                                                    {
                                                        if((board.tabPiece[i].coordinate.x == destinationPiece.x/50+1) && (board.tabPiece[i].coordinate.y == destinationPiece.y/50+1))
                                                        {
                                                            pieceAenlever = i;
                                                        }
                                                    }
                                                }
                                                if(pieceAenlever != -1)//Il existe un pièce sur la destination
                                                {
                                                    board.tabPiece[pieceAenlever].state = DEAD;//On la met en DEAD pour simuler le roi qui la mange
                                                }

                                                if(DeplacementRoiBlanc(board, destinationPiece,n) == 1)//Si le Roi peux se déplacer alors il n'est plas en echec après avoir manger cette pièce
                                                {
                                                    jouer = 1;
                                                }

                                                board.tabPiece[pieceAenlever].state = ALIVE;//On remet la position du roi à la position initiale et on remet le pièce sur la destination en ALIVE
                                                board.tabPiece[7].coordinate.x = positionInit.x;
                                                board.tabPiece[7].coordinate.y = positionInit.y;
                                            }
                                        }
                                        else
                                        {
                                            if(DeplacementRoiNoir(board, destinationPiece,n) == 1)
                                            {
                                                positionInit.x = board.tabPiece[23].coordinate.x;//Sauvegarde de la position du roi
                                                positionInit.y = board.tabPiece[23].coordinate.y;
                                                board.tabPiece[23].coordinate.x = destinationPiece.x/50+1;//On place le roi à la destination
                                                board.tabPiece[23].coordinate.x = destinationPiece.x/50+1;
                                                for(i=16; i<32; i++)//On regarde si il existe une pièce ennemie sur la destination
                                                {
                                                    if(board.tabPiece[i].state == ALIVE)
                                                    {
                                                        if((board.tabPiece[i].coordinate.x == destinationPiece.x/50+1) && (board.tabPiece[i].coordinate.y == destinationPiece.y/50+1))
                                                        {
                                                            pieceAenlever = i;
                                                        }
                                                    }
                                                }
                                                if(pieceAenlever != -1)//Il existe un pièce sur la destination
                                                {
                                                    board.tabPiece[pieceAenlever].state = DEAD;//On la met en DEAD pour simuler le roi qui la mange
                                                }

                                                if(DeplacementRoiBlanc(board, destinationPiece,n) == 1)//Si le Roi peux se déplacer alors il n'est plas en echec après avoir manger cette pièce
                                                {
                                                    jouer = 1;
                                                }

                                                board.tabPiece[pieceAenlever].state = ALIVE;//On remet la position du roi à la position initiale et on remet le pièce sur la destination en ALIVE
                                                board.tabPiece[23].coordinate.x = positionInit.x;
                                                board.tabPiece[23].coordinate.y = positionInit.y;
                                            }
                                        }
                                        break;

                                    default: break;
                                }
                                break;

                            default: break;
                        }
                        break;
                }
                if (jouer == 1)// Si le Joueur a joué
                {
                    continuer = 0;//On sort de la boucle évenements

                    testEchec = 0;
                    pieceTue = -1;
                    if(echecBlanc(board, 7) != -1 || echecNoir(board, 23) != -1)//Si l'un des roi est en echec on met la variable testEchec à 1
                    {
                        testEchec = 1;
                    }

                    positionInit.x = board.tabPiece[n].coordinate.x;//On sauvegarde la position de la pièce
                    positionInit.y = board.tabPiece[n].coordinate.y;

                    board.tabPiece[n].coordinate.x = destinationPiece.x/50+1;//Modification des coordonnées de la pièce
                    board.tabPiece[n].coordinate.y = destinationPiece.y/50+1;

                    for(i=0; i<32; i++)//Verifaction par savoir si une pièces est mangé (DEAD)
                    {
                        if(i != n)
                        {
                            if(board.tabPiece[i].state == ALIVE)
                            {
                                if((board.tabPiece[i].coordinate.x == board.tabPiece[n].coordinate.x) && (board.tabPiece[i].coordinate.y == board.tabPiece[n].coordinate.y))
                                {
                                    board.tabPiece[i].state = DEAD;
                                }
                            }
                        }
                    }

                    if((echecBlanc(board, 7) != -1 || echecNoir(board, 23) != -1) && (testEchec == 1))//Si on est toujours en echec
                    {
                        board.tabPiece[n].coordinate.x = positionInit.x;//On remet la pièce à ça place
                        board.tabPiece[n].coordinate.y = positionInit.y;
                        board.tabPiece[pieceTue].state = ALIVE;//On la met ALIVE
                        creationCadriage(ecran, tabRectangles);
                        placementPieces(board, ecran, surfacePieces);
                        SDL_Flip(ecran);
                    }
                    else//Sinon on réalise les test d'echecs
                    {
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 189, 195, 199));
                        creationCadriage(ecran, tabRectangles);
                        placementPieces(board, ecran, surfacePieces);

                        if(joueurQuiJoue == NOIR)
                        {
                            if(echecEtMatBlanc(board) == 1)//Test echec et mat Blanc
                            {
                                texteEchec = TTF_RenderText_Shaded(policeT20, "Vous êtes en echec et mat! Perdu", couleurTexte, couleurtexte2);
                                SDL_BlitSurface(texteEchec,NULL,ecran,&positionTexteEchec);
                                SDL_Flip(ecran);
                                echecEtMat = 1;
                            }
                            else
                            {
                                if(echecBlanc(board, 7) != -1)//Test pour savoir si le roi blanc est en echec
                                {
                                    texteEchec = TTF_RenderText_Shaded(policeT20, "Vous êtes en echec!", couleurTexte, couleurtexte2);
                                    SDL_BlitSurface(texteEchec,NULL,ecran,&positionTexteEchec);
                                    SDL_Flip(ecran);
                                }
                            }
                        }
                        if(joueurQuiJoue == BLANC)//Test echec et mat Noir
                        {
                            if(echecEtMatNoir(board) == 1)
                            {
                                texteEchec = TTF_RenderText_Shaded(policeT20, "Vous êtes en echec et mat! Perdu", couleurTexte, couleurtexte2);
                                SDL_BlitSurface(texteEchec,NULL,ecran,&positionTexteEchec);
                                SDL_Flip(ecran);
                                echecEtMat = 1;
                            }
                            else
                            {
                                if(echecNoir(board, 23) != -1)//Test pour savoir si le roi noir est en echec
                                {
                                    texteEchec = TTF_RenderText_Shaded(policeT20, "Vous êtes en echec!", couleurTexte, couleurtexte2);
                                    SDL_BlitSurface(texteEchec,NULL,ecran,&positionTexteEchec);
                                    SDL_Flip(ecran);
                                }
                            }
                        }

                        if(joueurQuiJoue == BLANC)//On change de joueur qui joue
                        {
                            joueurQuiJoue = NOIR;
                        }
                        else
                        {
                            joueurQuiJoue = BLANC;
                        }
                    }
                }
            }
        }
    }
    pause();



    //**********FREE SURFACES**********//
    SDL_FreeSurface(ecran);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            SDL_FreeSurface(tabRectangles[i][j]);
        }
    }

    for(i=0;i<12;i++)
    {
        SDL_FreeSurface(surfacePieces[i]);
    }

    SDL_FreeSurface(caseSelectionnee);


    TTF_CloseFont(policeT20);
    TTF_CloseFont(policeT15);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
