#include "deplacement.h"


int DeplacementTourBlanche (plateau board, SDL_Rect destination, int n)
{
    int i, j, able = 1, testPieceSurPosition = 0, difference;

    SDL_Rect depart = board.tabPiece[n].coordinate;
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if(depart.x != destination.x && depart.y != destination.y)
    {
        able = 0;
    }

    if(depart.x == destination.x) //Deplacement vertical
    {
        if(depart.y < destination.y) //Deplacement vers le bas
        {
            difference = destination.y - depart.y;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.x == depart.x)
                        {
                            if(board.tabPiece[i].coordinate.y == depart.y + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
        if(depart.y > destination.y) //Deplacement vers le haut
        {
            difference = depart.y - destination.y;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.x == depart.x)
                        {
                            if(board.tabPiece[i].coordinate.y == destination.y + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if(depart.y == destination.y) //Deplacement horizontal
    {

        if(depart.x < destination.x) //Deplacement vers la droite
        {
            difference = destination.x - depart.x;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y)
                        {
                            if(board.tabPiece[i].coordinate.x == depart.x + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
        if(depart.x > destination.x) //Deplacement vers la gauche
        {
            difference = depart.x - destination.x;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y)
                        {
                            if(board.tabPiece[i].coordinate.x == destination.x + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i=0; i<16; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    return able;
}

int DeplacementRoiBlanc(plateau board, SDL_Rect destination, int n)
{
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    SDL_Rect depart = board.tabPiece[n].coordinate;
    int i, j, testPieceSurPosition = 0, able = 1;
    int pieceAenlever = -1;

    int differenceX, differenceY;
    differenceX = fabs(depart.x - destination.x);
    differenceY = fabs(depart.y - destination.y);

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }

    if(testPieceSurPosition == 0)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;
        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if(differenceX > 1 )
    {
        able = 0;
    }

    if(differenceY > 1 )
    {
        able = 0;
    }

    for (i=0; i<16; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }

    return able;
}


int DeplacementCavalierBlanc(plateau board, SDL_Rect destination, int n)
{
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    SDL_Rect depart = board.tabPiece[n].coordinate;
    int i, able = 1, testPieceSurPosition = 0;

    int differenceX, differenceY;
    differenceX = fabs(depart.x - destination.x);
    differenceY = fabs(depart.y - destination.y);

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if((differenceX*differenceX + differenceY*differenceY) != 5)
    {
        able = 0;
    }

    for (i=0; i<16; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    return able;
}

int DeplacementFouBlanc (plateau board, SDL_Rect destination, int n)
{

    SDL_Rect depart = board.tabPiece[n].coordinate;
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    int i,j,able = 1, difference, testPieceSurPosition = 0;

    if((destination.x - depart.x) != (destination.y - depart.y))
    {
        able = 0;
    }
    if ((destination.x - depart.x) == (-(destination.y - depart.y)))
    {
        able = 1;
    }

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    for (i=0; i<16; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    if(depart.y < destination.y && depart.x < destination.x) //Deplacement vers le bas/droite
    {
        difference = destination.y - depart.y;
        for(j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if(board.tabPiece[i].coordinate.x == depart.x+j)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y + j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y < destination.y && depart.x > destination.x) //Deplacement vers le bas/gauche
    {
        difference = destination.y - depart.y;
        for (j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x-j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y + j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y > destination.y && depart.x < destination.x)//Deplacement vers le haut/droite
    {
        difference = depart.y - destination.y;
        for (j=1; j<difference; j++)
        {
            for (i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x+j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y-j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y > destination.y && depart.x > destination.x)//Deplacement vers le haut/gauche
    {
        difference = depart.y - destination.y;
        for (j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if (board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x - j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y - j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    return able;
}


int DeplacementDameBlanche(plateau board, SDL_Rect destination, int n)
{
    int able = 0, i,  testPieceSurPosition = 0;
    SDL_Rect depart = board.tabPiece[n].coordinate;

    if(DeplacementTourBlanche(board,destination,n) == 1 || DeplacementFouBlanc(board,destination,n) == 1)
    {
        able = 1;
    }

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    return able;
}

int DeplacementTourNoire (plateau board, SDL_Rect destination, int n)
{
    int i, j, able = 1, testPieceSurPosition = 0;
    int difference;

    SDL_Rect depart = board.tabPiece[n].coordinate;
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;


    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if(depart.x != destination.x && depart.y != destination.y)
    {
        able = 0;
    }

    if(depart.x == destination.x) //Deplacement vertical
    {
        if(depart.y < destination.y) //Deplacement vers le bas
        {
            difference = destination.y - depart.y;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.x == depart.x)
                        {
                            if(board.tabPiece[i].coordinate.y == depart.y + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
        if(depart.y > destination.y) //Deplacement vers le haut
        {
            difference = depart.y - destination.y;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.x == depart.x)
                        {
                            if(board.tabPiece[i].coordinate.y == destination.y + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if(depart.y == destination.y) //Deplacement horizontal
    {

        if(depart.x < destination.x) //Deplacement vers la droite
        {
            difference = destination.x - depart.x;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y)
                        {
                            if(board.tabPiece[i].coordinate.x == depart.x + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
        if(depart.x > destination.x) //Deplacement vers la gauche
        {
            difference = depart.x - destination.x;
            for(j=1; j<difference; j++)
            {
                for(i=0; i<32; i++)
                {
                    if(board.tabPiece[i].state == ALIVE)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y)
                        {
                            if(board.tabPiece[i].coordinate.x == destination.x + j)
                            {
                                able = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i=16; i<32; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    return able;
}

int DeplacementRoiNoir(plateau board, SDL_Rect destination, int n)
{
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    SDL_Rect depart = board.tabPiece[n].coordinate;
    int i, able = 1, testPieceSurPosition = 0;

    int differenceX, differenceY;
    differenceX = fabs(depart.x - destination.x);
    differenceY = fabs(depart.y - destination.y);

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[23].coordinate.x = destination.x;
        board.tabPiece[23].coordinate.y = destination.y;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[23].coordinate.x = depart.x;
        board.tabPiece[23].coordinate.y = depart.y;
    }

    if(differenceX > 1 )
    {
        able = 0;
    }

    if(differenceY > 1 )
    {
        able = 0;
    }

    for (i=16; i<32; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }

    return able;
}

int DeplacementCavalierNoir(plateau board, SDL_Rect destination, int n)
{
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    SDL_Rect depart = board.tabPiece[n].coordinate;
    int i, able = 1, testPieceSurPosition = 0;

    int differenceX, differenceY;
    differenceX = fabs(depart.x - destination.x);
    differenceY = fabs(depart.y - destination.y);

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if((differenceX*differenceX + differenceY*differenceY) != 5)
    {
        able = 0;
    }

    for (i=16; i<32; i++) //Ne pas se déplacer sur une pièce blanche
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    return able;
}

int DeplacementPionBlanc (plateau board, SDL_Rect PositionClicDestination, int n)
{
    int able = 1, testPieceSurPosition = 0;
    int i, j;
    SDL_Rect depart = board.tabPiece[n].coordinate;

    //Déplacement d'une case
    if (((PositionClicDestination.y/50+1)-board.tabPiece[n].coordinate.y) > 1)
    {
        able = 0;
    }
    //Déplacement de deux cases au début
    if (board.tabPiece[n].coordinate.y == 2 && ((PositionClicDestination.y/50+1) -board.tabPiece[n].coordinate.y)==2)
    {
        able = 1;
    }

    //Supprimer les diagonales
    if (board.tabPiece[n].coordinate.x != PositionClicDestination.x/50+1 && board.tabPiece[n].coordinate.y != PositionClicDestination.y/50+1)
    {
        able = 0;
    }
    //Supprimer la même case
    if (board.tabPiece[n].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[n].coordinate.y == PositionClicDestination.y/50+1)
    {
        able = 0;
    }
    //Supprimer le déplacement suivant x
    if (board.tabPiece[n].coordinate.x != PositionClicDestination.x/50+1)
    {
        able =0;
    }

    //Supprimer déplacement sur une case où il y a une pièce ALIVE
    for (i=0; i<32; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[i].coordinate.y == PositionClicDestination.y/50+1)
            {
                able = 0;
            }
        }
    }
    //Pas de retour en arrière
    if (PositionClicDestination.y/50+1 < board.tabPiece[n].coordinate.y)
    {
        able = 0;
    }
    //Ne pas sauter une pièce lors du saut double
    int difference = (PositionClicDestination.y/50+1) - board.tabPiece[n].coordinate.y;
    for(j=1; j<difference; j++)
    {
        for(i=0; i<32; i++)
        {
            if(board.tabPiece[i].state == ALIVE)
            {
                if(board.tabPiece[i].coordinate.x == board.tabPiece[n].coordinate.x)
                {
                    if(board.tabPiece[i].coordinate.y == board.tabPiece[n].coordinate.y + j)
                    {
                        able = 0;
                    }
                }
            }
        }
    }

    //Manger en diagonal sur pièce noire ALIVE
    for (i=0; i<32; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].color == NOIR && board.tabPiece[i].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[i].coordinate.y == PositionClicDestination.y/50+1)
            {
                if ((PositionClicDestination.x/50+1 == board.tabPiece[n].coordinate.x+1  && PositionClicDestination.y/50+1 == board.tabPiece[n].coordinate.y+1) || (PositionClicDestination.x/50+1 == board.tabPiece[n].coordinate.x-1  && PositionClicDestination.y/50+1 == board.tabPiece[n].coordinate.y+1))
                {
                    able =1;
                }
            }
        }
    }

    for(i=0; i<16; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if((board.tabPiece[i].coordinate.x == (PositionClicDestination.x/50+1)) && (board.tabPiece[i].coordinate.y == (PositionClicDestination.y/50+1)))
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = PositionClicDestination.x/50+1;
        board.tabPiece[n].coordinate.y = PositionClicDestination.y/50+1;

        if(echecBlanc(board, 7) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    return able;
}

int DeplacementPionNoir (plateau board, SDL_Rect PositionClicDestination, int n)
{
    int i, j, able = 1, testPieceSurPosition=0;
    SDL_Rect depart = board.tabPiece[n].coordinate;

    //Déplacement d'une case
    if (((PositionClicDestination.y/50+1) - board.tabPiece[n].coordinate.y) != -1)
    {
        able = 0;
    }
    //Déplacement de deux cases au début
    if (board.tabPiece[n].coordinate.y == 7 && (((PositionClicDestination.y/50+1) - board.tabPiece[n].coordinate.y)==-2))
    {
        able = 1;
    }

    //Supprimer les diagonales
    if (board.tabPiece[n].coordinate.x != PositionClicDestination.x/50+1 && board.tabPiece[n].coordinate.y != PositionClicDestination.y/50+1)
    {
        able = 0;
    }
    //Suprimer la même case
    if (board.tabPiece[n].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[n].coordinate.y == PositionClicDestination.y/50+1)
    {
        able = 0;
    }
    //Supprimer le déplacement suivant x
    if (board.tabPiece[n].coordinate.x != PositionClicDestination.x/50+1)
    {
        able =0;
    }
    //Supprimer déplacement sur une case où il y a une pièce ALIVE
    for (i=0; i<32; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[i].coordinate.y == PositionClicDestination.y/50+1)
            {
                able = 0;
            }
        }
    }
    //Pas de retour en arrière
    if (board.tabPiece[n].coordinate.y < PositionClicDestination.y/50+1)
    {
        able = 0;
    }
    //Ne pas sauter une pièce lors du double saut
    int difference = board.tabPiece[n].coordinate.y - (PositionClicDestination.y/50+1);
    for(j=1; j<difference; j++)
    {
        for(i=0; i<32; i++)
        {
            if(board.tabPiece[i].state == ALIVE)
            {
                if(board.tabPiece[i].coordinate.x == board.tabPiece[n].coordinate.x)
                {
                    if(board.tabPiece[i].coordinate.y == (PositionClicDestination.y/50+1) + j)
                    {
                        able = 0;
                    }
                }
            }
        }
    }
    //Manger en diagonal sur pièce blanche ALIVE
    for (i=0; i<32; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].color == BLANC && board.tabPiece[i].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[i].coordinate.y == PositionClicDestination.y/50+1)
            {
                if ((PositionClicDestination.x/50+1 == board.tabPiece[n].coordinate.x+1  && PositionClicDestination.y/50+1 == board.tabPiece[n].coordinate.y-1) || (PositionClicDestination.x/50+1 == board.tabPiece[n].coordinate.x-1  && PositionClicDestination.y/50+1 == board.tabPiece[n].coordinate.y-1))
                {
                    able =1;
                }
            }
        }
    }

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == PositionClicDestination.x/50+1 && board.tabPiece[i].coordinate.y == PositionClicDestination.y/50+1)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = PositionClicDestination.x/50+1;
        board.tabPiece[n].coordinate.y = PositionClicDestination.y/50+1;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    return able;
}


int DeplacementFouNoir(plateau board, SDL_Rect destination, int n)
{

    SDL_Rect depart = board.tabPiece[n].coordinate;
    destination.x = destination.x/50+1;
    destination.y = destination.y/50+1;
    int i,j,able = 1,difference, testPieceSurPosition=0;

    if((destination.x - depart.x) != (destination.y - depart.y))
    {
        able = 0;
    }
    if ((destination.x - depart.x) == (-(destination.y - depart.y)))
    {
        able = 1;
    }

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    for (i=16; i<32; i++)
    {
        if (board.tabPiece[i].state == ALIVE)
        {
            if (board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                able = 0;
            }
        }
    }
    if(depart.y < destination.y && depart.x < destination.x) //Deplacement vers le bas/droite
    {
        difference = destination.y - depart.y;
        for(j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if(board.tabPiece[i].coordinate.x == depart.x+j)
                    {
                        if(board.tabPiece[i].coordinate.y == depart.y + j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y < destination.y && depart.x > destination.x) //Deplacement vers le bas/gauche
    {
        difference = destination.y - depart.y;
        for (j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x-j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y + j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y > destination.y && depart.x < destination.x)//Deplacement vers le haut/droite
    {
        difference = depart.y - destination.y;
        for (j=1; j<difference; j++)
        {
            for (i=0; i<32; i++)
            {
                if(board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x+j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y-j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    if (depart.y > destination.y && depart.x > destination.x)//Deplacement vers le haut/gauche
    {
        difference = depart.y - destination.y;
        for (j=1; j<difference; j++)
        {
            for(i=0; i<32; i++)
            {
                if (board.tabPiece[i].state == ALIVE)
                {
                    if (board.tabPiece[i].coordinate.x == depart.x - j)
                    {
                        if (board.tabPiece[i].coordinate.y == depart.y - j)
                        {
                            able = 0;
                        }
                    }
                }
            }
        }
    }
    return able;
}


int DeplacementDameNoire(plateau board, SDL_Rect destination, int n)
{
    int able = 0, i, testPieceSurPosition = 0;
    SDL_Rect depart = board.tabPiece[n].coordinate;

    for(i=16; i<32; i++)
    {
        if(board.tabPiece[i].state == ALIVE)
        {
            if(board.tabPiece[i].coordinate.x == destination.x && board.tabPiece[i].coordinate.y == destination.y)
            {
                testPieceSurPosition = 1;
            }
        }
    }
    if(!testPieceSurPosition)
    {
        board.tabPiece[n].coordinate.x = destination.x;
        board.tabPiece[n].coordinate.y = destination.y;

        if(echecBlanc(board, 23) != -1)
        {
            able = 0;
        }
        board.tabPiece[n].coordinate.x = depart.x;
        board.tabPiece[n].coordinate.y = depart.y;
    }

    if(DeplacementTourNoire(board,destination,n) == 1 || DeplacementFouNoir(board,destination,n) == 1)
    {
        able = 1;
    }
    return able;
}


















