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


void tailleComposants(sf:: RenderWindow *window)
{
    // Ligne de séparation du milieu écran
    sf::RectangleShape line(sf::Vector2f(600, 1));
    line.setOrigin(1,400);
    line.rotate(90);
    //Ligne de séparation pour les scores etl'histo
    sf::RectangleShape line2(sf::Vector2f(800, 1));
    line2.setOrigin(800,400);
    line2.rotate(180);

    sf::RectangleShape plat1(sf::Vector2f(300, 300));
    plat1.setOrigin(350, 350);
    plat1.rotate(180);

    sf::RectangleShape plat2(sf::Vector2f(300, 300));
    plat2.setOrigin(750,350);
    plat2.rotate(180);

        //draw
        window->draw(line);
        window->draw(line2);
        window->draw(plat1);
        window->draw(plat2);
}

int main()
{

    std::vector<std::vector<int> > A;
    GetTxt maRecup;
    //maRecup.Test();
    maRecup.fillCheckerboard("config.txt");
    maRecup.printCheckerboard();
    /* CA FONCTIOOOOOONNNE !
    A = maRecup.getCheckerboard();
    cout << endl << endl << "OOOOOOOOOOOOOOOOOOO : " << A[9][8] << endl;
    */
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
        tailleComposants(&window);
        window.display();

    }
    return 0;
}
