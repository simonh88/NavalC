#ifndef JOUEUR_H
#define JOUEUR_H
#include "Board.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Joueur
{
    public:
        Joueur();
        ~Joueur();
        std::vector<std::vector<int> > getcheckerBoard();
        int placeBateauH(sf::Vector2i coord, bool verticale, int boatLength);
        Board placeBateauIA();
        void printCheckerboard();

        Board plat;
    protected:
    private:
        std::vector <int> row;
		std::vector<std::vector<int> > checkerBoard;
		bool isIa; // vrais = ordi, faux = humain
};

#endif // JOUEUR_H
