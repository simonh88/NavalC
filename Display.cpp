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


