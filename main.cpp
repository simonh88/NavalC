#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;
bool is_readable( const string & file )
{
    ifstream fichier( file.c_str() );
    return !fichier.fail();
}

void read(const string & file)
{
    ifstream fichier( file.c_str() );
    string ligne;
    while (getline(fichier, ligne))
    {
        cout << ligne << endl;
    }
}

void Test()
{
    if ( is_readable( "config.txt" ) )
    {
        read("config.txt");
    }
    else
    {
        cout << "Le Fichier inexistant ou non lisible.\n";
    }
}

int main()
{
    Test();
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Formes");

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
        window.display();
    }*/
    return 0;
}
