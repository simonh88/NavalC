#include "Joueur.h"

/*Constructor (surchage pour init le checkerboard à 0 */
Joueur::Joueur() : row(10, 0), checkerBoard(10, row)  // default Humain
{
	this->ia = 0;
}

/*Constructor avec un param x pour défénir
* la difficulté de l'ordi
*/
Joueur::Joueur(int x) // 1;2;3 = ordi, 0 = humain
{
	this->ia = x;
}

/*Destructor */
Joueur::~Joueur()
{
	//dtor
}




/* Getteur du checkerboard */
std::vector<std::vector<int> > Joueur::getcheckerBoard()
{
	return checkerBoard;
}

/*int Joueur::placeBateauH(sf::Vector2i coord, bool verticale, int boatLength )
{
// placement bateau humain
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

//test if boat is in the checkerboard

if (x >= 0 && y >= 0 && x < 300 && y < 300)
{
x = x / 30;
y = y / 30;
for( int i = 0; i<boatLength; i++)
{
this->checkerBoard[x][y] = pos;
if(verticale)x++;
else y++;
}
}
return 1; // No problems
}
*/
/*Affichage du checkerboard pour debug */
void Joueur::printCheckerboard()
{
	std::cout << std::endl;
	for (int i(0); i < 10; i++)
	{
		for (int j(0); j < 10; j++)
		{
			std::cout << " pos(" << i << ":" << j << ") " << checkerBoard[i][j] << std::endl;
		}
	}
}




// placement bateau humain, si vrais, placement reusi

bool Joueur::placeBateauH(sf::Vector2i coordmouse, bool verticale, int longueur)
{
	int x(coordmouse.x);
	int y(coordmouse.y);
	int pos(2);
	if (verticale) pos = 3;

	if (x >= 50 && y >= 50 && x <= 350 && y <= 350)
	{
		x = (x - 50) / 29;
		y = (y - 50) / 29;

		int a = x;
		int b = y;
		// test de la place pour le bateau;


		for (int i = 0; y < longueur; i++)
		{
			if (this->CheckPlace(a, b, this->plat) != 0)
			{
				if (!verticale)a++;
				else b++;
			}
			else
			{
				std::cout << "quelque chose bloque" << std::endl;
				return false;
			}
		}
		// placement du bateau
		for (int i = 0; i < longueur; i++)
		{
			this->plat.setBoard(x, y, pos);
			if (verticale)y++;
			else x++;

		}
		return true;
	}
	return false;
}


bool Joueur::joueurJoue(Board adv, Board tmp, int x, int y) { // x, y les coordonné de la souris sans direct, board tmp sera l'affichage du board adverse


	x = x - 450; // valeurs de la premier case est de 450, on simplifie en mettant x a zero
	y = y - 50; // valeurs de la premier case est de 50, on simplifie en mettant y a zero

	if (x >= 0 || y >= 0 || x > 399 || y > 299) {
		if (x <= 299) x = 9;
		if (x <= 269) x = 8;
		if (x <= 239) x = 7;
		if (x <= 209) x = 6;
		if (x <= 179) x = 5;
		if (x <= 149) x = 4;
		if (x <= 119) x = 3;
		if (x <= 89) x = 2;
		if (x <= 59) x = 1;
		if (x <= 29) x = 0; // donne la  case x dans le tableau adverse

		if (y <= 299) y = 9;
		if (y <= 269) y = 8;
		if (y <= 239) y = 7;
		if (y <= 209) y = 6;
		if (y <= 179) y = 5;
		if (y <= 149) y = 4;
		if (y <= 119) y = 3;
		if (y <= 89) y = 2;
		if (y <= 59) y = 1;
		if (y <= 29) y = 0; // donne la case y dans le tableau adverse;

		int a = CheckPlace(x, y, adv);

		switch (a) {
		case 0: // a l'eau
			adv.setBoard(x, y, 4);
			tmp.setBoard(x, y, 4); // place sur le board afficher une croix bleu 
			return true;
			break;
		case 1: // rocher
				//TODO faire passer son tour
			tmp.setBoard(x, y, 1); // place sur le board afficher un rocher
			return true;
			break;
		case 2: // touche bateau
			adv.setBoard(x, y, 5);
			tmp.setBoard(x, y, 5); // place sur le board afficher, une croix rouge representant la bateau touché
			return true;
		case 3: // zone deja touché, deja joué, ( où hors tableau si la verif a bugé)
		default:
			return false;
			break;
		}


	}
	else {
		return false; // le clique n'était pas dans le tableau;
	}



}













/* Du coup, ici, rajouter peut être un param qui contient le vector des bateaux */
void Joueur::placeBateauIA()   // placement bateau de l'ia
{
	/* On pourra lire le nombre de bateaux que le joueur à placer
	* et par la suite utiliser le tableau qui contient tout les tailles.
	*/
	int x;
	int y;
	bool verticale;
	//int nbBateau = 5; // 5 bateau de 2;3;3;4;5 case
	int tab[5] = { 2,3,3,4,5 };
	int a;

	// boucle de 5 bateaux
	for (int i = 0; i < 5; i++)
	{
		a = rand() % 2;
		verticale = (a == 0); // sens bateau random
		x = rand() % 10;
		y = rand() % 10; //coord random

		int c = x; // coord temporaire pour verif
		int b = y;
		bool peutPlacer = false;
		while (!peutPlacer)
		{
			// verif assez de place dispo pour placer le bateau de tab[i] cases
			for (int z = 0; z < tab[i]; z++)
			{

				if (this->CheckPlace(c, b, this->plat) == 0)
				{
					if (!verticale)b++;
					else c++;
					peutPlacer = true;
				}
				else
				{
					peutPlacer = false;
					break; // sort de la boucle de verification si 1 case ne peut pas etre placée
				}
			}
			if (peutPlacer == false)   // si on ne peut placer, new coord aleatoire
			{
				c = rand() % 10;
				b = rand() % 10;//coord random
				x = c;
				y = b;
				a = rand() % 2;
				verticale = (a == 0);
			}
		}
		//placement du bateau dans le tableau de donnée;
		for (int z = 0; z < tab[i]; z++)
		{
			if (!verticale) {
				this->plat.setBoard(x, y, 2);
				y++;
			}
			else {
				this->plat.setBoard(x, y, 3);
				x++;
			}
		}
	}
	//this->plat.printCheckerboard();

}


int Joueur::CheckPlace(int x, int y, Board plateau)   // 0 = de l'eau, 1= un rocher, 2 = un bateau, 3 = erreur, zone deja touché(anormale)
{
	//std::cout << "le Board : " << plateau.getBoard(x, y) << std::endl;
	switch (plateau.getBoard(x, y))
	{
		//std::cout << "le Board : " << plateau.getBoard(x, y) << std::endl;
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
	case 3:
		return 2;
		break;
	default:
		return 3;
		break;
	}

}

void Joueur::setDifficulty(int x)
{
	if (x >= 0 && x <= 3)
		this->ia = x;
	else
		this->ia = 0; // par default humain;
}

void Joueur::ordiJoue(Board adv)
{
	int x; //coordonées
	int y;
	/* forcing de la difficultée ! */
	this->ia = 1;

	switch (this->ia)
	{

	case 3: //ia difficile
		switch (this->strat)
		{

			//-------------------------------------------
		case 1: // debut chasse
			if (this->dejaJouer.empty())   // premier tour de l'ordi
			{
				x = rand() % 10;
				y = rand() % 10;
				while (CheckPlace(x, y, adv) == 1)   // l'ordi est trop fort, il ne tombe pas sur les rocher
				{
					x = rand() % 10;
					y = rand() % 10;
				}
				this->dejaJouer.push_back(std::make_pair(x, y));
				if (CheckPlace(x, y, adv) == 2)
				{
					this->touche.push_back(std::make_pair(x, y)); //si un bateau, ajouter au bateau touche
					this->First.push_back(std::make_pair(x, y)); // ajoute la case comme premiere case touche
					this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau

					adv.setBoard(x, y, 4); // TODO img croix rouge pour indiqué bateau touché
				}
				else
				{
					adv.setBoard(x, y, 5); // TODO img croix bleu                }
				}
			}
			else   // on chasse en quadrillage en fonction du dernier coup deja jouer en evitant les rochers
			{

				x = rand() % 10;
				y = rand() % 10;
				while (CheckPlace(x, y, adv) == 1 || isIn(this->dejaJouer, x, y) || !estDansQuadrillage(x, y))
				{
					// il ne tombe pas sur les rocher, et ne rejoue pas une case deja joué, et cherche dans le case en cadriallage
					x = rand() % 10;
					y = rand() % 10;
				}
				this->dejaJouer.push_back(std::make_pair(x, y));
				if (CheckPlace(x, y, adv) == 2)
				{
					this->touche.push_back(std::make_pair(x, y)); //si un bateau, ajouter au bateau touche
					this->First.push_back(std::make_pair(x, y));
					this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau
					adv.setBoard(x, y, 4); // TODO img croix rouge pour indiqué bateau touché
				}
				else
				{
					adv.setBoard(x, y, 5); // TODO img croix bleu				}

				}
				break; // fin chasse
					   //-------------------------------------------------
		case 2: //debut traque

			int lastx = this->touche.end()->first;
			int lasty = this->touche.end()->second; // recupere les derniere coordoné du bateau touché

			if (CheckPlace(lastx + 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx + 1, lasty))   //cherche autour, et sans tomber sur un cailloux
			{
				this->touche.push_back(std::make_pair(lastx + 1, lasty));
				this->dejaJouer.push_back(std::make_pair(lastx + 1, lasty));
				adv.setBoard(lastx + 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché

			}
			else if (CheckPlace(lastx, lasty + 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty + 1))
			{
				this->touche.push_back(std::make_pair(lastx, lasty + 1));
				this->dejaJouer.push_back(std::make_pair(lastx, lasty + 1));
				adv.setBoard(lastx, lasty + 1, 4); // TODO img croix rouge pour indiqué bateau touché


			}
			else if (CheckPlace(lastx - 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx - 1, lasty))
			{
				this->touche.push_back(std::make_pair(lastx - 1, lasty));
				this->dejaJouer.push_back(std::make_pair(lastx - 1, lasty));
				adv.setBoard(lastx - 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché

			}
			else if (CheckPlace(lastx, lasty - 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty - 1))
			{
				this->touche.push_back(std::make_pair(lastx, lasty - 1));
				this->dejaJouer.push_back(std::make_pair(lastx, lasty - 1));
				adv.setBoard(lastx, lasty - 1, 4); // TODO img croix rouge pour indiqué bateau touché
			}
			else // on test avec la case de depart pour voir si l'on a pas manqué des case avant
			{
				int firstx = this->First.end()->first;
				int firsty = this->First.end()->second; // recupere les coordoné de la permiere case touché

				if (CheckPlace(firstx + 1, firsty, adv) == 2 && !isIn(dejaJouer, firstx + 1, firsty))   //cherche autour, et sans tomber sur un cailloux
				{
					this->touche.push_back(std::make_pair(firstx + 1, firsty));
					this->dejaJouer.push_back(std::make_pair(firstx + 1, firsty));
					adv.setBoard(lastx + 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché

				}
				else if (CheckPlace(firstx, firsty + 1, adv) == 2 && !isIn(dejaJouer, firstx, firsty + 1))
				{
					this->touche.push_back(std::make_pair(firstx, firsty + 1));
					this->dejaJouer.push_back(std::make_pair(firstx, firsty + 1));
					adv.setBoard(lastx, lasty + 1, 4); // TODO img croix rouge pour indiqué bateau touché

				}
				else if (CheckPlace(firstx - 1, firsty, adv) == 2 && !isIn(dejaJouer, firstx - 1, firsty))
				{
					this->touche.push_back(std::make_pair(firstx - 1, firsty));
					this->dejaJouer.push_back(std::make_pair(firstx - 1, firsty));
					adv.setBoard(lastx - 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché

				}
				else if (CheckPlace(firstx, firsty - 1, adv) == 2 && !isIn(dejaJouer, firstx, firsty - 1))
				{
					this->touche.push_back(std::make_pair(firstx, firsty - 1));
					this->dejaJouer.push_back(std::make_pair(firstx, firsty - 1));
					adv.setBoard(lastx, lasty - 1, 4); // TODO img croix rouge pour indiqué bateau touché
				}
				else {
					this->strat = 1; // sinon le bateau a été entierement détruit deja, on repasse en mode chasse
					this->ordiJoue(adv);
				}
			}

			break; //fin traque
			}
		}
		break;

		// fin ia difficile
		//-------------------------------------

	case 2: //ia moyen
			//meme strat que l'ia difficile, mais ne peut eviter les rocher, et peut faire des erreur sur le bateau touche
		switch (this->strat)
		{

			//-------------------------------------------
		case 1: // debut chasse
			if (this->dejaJouer.empty())   // premier tour de l'ordi
			{
				x = rand() % 10;
				y = rand() % 10;

				this->dejaJouer.push_back(std::make_pair(x, y));

				if (CheckPlace(x, y, adv) == 2)
				{
					this->touche.push_back(std::make_pair(x, y)); //si un bateau, ajouter au bateau touche
					this->First.push_back(std::make_pair(x, y));
					this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau
					adv.setBoard(x, y, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

				}
				else
				{
					if (CheckPlace(x, y, adv) == 1) {

						this->strat = 3; // l'ordi a touché une pierre, il passe son tour au tour prochain
						adv.setBoard(x, y, 5); // TODO img croix bleu
					}
					else {
						adv.setBoard(x, y, 5); // TODO img croix bleu					}
					}
				}
			}
			else   // on chasse en quadrillage en fonction du dernier coup deja jouer en evitant les rochers
			{

				x = rand() % 10;
				y = rand() % 10;
				while (isIn(this->dejaJouer, x, y) || !estDansQuadrillage(x, y))
				{
					// il ne rejoue pas une case deja joué, et cherche dans le case en cadriallage
					x = rand() % 10;
					y = rand() % 10;
				}
				this->dejaJouer.push_back(std::make_pair(x, y));
				if (CheckPlace(x, y, adv) == 2)
				{
					this->touche.push_back(std::make_pair(x, y)); //si un bateau, ajouter au bateau touche
					this->First.push_back(std::make_pair(x, y));
					this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau
					adv.setBoard(x, y, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

				}
				else
				{
					if (CheckPlace(x, y, adv) == 1) {

						this->strat = 3; // l'ordi a touché une pierre, il passe son tour au tour prochain
						adv.setBoard(x, y, 5); // TODO img croix bleu
					}
					else {
						adv.setBoard(x, y, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4
					}
				}

			}
			break; // fin chasse
				   //-------------------------------------------------
		case 2: //debut traque

			int lastx = this->First.end()->first;
			int lasty = this->First.end()->second; // recupere les derniere coordonnées du bateau touché


			if (neso == NULL) {//seconde case donnant la direction
				int aa = 0;
				int lastx = this->First.end()->first;
				int lasty = this->First.end()->second; // recupere les derniere coordoné du bateau touché

				if (CheckPlace(lastx + 1, lasty, adv) != 3 && !isIn(dejaJouer, lastx + 1, lasty))   //cherche autour, et sans tomber sur un cailloux
				{
					this->dejaJouer.push_back(std::make_pair(lastx + 1, lasty));
					aa = CheckPlace(lastx + 1, lasty, adv);
					if (aa == 2) {
						neso = 1; // est
						this->touche.push_back(std::make_pair(lastx + 1, lasty)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx + 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else if (aa == 1) {
						strat = 1;
					}
					else {
						adv.setBoard(lastx + 1, lasty, 5); // TODO img croix bleu					}
					}
				}
				else if (CheckPlace(lastx, lasty + 1, adv) != 3 && !isIn(dejaJouer, lastx, lasty + 1))
				{
					this->dejaJouer.push_back(std::make_pair(lastx, lasty + 1));
					aa = CheckPlace(lastx, lasty + 1, adv);
					if (aa == 2) {
						neso = 3; // sud
						this->touche.push_back(std::make_pair(lastx, lasty + 1)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx, lasty + 1, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else if (aa == 1) {
						strat = 1;
					}
					else {
						adv.setBoard(lastx, lasty + 1, 5); // TODO img croix bleu					}
					}
				}
				else if (CheckPlace(lastx - 1, lasty, adv) != 3 && !isIn(dejaJouer, lastx - 1, lasty))
				{
					this->dejaJouer.push_back(std::make_pair(lastx - 1, lasty));
					aa = CheckPlace(lastx - 1, lasty, adv);
					if (aa == 2) {
						neso = 4; // ouest
						this->touche.push_back(std::make_pair(lastx - 1, lasty)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx - 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else if (aa == 1) {
						strat = 1;
					}
					else {
						adv.setBoard(lastx - 1, lasty, 5); // TODO img croix bleu					}
					}
				}
				else if (CheckPlace(lastx, lasty - 1, adv) != 3 && !isIn(dejaJouer, lastx, lasty - 1))
				{
					this->dejaJouer.push_back(std::make_pair(lastx, lasty - 1));
					aa = CheckPlace(lastx, lasty - 1, adv);
					if (aa == 2) {
						neso = 1; // nord
						this->touche.push_back(std::make_pair(lastx, lasty - 1)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx, lasty - 1, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else if (aa == 1) {
						strat = 1;
					}
					else {
						adv.setBoard(lastx, lasty - 1, 5); // TODO img croix bleu
					}
				}
				else { // bateau entierement detruit, pard en mode chasse
					this->strat = 1;
					this->ordiJoue(adv);
				}


			}
			else { // si on connais la direction "neso"

				switch (neso) {
				case 1://Nord
					this->dejaJouer.push_back(std::make_pair(lastx, lasty - 1));
					if (CheckPlace(lastx, lasty - 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty - 1)) {
						this->touche.push_back(std::make_pair(lastx, lasty - 1)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx, lasty - 1, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else {
						if (CheckPlace(lastx, lasty - 1, adv) == 1 && !isIn(dejaJouer, lastx, lasty - 1)) {
							strat = 1;
							adv.setBoard(lastx, lasty - 1, 5); // TODO img croix bleu
						}
						else {
							adv.setBoard(lastx, lasty - 1, 5); // TODO img croix bleu							neso = NULL; // on a atteind un bout du bateau, on test l'autre bout
						}
					}
					break;
				case 2: // est
					this->dejaJouer.push_back(std::make_pair(lastx + 1, lasty));
					if (CheckPlace(lastx + 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx + 1, lasty)) {
						this->touche.push_back(std::make_pair(lastx + 1, lasty)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx + 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else {
						if (CheckPlace(lastx + 1, lasty, adv) == 1 && !isIn(dejaJouer, lastx + 1, lasty)) { // caillou
							strat = 1;
							adv.setBoard(lastx + 1, lasty, 5); // TODO img croix bleu
						}
						else {
							// a l'eau
							neso = NULL; // on a atteind un bout du bateau, on test l'autre bout
							adv.setBoard(lastx + 1, lasty, 5); // TODO img croix bleu
						}
					}
					break;
				case 3: // sud
					this->dejaJouer.push_back(std::make_pair(lastx, lasty + 1));
					if (CheckPlace(lastx, lasty + 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty + 1)) {
						this->touche.push_back(std::make_pair(lastx, lasty + 1)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx, lasty + 1, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else {
						if (CheckPlace(lastx, lasty + 1, adv) == 1 && !isIn(dejaJouer, lastx, lasty + 1)) {
							adv.setBoard(lastx, lasty + 1, 5); // TODO img croix bleu
							strat = 1;
						}
						else {
							// a l'eau
							neso = NULL; // on a atteind un bout du bateau, on test l'autre bout
							adv.setBoard(lastx, lasty + 1, 5); // TODO img croix bleu
						}
					}
					break;
				case 4: // ouest
				default:
					this->dejaJouer.push_back(std::make_pair(lastx - 1, lasty));
					if (CheckPlace(lastx - 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx - 1, lasty)) {
						this->touche.push_back(std::make_pair(lastx - 1, lasty)); //si un bateau, ajouter au bateau touche
						adv.setBoard(lastx - 1, lasty, 4); // TODO img croix rouge pour indiqué bateau touché avec indice 4

					}
					else {
						if (CheckPlace(lastx - 1, lasty, adv) == 1 && !isIn(dejaJouer, lastx - 1, lasty)) {
							adv.setBoard(lastx - 1, lasty, 5); // TODO img croix bleu
							strat = 1;
						}
						else {
							// a l'eau
							neso = NULL; // on a atteind un bout du bateau, on test l'autre bout
							adv.setBoard(lastx - 1, lasty, 5); // TODO img croix bleu
						}
					}
					break;

				}
			}

			break; //fin traque
		}
		break;

	case 1://ia facile
	default:
		//RANDOOOOOOOOOOOOM POWAAAAAAAA

		if (this->strat != 3)
		{
			x = rand() % 10;
			y = rand() % 10;
			while (isIn(this->dejaJouer, x, y))
			{
				// il ne rejoue pas une case deja joué
				x = rand() % 10;
				y = rand() % 10;
			}

			switch (CheckPlace(x, y, adv))
			{

			case 0:
			default: // a l'eau
				this->dejaJouer.push_back(std::make_pair(x, y));
				adv.setBoard(x, y, 5); // TODO img croix bleu


				break;
			case 1: // un rocher
				this->dejaJouer.push_back(std::make_pair(x, y));
				this->strat = 3;

				break;
			case 2:
				this->touche.push_back(std::make_pair(x, y)); //si un bateau, ajouter au bateau touche
				adv.setBoard(x, y, 4); // TODO img croix rouge
				break;
			}
		}
		else
		{
			//pass ton tour cout << <<
		}
		break;
	}
}

bool Joueur::isIn(std::vector<std::pair<int, int> > L, int x, int y) // verif d'une valeur dans une liste de paire(coordonée)
{
	std::pair<int, int> cherche;
	cherche.first = x;
	cherche.second = y;

	std::vector<std::pair<int, int> >::iterator li;
	li = std::find(L.begin(), L.end(), cherche);

	if (li != L.end()) return true; //valeur dans le vector
	else return false; //valeur pas dans le vector
}

bool Joueur::estDansQuadrillage(int x, int y)
{
	int xx = this->dejaJouer.back().first; //coordonée x du dernier element ajouté
	int yy = this->dejaJouer.back().second; // coordonée y du dernier element ajouté

	int a = (x - xx) + (y - yy);

	if (a % 2 == 0) return true;
	else return false;
}
