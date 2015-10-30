#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
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
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(30);
    srand(time(NULL));

    Game partie;

    while (window.isOpen()) // Boucle principal
    {
        partie.generalLoop(&window);
    }
    cout << endl;
    return 0;
}
