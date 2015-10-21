#include "Joueur.h"

Joueur::Joueur() : row(10, 0), checkerBoard(10, row)  // default Humain
{
    this->ia = 0;
}


Joueur::Joueur(int x) // 1;2;3 = ordi, 0 = humain
{
    this->ia = x;
}

Joueur::~Joueur()
{
    //dtor
}





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





bool Joueur::placeBateauH(sf::Vector2i coordmouse, bool verticale, int longueur)   // placement bateau humain, si vrais, placement reusi
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
            if (this->CheckPlace(a, b, this->plateau) != 0)
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
            this->plateau.setBoard(x, y, pos);
            if (verticale)y++;
            else x++;

        }
        return true;
    }
    return false;
}

void Joueur::placeBateauIA()   // placement bateau de l'ia
{
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
        std::cout << "coucou" << std::endl;
        while (peutPlacer == false)
        {
            // verif assez de place dispo pour placer le bateau de tab[i] cases
            for (int z = 0; z < tab[i]; z++)
            {
                std::cout << "coucou2" << std::endl;
                std::cout << c << b << x << y << std::endl;

                if (this->CheckPlace(c, b, this->plateau) == 0)
                {
                    std::cout << "coucou4" << std::endl;
                    if (!verticale)b++;
                    else c++;
                    peutPlacer = true;
                }
                else
                {
                    std::cout << "coucou5" << std::endl;
                    peutPlacer = false;
                    break; // sort de la boucle de verification si 1 case ne peut pas etre placée
                }
            }
            if (peutPlacer == false)   // si on ne peut placer, new coord aleatoire
            {
                x = rand() % 10;
                y = rand() % 10; //coord random
                a = rand() % 2;
                verticale = (a == 0);
            }
        }
        //placement du bateau dans le tableau de donnée;
        for (int z = 0; z < tab[i]; z++)
        {
            std::cout << "coucou3" << std::endl;

            this->plateau.setBoard(x, y, 2);
            if (!verticale)x++;
            else y++;
        }
    }
this->plateau.printCheckerboard();

}


int Joueur::CheckPlace(int x, int y, Board plateau)   // 0 = de l'eau, 1= un rocher, 2 = un bateau, 3=vide/erreur
{
    std::cout << "le Board : " << plateau.getBoard(x, y) << std::endl;
    switch (this->plateau.getBoard(x, y))
    {
    //std::cout << "le Board : " << plateau.getBoard(x, y) << std::endl;
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    case 2:
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
                this->dejaJouer.push_back(std::make_pair(x,y));
                if (CheckPlace(x, y, adv) == 2)
                {
                    this->touche.push_back(std::make_pair(x,y)); //si un bateau, ajouter au bateau touche
                    this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau
                    // adv[x][y] = ?; dire qu'une case est detruite ?!
                }
                else
                {
                    //dire a l'eau
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
                this->dejaJouer.push_back(std::make_pair(x,y));
                if (CheckPlace(x, y, adv) == 2)
                {
                    this->touche.push_back(std::make_pair(x,y)); //si un bateau, ajouter au bateau touche
                    this->strat = 2; // on passe en mode traque afin de detruire le reste du bateau
                    // adv[x][y] = ?; dire qu'une case est detruite ?!
                }
                else
                {
                    //dire a l'eau
                }

            }
            break; // fin chasse
//-------------------------------------------------
        case 2: //debut traque

            int lastx = this->touche.end()->first;
            int lasty = this->touche.end()->second; // recupere les derniere coordoné du bateau touché

            if (CheckPlace(lastx + 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx, lasty))   //cherche autour, et sans tomber sur un cailloux
            {
                this->touche.push_back(std::make_pair(lastx + 1, lasty));
                this->dejaJouer.push_back(std::make_pair(lastx + 1, lasty));
            }
            else if (CheckPlace(lastx, lasty + 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty))
            {
                this->touche.push_back(std::make_pair(lastx, lasty + 1));
                this->dejaJouer.push_back(std::make_pair(lastx, lasty + 1));
            }
            else if (CheckPlace(lastx - 1, lasty, adv) == 2 && !isIn(dejaJouer, lastx, lasty))
            {
                this->touche.push_back(std::make_pair(lastx - 1, lasty));
                this->dejaJouer.push_back(std::make_pair(lastx - 1, lasty));
            }
            else if (CheckPlace(lastx, lasty - 1, adv) == 2 && !isIn(dejaJouer, lastx, lasty))
            {
                this->touche.push_back(std::make_pair(lastx, lasty - 1));
                this->dejaJouer.push_back(std::make_pair(lastx, lasty - 1));
                // adv[][] = detruit  ?? dire qu'une case est detruite
            }
            else
            {
                this->strat = 1; // le bateau a été entierement détruit deja, on repasse en mode chasse
                this->ordiJoue(adv);
            }

            break; //fin traque
        }
        break;
        // fin ia difficile
//-------------------------------------

    case 2: //ia moyen
        //meme strat que l'ia difficile, mais ne peut eviter les rocher, et peut faire des erreur sur le bateau touche
        //TODO
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

                break;
            case 1 : // un rocher
                this->dejaJouer.push_back(std::make_pair(x,y));
                this->strat = 3;

                break;
            case 2:
                this->touche.push_back(std::make_pair(x,y)); //si un bateau, ajouter au bateau touche
                //adv[][] = detruit ??!
                break;
            }
        }
        else
        {
            //printf("passe son tour");
        }
        break;
    }
}

bool Joueur::isIn(std::list<std::pair<int, int> > list, int x, int y) // verif d'une valeur dans une liste de paire(coordonée)
{
    std::pair<int, int> cherche;
    cherche.first = x;
    cherche.second = y;

    std::list<std::pair<int, int> >::iterator li;
    li = std::find(list.begin(), list.end(), cherche);

    if (li != list.end()) return true; //valeur dans la liste
    else return false; //valeur pas dans la liste
}

bool Joueur::estDansQuadrillage(int x, int y)
{
    int xx = this->dejaJouer.back().first; //coordonée x du dernier element ajouté
    int yy = this->dejaJouer.back().second; // coordonée y du dernier element ajouté

    int a = (x - xx) + (y - yy);

    if (a % 2 == 0) return true;
    else return false;
}
