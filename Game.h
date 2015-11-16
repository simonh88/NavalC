#ifndef GAME_H
#define GAME_H
#include "GetTxt.h"
#include "Display.h"
#include "Board.h"
#include "Joueur.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
    public:
        Game();
        virtual ~Game();
        void startMenu(sf::RenderWindow *window);
        void mainLoop(sf::RenderWindow *window);
        void generalLoop(sf::RenderWindow *window);
        void placementLoop(sf::RenderWindow *window);
        void difficultyLoop(sf::RenderWindow *window);
    protected:
    private:
        sf::Event event;
        Display blitText; //Permet d'afficher tout les textes et sprites au fil du temps
        GetTxt maRecup; //Permet la récupération du fichier .txt
        Joueur moi;
        Joueur ia;
        Joueur tmp; //utiliser pour le choix des bateaux et pour cacher l'affichage de l'ordi
        /*Board* pBmoi;
        Board* pBia;
        Board* pBtmp;*/
        unsigned int nbRock;
        int pos;  //Permet de se repérer dans le startingMenu pour naviguer entre les sous menus
        bool continuingStartMenu;  //Permet de savoir si on a besoin d'afficher le startmenu
        bool placementMenu;  // Permet de savoir si on a besoin d'afficher le placementMenu
        bool difficultyMenu;
};

#endif // GAME_H
