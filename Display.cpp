#include "Display.h"
#include <cstdlib>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;


Display::Display() : color(255, 255, 255, 255), receding(true)
{

}

Display::~Display()
{
    //dtor
}

void Display::opacitychange()
{
    if (color.a < 255 && !receding)
        color.a ++;
    if(color.a > 0 && receding)
        color.a --;
    if (color.a <= 0)
        receding = false;
    if (color.a >= 200)
        receding = true;
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
sf::Vector2u initPos, bool bold, bool flashing)
{
    font.loadFromFile("arial.ttf");
    sf::Text myText;
    sf::Text flashingT;
    myText.setFont(font);
    myText.setString(word.c_str());
    myText.setCharacterSize(sizeOfFont);
    myText.setColor(sf::Color::White);
    myText.setPosition(initPos.x, initPos.y);
    if (bold)
        myText.setStyle(sf::Text::Bold);
    if (flashing)
    {
        opacitychange();
        flashingT.setFont(font);
        flashingT.setString(word.c_str());
        flashingT.setCharacterSize(sizeOfFont);
        flashingT.setPosition(initPos.x, initPos.y);
        flashingT.setColor(color);
        return flashingT;
    }
    return myText;
}


bool Display::blitStaticText(sf::RenderWindow *window)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;

    window->draw(setStaticText("You", 25, sf::Vector2u(170,10), true, false));
    window->draw(setStaticText("Computer", 25, sf::Vector2u(550,10), true, false));
    return true;
}

bool Display::textPlacementLoop(sf::RenderWindow *window)
{
    window->draw(setStaticText("Placez vos bateaux !", 30, sf::Vector2u(250,10), true, false));
    return true;
}

bool Display::textStartMenu(sf::RenderWindow *window, int pos)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;
    if (!textureBG.loadFromFile("img/background_start_menu.png", sf::IntRect(0, 0, 800, 600)))
        return false;
    if (!textureKeyUp.loadFromFile("img/keyUp.png", sf::IntRect(0, 0, 24, 24)))
        return false;
    if (!textureKeyDown.loadFromFile("img/keyDown.png", sf::IntRect(0, 0, 24, 24)))
        return false;
    spriteBG.setTexture(textureBG);
    spriteKeyUp.setTexture(textureKeyUp);
    spriteKeyDown.setTexture(textureKeyDown);
    spriteKeyUp.setPosition(250, 280);
    spriteKeyDown.setPosition(250, 320);
    window->draw(spriteBG);
    window->draw(spriteKeyUp);
    window->draw(spriteKeyDown);
    window->draw(setStaticText("Welcome to the Navalbattle", 50, sf::Vector2u(80,30), true, false));

    if (pos == 0)
        window->draw(setStaticText("Start a game", 30, sf::Vector2u(300, 250), false, false));
    else
        window->draw(setStaticText("Start a game", 25, sf::Vector2u(300, 250), false, false));
    if (pos == 1)
        window->draw(setStaticText("Difficulty", 30, sf::Vector2u(300, 300), false, false));
    else
        window->draw(setStaticText("Difficulty", 25, sf::Vector2u(300, 300), false, false));
    if (pos == 2)
        window->draw(setStaticText("Rules", 30, sf::Vector2u(300, 350), false, false));
    else
        window->draw(setStaticText("Rules", 25, sf::Vector2u(300, 350), false, false));

    return true;
}

bool Display::flashingText(sf::RenderWindow *window)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;
        for (int i = 0; i<4; i++)
            window->draw(setStaticText("Press \"Enter\" to continue ", 20, sf::Vector2u(560, 575), false, true));
    return true;
}

