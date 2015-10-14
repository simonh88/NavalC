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

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "NavalBattle");

    GetTxt maRecup;
    Board plat1;
    Board plat2;
    Display blitText;
    Joueur player;
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
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        blitText.tailleComposants(&window);
        blitText.blitStaticText(&window);
        window.draw(plat1);
        window.draw(plat2);
        window.display();
    }

    cout << endl;
    return 0;
}
