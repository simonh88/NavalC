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
    Display realCheckerboard;
    //maRecup.Test();
    maRecup.fillCheckerboard("config.txt");
    //maRecup.printCheckerboard();
    realCheckerboard.initCheckerboard(maRecup.getCheckerboard());
    realCheckerboard.printCheckerboard();
    //cout << endl << endl << "OOOOOOOOOOOOOOOOOOO : " << A[9][8] << endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Formes");






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
        realCheckerboard.tailleComposants(&window);
        window.display();

    }
    return 0;
}
