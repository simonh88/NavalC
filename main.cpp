#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GetTxt.h"
#include "Display.h"
#include "Board.h"
#include "Joueur.h"
#include "Game.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "NavalBattle");
    window.setFramerateLimit(30);

    GetTxt maRecup;
    Board plat1;
    Board plat2;
    Joueur player;
    Game partie;
//Position du bateau à placer


    //maRecup.Test();
    maRecup.fillCheckerboard("config.txt");
    //maRecup.printCheckerboard();
    //cout << endl << endl << "OOOOOOOOOOOOOOOOOOO : " << A[9][8] << endl;


    /**test en cours **/
    sf::Vector2i coord(289,349);
    switch(player.placeBateauH(coord,true,2))
    {
    case 1:
    {
        cout << "No problems" << endl;
        break;
    }
    case -1:
    {
        cout << "click outside of the checkerBoard"<< endl;
        break;
    }
    case 0:
        cout << "boat is too big, he exceed the size of checkerBoard" << endl;
    }
    /** Fin test **/
    //player.printCheckerboard();
    plat1.updateCheckerboard(player.getcheckerBoard());
    plat2.updateCheckerboard(plat2.newBoard());


    if (!plat1.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10))
        return -1;

    if (!plat2.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10))
        return -1;

    plat1.setPosition(50,50);
    plat2.setPosition(450,50);



    while (window.isOpen()) // Boucle principal
    {
        partie.startMenu(&window);
        //partie.mainLoop(&window);
    }
    cout << endl;
    return 0;
}
