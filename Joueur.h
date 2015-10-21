#ifndef JOUEUR_H
#define JOUEUR_H
#include "Board.h"
#include <list>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Joueur
{
    public:
        std::vector<std::vector<int> > getcheckerBoard();
        //int placeBateauH(sf::Vector2i coord, bool verticale, int boatLength);
        //Board placeBateauIA();
        void printCheckerboard();

        Joueur();
        Joueur(int ia);
        virtual ~Joueur();
		bool placeBateauH(sf::Vector2i coord, bool verticale, int longueur);
		void placeBateauIA();
		int CheckPlace(int x, int y, Board b);
		void setDifficulty(int x);
		void ordiJoue(Board adversaire);
		bool isIn(std::list<std::pair<int,int> >, int x, int y);
		bool estDansQuadrillage(int x, int y);


        Board plat;
    protected:
    private:
        std::vector <int> row;
		std::vector<std::vector<int> > checkerBoard;
		bool isIa; // vrais = ordi, faux = humain
		Board plateau;
		int ia; // 1;2;3 = ordi, 0 = humain
		std::list <std::pair< int, int> > dejaJouer; // liste des case deja jouer / historique
		std::list <std::pair< int, int> > touche; // liste des case ayant un bateau
		int strat; // "chasse", "traque","bloque"; strategie d'attaque de l'ia,
		/*
		1 = chasse, chercher au hazard( ia 1) en cadrillage (ia 2 3)
		2 = traque, cherche autour d'un bateau touché (ia 2) et continue dans la ligne
		3= l'ordi a toucher un rocher au tour precedent il passe sont tour
		*/
};

#endif // JOUEUR_H
