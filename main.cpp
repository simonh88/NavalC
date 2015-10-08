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

using namespace std;

int main()
{

    GetTxt maRecup;
    Display plat1;
    Display plat2;
    Display compenentSize;

    //maRecup.Test();
    maRecup.fillCheckerboard("config.txt");
    //maRecup.printCheckerboard();
    compenentSize.initCheckerboard(maRecup.getCheckerboard());
    compenentSize.printCheckerboard();
    //cout << endl << endl << "OOOOOOOOOOOOOOOOOOO : " << A[9][8] << endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "NavalBattle");
    if (!plat1.loadTileMap("img/test.png", sf::Vector2u(30, 30), maRecup.getCheckerboard(), 10, 10))
        return -1;

    if (!plat2.loadTileMap("img/test.png", sf::Vector2u(30, 30), maRecup.getCheckerboard(), 10, 10))
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
        compenentSize.tailleComposants(&window);
        plat1.blitStaticText(&window);
        window.draw(plat1);
        window.draw(plat2);
        window.display();

    }
    return 0;
}
