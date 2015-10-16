#include "Game.h"


using std::cout;
using std::endl;



Game::Game() : pos(0), continuingStartMenu(true)
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (pos == 2)
                    pos = 0;
                else
                    pos ++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (pos == 0)
                    pos = 2;
                else
                    pos --;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))//"Enter"
            {
                switch(pos)
                {
                case 0:
                    continuingStartMenu = false;
                    break;
                case 1:
                    //A completer
                    cout << "DIFFICULTY" << endl;
                    break;
                }
            }
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
    blitText.textStartMenu(window, pos);
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

void Game::generalLoop(sf::RenderWindow *window)
{
    if (continuingStartMenu)
        startMenu(window);
    else
        mainLoop(window);

}

