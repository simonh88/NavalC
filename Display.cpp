#include "Display.h"
#include <cstdlib>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;


Display::Display()
{

}

Display::~Display()
{
    //dtor
}

void Display::refreshCheckerboard()
{

}

void Display::initCheckerboard (const std::vector<std::vector<int> > & dataMap)
{
    realCheckerboard = dataMap;
}


void Display::printCheckerboard()
{
    cout << endl;
    for (int i(0); i<10; i++)
    {
        for (int j(0); j<10; j++)
        {
            cout << " pos(" << i << ":" << j << ") "<< realCheckerboard[i][j] << endl;
        }
    }
}


void Display::tailleComposants(sf:: RenderWindow *window)
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
sf::Text Display::setStaticText(const std::string& word, unsigned int sizeOfFont,
sf::Vector2u initPos, bool bold)
{
    font.loadFromFile("arial.ttf");
    sf::Text myText;
    myText.setFont(font);
    myText.setString(word.c_str());
    myText.setCharacterSize(sizeOfFont);
    myText.setColor(sf::Color::White);
    myText.setPosition(initPos.x, initPos.y);
    if (bold)
        myText.setStyle(sf::Text::Bold);
    return myText;
}


bool Display::blitStaticText(sf::RenderWindow *window)
{
    if (!font.loadFromFile("arial.ttf"))
       return false;

    window->draw(setStaticText("You", 25, sf::Vector2u(170,10), true));
    window->draw(setStaticText("Computer", 25, sf::Vector2u(550,10), true));
    return true;
}

bool Display::loadTileMap(const std::string& tileset, sf::Vector2u tileSize,
std::vector<std::vector<int> > dataMap, unsigned int width, unsigned int height)
{
    // load .png jpg isn't supported
    if (!myTileset.loadFromFile(tileset))
        return false;

    // resize vertices with 10*10
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // fill the vertex with a quad for one tile
    for (unsigned int i = 0; i < width; i++)
        for (unsigned int j = 0; j < height; j++)
        {
            // backup id at this moment for the tile
            int tileNumber = dataMap[j][i];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (myTileset.getSize().x / tileSize.x);
            int tv = tileNumber / (myTileset.getSize().x / tileSize.x);


            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    return true;
}
