#include "Game.h"


using std::cout;
using std::endl;



Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}




void Game::startMenu(sf::RenderWindow *window)
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        // fenêtre fermée
        case sf::Event::Closed:
            window->close();
            break;

        // touche pressée
        case sf::Event::KeyPressed:
            //...
            break;

        case sf::Event::MouseButtonPressed:
            cout << "position en x souris : " << event.mouseButton.x << endl;
            cout << "position en y souris : " << event.mouseButton.y << endl;
            break;
        // on ne traite pas les autres types d'évènements
        default:
            break;
        }

    }
    window->clear(sf::Color::Black);
    blitText.textStartMenu(window);
    blitText.flashingText(window);
    window->display();

}


void Game::mainLoop(sf::RenderWindow *window)
{
    while (window->pollEvent(event))
    {
        // évènement "fermeture demandée" : on ferme la fenêtre
        /*if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::)
        */
        switch (event.type)
        {
        // fenêtre fermée
        case sf::Event::Closed:
            window->close();
            break;

        // touche pressée
        case sf::Event::KeyPressed:
            //...
            break;

        case sf::Event::MouseButtonPressed:
            cout << "position en x souris : " << event.mouseButton.x << endl;
            cout << "position en y souris : " << event.mouseButton.y << endl;
            break;
        // on ne traite pas les autres types d'évènements
        default:
            break;
        }
    }
    window->clear(sf::Color::Black);
    blitText.tailleComposants(window);
    blitText.blitStaticText(window);
    window->display();
}

