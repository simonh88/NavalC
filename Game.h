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
    protected:
    private:
    sf::Event event;
    Display blitText;
    int j;
};

#endif // GAME_H