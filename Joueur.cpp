#include "Joueur.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

Joueur::Joueur() : row(10, 0), checkerBoard(10, row)
{

}

Joueur::~Joueur()
{
    //dtor
}

std::vector<std::vector<int> > Joueur::getcheckerBoard()
{
    return checkerBoard;
}

int Joueur::placeBateauH(sf::Vector2i coord, bool verticale, int boatLength )
{ // placement bateau humain
	int x(coord.x - 50);
	int y(coord.y - 50);
	int tileSize(30);
	int xTail, yTail, pos; //back coord of the boat

	if(verticale)
	{
        xTail = x + tileSize*(boatLength - 1);
        pos = 3;
	}
	else
	{
        yTail = y + tileSize*(boatLength - 1);
        pos = 2;
	}
	if (!(x >= 0 && y >= 0 && x < 300 && y < 300))
	{
        return -1; //click outside of the checkerBoard
	}
	if (!(xTail >= 0 && yTail >= 0 && xTail < 300 && yTail < 300))
	{
        return 0; // boat is too big, he exceed the size of checkerBoard
	}

	/*test if boat is in the checkerboard*/

	if (x >= 0 && y >= 0 && x < 300 && y < 300){
		x = x / 30;
		y = y / 30;
		for( int i = 0; i<boatLength; i++){
			this->checkerBoard[x][y] = pos;
			if(verticale)x++;
			else y++;
		}
	}
	return 1; // No problems
}

void Joueur::printCheckerboard()
{
    std::cout << std::endl;
    for (int i(0); i<10; i++)
    {
        for (int j(0); j<10; j++)
        {
            std::cout << " pos(" << i << ":" << j << ") "<< checkerBoard[i][j] << std::endl;
        }

    }
}

/*Board Joueur::placeBateauIA(){ // placement bateau de l'ia



}
*/
