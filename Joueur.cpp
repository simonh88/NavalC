#include "Joueur.h"

Joueur::Joueur()
{
    
}

Joueur::~Joueur()
{
    //dtor
}




Board Joueur::placeBateauH(sf::Vector2i coord, bool verticale, int longueur ){ // placement bateau humain
	int x = coord.x;
	int y = coord.y;
	int pos = 2;
	if(verticale) pos = 3;
	
	if (x >= 50 && y >= 50 && x <= 350 && y <= 350){
		x = (x - 50)/29;
		y = (y - 50)/29: 
		if 
		for( int i = 0; i<longueur; i++){
			this.board[x][y] = pos;
			if(verticale)y++;
			else x++;
			
		}
		
	}
}

Board Joueur::placeBateauIA(){ // placement bateau de l'ia
	
	
	
}