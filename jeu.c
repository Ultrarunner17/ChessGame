#include "jeu.h"


void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

plateau initialisePlateau()
{
    //**********VARIABLES**********//
    int i;
    plateau board;
    board.tabPiece = malloc(sizeof(piece)*32);

    //**********CORPS**********//
    for(i=0;i<32;i++)
    {
        board.tabPiece[i].state = ALIVE;
        if(i<16) //Les 16 premiers sont BLANCS
        {
            board.tabPiece[i].color = BLANC;
            if(i>=8) //Les 8 derniers (8-16) sont des PIONS
            {
                board.tabPiece[i].type = PION;
                board.tabPiece[i].coordinate.x = i-7;
                board.tabPiece[i].coordinate.y = 2;
            }
        }
        else //Les 16 derniers sont NOIRS
        {
            board.tabPiece[i].color = NOIR;
            if(i>=24) //Les 8 derniers (24-32) sont des PIONS
            {
                board.tabPiece[i].type = PION;
                board.tabPiece[i].coordinate.x = i-23;
                board.tabPiece[i].coordinate.y = 7;
            }
        }
        switch (i)
        {
            case 0:
                board.tabPiece[i].type = TOUR;
                board.tabPiece[i].coordinate.x = 1;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 1:
                board.tabPiece[i].type = TOUR;
                board.tabPiece[i].coordinate.x = 8;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 2:
                board.tabPiece[i].type = CAVALIER;
                board.tabPiece[i].coordinate.x = 2;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 3:
                board.tabPiece[i].type = CAVALIER;
                board.tabPiece[i].coordinate.x = 7;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 4:
                board.tabPiece[i].type = FOU;
                board.tabPiece[i].coordinate.x = 3;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 5:
                board.tabPiece[i].type = FOU;
                board.tabPiece[i].coordinate.x = 6;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 6:
                board.tabPiece[i].type = DAME;
                board.tabPiece[i].coordinate.x = 4;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 7:
                board.tabPiece[i].type = ROI;
                board.tabPiece[i].coordinate.x = 5;
                board.tabPiece[i].coordinate.y = 1;
                break;
            case 16:
                board.tabPiece[i].type = TOUR;
                board.tabPiece[i].coordinate.x = 1;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 17:
                board.tabPiece[i].type = TOUR;
                board.tabPiece[i].coordinate.x = 8;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 18:
                board.tabPiece[i].type = CAVALIER;
                board.tabPiece[i].coordinate.x = 2;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 19:
                board.tabPiece[i].type = CAVALIER;
                board.tabPiece[i].coordinate.x = 7;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 20:
                board.tabPiece[i].type = FOU;
                board.tabPiece[i].coordinate.x = 3;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 21:
                board.tabPiece[i].type = FOU;
                board.tabPiece[i].coordinate.x = 6;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 22:
                board.tabPiece[i].type = DAME;
                board.tabPiece[i].coordinate.x = 4;
                board.tabPiece[i].coordinate.y = 8;
                break;
            case 23:
                board.tabPiece[i].type = ROI;
                board.tabPiece[i].coordinate.x = 5;
                board.tabPiece[i].coordinate.y = 8;
                break;
            default: break;
        }
    }
    return board;
}

void creationCadriage(SDL_Surface* ecran, SDL_Surface* tabRectangles[8][8])
{
    int i,j;

    SDL_Rect position;


    //**********CREATION DU CADRILLAGE**********//
    for(i=0;i<8;i=i+2)
    {
        for(j=1;j<8;j=j+2)
        {
            tabRectangles[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);

            SDL_FillRect(tabRectangles[i][j], NULL, SDL_MapRGB(ecran->format, 255,255, 255));

            position.x = i * 50;
            position.y = j * 50;

            SDL_BlitSurface(tabRectangles[i][j], NULL, ecran, &position);
        }
    }

      for(i=1;i<8;i=i+2)
    {
        for(j=0;j<8;j=j+2)
        {
            tabRectangles[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);

            SDL_FillRect(tabRectangles[i][j], NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

            position.x = i * 50;
            position.y = j * 50;

            SDL_BlitSurface(tabRectangles[i][j], NULL, ecran, &position);
        }
    }

    for(i=0;i<8;i=i+2)
    {
        for(j=0;j<8;j=j+2)
        {
            tabRectangles[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);

            SDL_FillRect(tabRectangles[i][j], NULL, SDL_MapRGB(ecran->format,40, 40, 40));

            position.x = i * 50;
            position.y = j * 50;

            SDL_BlitSurface(tabRectangles[i][j], NULL, ecran, &position);
        }
    }

    for(i=1;i<8;i=i+2)
    {
        for(j=1;j<8;j=j+2)
        {
            tabRectangles[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);

            SDL_FillRect(tabRectangles[i][j], NULL, SDL_MapRGB(ecran->format, 40, 40, 40));

            position.x = i * 50;
            position.y = j * 50;

            SDL_BlitSurface(tabRectangles[i][j], NULL, ecran, &position);
        }
    }

    SDL_Flip(ecran);
}

void placementPieces(plateau board, SDL_Surface* ecran,SDL_Surface* surfacePieces[])
{

    int i;
    SDL_Rect position;



    //**********PLACEMENT DES PIECES**********//
    for(i=0;i<32;i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            position.x = board.tabPiece[i].coordinate.x * 50 -50;
            position.y = board.tabPiece[i].coordinate.y * 50 -50;
            if(board.tabPiece[i].type == PION)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[11], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[10], NULL, ecran, &position);
                }
            }
            if(board.tabPiece[i].type == TOUR)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[9], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[8], NULL, ecran, &position);
                }
            }
            if(board.tabPiece[i].type == FOU)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[1], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[0], NULL, ecran, &position);
                }
            }
            if(board.tabPiece[i].type == CAVALIER)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[5], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[4], NULL, ecran, &position);
                }
            }
            if(board.tabPiece[i].type == DAME)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[3], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[2], NULL, ecran, &position);
                }
            }
            if(board.tabPiece[i].type == ROI)
            {
                if(board.tabPiece[i].color == BLANC)
                {
                    SDL_BlitSurface(surfacePieces[7], NULL, ecran, &position);
                }
                else
                {
                    SDL_BlitSurface(surfacePieces[6], NULL, ecran, &position);
                }
            }
        }
    }

    SDL_Flip(ecran);
}

SDL_Rect getClicPosition()
{
    int continuer = 1;
    SDL_Rect position;
    SDL_Event event;

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.x < 400)
                {
                    position.x = event.button.x;
                    position.y = event.button.y;
                    continuer = 0;
                }
                break;

            default: break;
        }
    }
    return position;
}

int selectionnerPiece(plateau board,SDL_Surface* ecran, SDL_Surface* caseSelectionnee, couleur joueurQuiJoue)
{
    SDL_Rect positionClic;
    positionClic.x = -1;
    positionClic.y = -1;
    SDL_Rect c;
    int i, n, continuer = 1;

    while(continuer)
    {
        positionClic = getClicPosition();
        for(i=0;i<32;i++)
        {
            if(board.tabPiece[i].state == ALIVE)
            {
                if((((positionClic.x+50)/50) == board.tabPiece[i].coordinate.x) && (((positionClic.y+50)/50) == board.tabPiece[i].coordinate.y) && ( board.tabPiece[i].color == joueurQuiJoue))
                {
                    continuer = 0;
                    n=i;
                }
            }
        }
    }

    c.x = (positionClic.x/50)*50;
    c.y = (positionClic.y/50)*50;

    SDL_BlitSurface(caseSelectionnee, NULL, ecran, &c);
    SDL_Flip(ecran);

    return n;
}

void affichePiecesMortes(plateau board, SDL_Surface* ecran, TTF_Font *policeT15, SDL_Color couleurTexte, SDL_Color couleurtexte2)
{
    int i, nbFB = 0, nbTB = 0, nbPB = 0, nbCB = 0, nbDB = 0, nbFN = 0, nbTN = 0, nbPN = 0, nbCN = 0, nbDN = 0;
    for(i=0; i<32; i++)
    {
        if(board.tabPiece[i].state == DEAD)
        {
            if(board.tabPiece[i].color == BLANC)
            {
                switch(board.tabPiece[i].type)
                {
                    case PION:
                        nbPB++;
                        break;
                    case CAVALIER:
                        nbCB++;
                        break;
                    case FOU:
                        nbFB++;
                        break;
                    case TOUR:
                        nbTB++;
                        break;
                    case DAME:
                        nbDB++;
                        break;
                    default: break;
                }
            }
            if(board.tabPiece[i].color == NOIR)
            {
                switch(board.tabPiece[i].type)
                {
                    case PION:
                        nbPN++;
                        break;
                    case CAVALIER:
                        nbCN++;
                        break;
                    case FOU:
                        nbFN++;
                        break;
                    case TOUR:
                        nbTN++;
                        break;
                    case DAME:
                        nbDN++;
                        break;
                    default: break;
                }
            }
        }
    }
    SDL_Surface *texte;
    SDL_Rect position;

    texte = TTF_RenderText_Shaded(policeT15, "Pièces mortes :", couleurTexte, couleurtexte2);
    position.x = 410;
    position.y = 130;
    SDL_BlitSurface(texte,NULL,ecran,&position);
    char string[20];

    //PION
    sprintf(string, "Pion blanc: %d", nbPB);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440;
    position.y = 170;
    SDL_BlitSurface(texte, NULL, ecran, &position);

    sprintf(string, "Pion noir: %d", nbPN);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440 + 130;
    position.y = 170;
    SDL_BlitSurface(texte, NULL, ecran, &position);

    //CAVALIER
    sprintf(string, "Cavalier blanc: %d", nbCB);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440;
    position.y = 190;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    sprintf(string, "Cavalier noir: %d", nbCN);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440 + 130;
    position.y = 190;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    //FOU
    sprintf(string, "Fou blanc: %d", nbFB);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440;
    position.y = 210;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    sprintf(string, "Fou noir: %d", nbFN);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440 + 130;
    position.y = 210;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    //TOUR
    sprintf(string, "Tour blanc: %d", nbTB);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440;
    position.y = 230;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    sprintf(string, "Tour noir: %d", nbTN);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440 + 130;
    position.y = 230;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    //DAME
    sprintf(string, "Dame blanc: %d", nbDB);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440;
    position.y = 250;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    sprintf(string, "Dame noir: %d", nbDN);
    texte = TTF_RenderText_Shaded(policeT15, string, couleurTexte, couleurtexte2);
    position.x = 440 + 130;
    position.y = 250;
    SDL_BlitSurface(texte,NULL,ecran,&position);

    SDL_Flip(ecran);

}



int echecBlanc(plateau board, int n)
{
    int i, testEchec = -1;
    SDL_Rect position;
    position.x = (board.tabPiece[n].coordinate.x * 50 - 50);
    position.y = (board.tabPiece[n].coordinate.y * 50 - 50);

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            switch(board.tabPiece[i].type)
            {
                case PION:
                    if(DeplacementPionNoir(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case FOU:
                    if(DeplacementFouNoir(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case CAVALIER:
                    if(DeplacementCavalierNoir(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case DAME:
                    if(DeplacementDameNoire(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case ROI:
                    if(DeplacementRoiNoir(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case TOUR:
                    if(DeplacementTourNoire(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                default: break;
            }
        }
    }
    return testEchec;
}

int echecNoir(plateau board, int n)
{
    int i, testEchec = -1;
    SDL_Rect position;
    position.x = (board.tabPiece[n].coordinate.x * 50 - 50);
    position.y = (board.tabPiece[n].coordinate.y * 50 - 50);

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            switch(board.tabPiece[i].type)
            {
                case PION:
                    if(DeplacementPionBlanc(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case FOU:
                    if(DeplacementFouBlanc(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case CAVALIER:
                    if(DeplacementCavalierBlanc(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case DAME:
                    if(DeplacementDameBlanche(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case ROI:
                    if(DeplacementRoiBlanc(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                case TOUR:
                    if(DeplacementTourBlanche(board,position,i))
                    {
                        testEchec = i;
                    }
                    break;

                default: break;
            }
        }
    }
    return testEchec;
}



int echecEtMatBlanc (plateau board)
{
    int testEchec = 0, cpt = 0, pieceMiseEchec;
    SDL_Rect destinationP, positionInit;

    positionInit.x = board.tabPiece[7].coordinate.x;
    positionInit.y = board.tabPiece[7].coordinate.y;

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50);
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)+50;
    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y + 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)+50;

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x + 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y + 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50);

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x + 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y;
            cpt ++;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)-50;

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x + 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y - 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50);
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)-50;

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y - 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)-50;

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x - 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y - 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50);

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x - 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }


    destinationP.x = (board.tabPiece[7].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[7].coordinate.y * 50 - 50)+50;

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiBlanc(board, destinationP, 7))
        {
            cpt ++;
            board.tabPiece[7].coordinate.x = board.tabPiece[7].coordinate.x - 1;
            board.tabPiece[7].coordinate.y = board.tabPiece[7].coordinate.y + 1;
            pieceMiseEchec = echecBlanc(board, 7);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    board.tabPiece[7].coordinate.x = positionInit.x;
    board.tabPiece[7].coordinate.y = positionInit.y;

    if(echecBlanc(board, 7) != -1)
    {
        if(echecNoir(board, echecBlanc(board, 7)) == -1)
        {
            if (testEchec == cpt)
            {
                return 1;
            }
        }
    }
    return 0;
}

int echecEtMatNoir (plateau board)
{
    int testEchec = 0, cpt = 0, pieceMiseEchec;
    SDL_Rect destinationP, positionInit;

    positionInit.x = board.tabPiece[23].coordinate.x;
    positionInit.y = board.tabPiece[23].coordinate.y;

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50);
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)+50;
    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y + 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)+50;

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x + 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y + 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50);

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x + 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y;
            cpt ++;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)+50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)-50;

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x + 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y - 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50);
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)-50;

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y - 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)-50;

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x - 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y - 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50);

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x - 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    destinationP.x = (board.tabPiece[23].coordinate.x * 50 - 50)-50;
    destinationP.y = (board.tabPiece[23].coordinate.y * 50 - 50)+50;

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(destinationP.x < 1 || destinationP.x > 8 || destinationP.y < 1 || destinationP.y > 8)
    {
        if (DeplacementRoiNoir(board, destinationP, 23))
        {
            cpt ++;
            board.tabPiece[23].coordinate.x = board.tabPiece[23].coordinate.x - 1;
            board.tabPiece[23].coordinate.y = board.tabPiece[23].coordinate.y + 1;
            pieceMiseEchec = echecNoir(board, 23);
            if(pieceMiseEchec != -1)
            {
                testEchec ++;
            }
        }
    }

    board.tabPiece[23].coordinate.x = positionInit.x;
    board.tabPiece[23].coordinate.y = positionInit.y;

    if(echecNoir(board, 23) != -1)
    {
        if(echecBlanc(board, echecNoir(board, 7)) == -1)
        {
            if (testEchec == cpt)
            {
                return 1;
            }
        }
    }
    return 0;
}


