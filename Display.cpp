#include "Display.h"
#include <cstdlib>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;

/*Constructeur utilisant la surcharge pour init auto color et receding */
Display::Display() : color(255, 255, 255, 255), receding(true)
{

}
/* Destructor */
Display::~Display()
{
    //dtor
}

/*Permet de faire varier l'opaciter des textes pour faire clignoter */
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
/*Affiche les rectangles ou doivent se trouver les grilles
 * Juste des repères pour debug plus facilement
 */
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
/*Affichage de nombreuses stats */
void Display::blitStatistics(sf::RenderWindow *window, const std::string& turn,const  std::string& sizeBoatMoi,
 const std::string& sizeBoatIa, const std::string& nbBoatMoi, const std::string& nbBoatIa,
 const std::string& nbWaterMoi, const std::string& nbWaterIa, const std::string& nbFireMoi,
const std::string& nbFireIa, const std::string& nbTotMoi, const std::string& nbTotIa,
const std::string& nbPartMoi, const std::string& nbPartIa)
{
  /* COMPUTER */
  window->draw(setStaticText("Boat alive                    :    " + nbBoatIa, 23, sf::Vector2u(410,400), false, false));
  window->draw(setStaticText("Size of boat alive        :    " + sizeBoatIa, 23, sf::Vector2u(410,425), false, false));
  window->draw(setStaticText("Number of parts alive :    " + nbPartIa, 23, sf::Vector2u(410,450), false, false));
  window->draw(setStaticText("Number of turns          :    " + turn, 23, sf::Vector2u(410,480), false, false));
  window->draw(setStaticText("Number of water hit    :    " + nbWaterIa, 23, sf::Vector2u(410,510), false, false));
  window->draw(setStaticText("Number of boat hit      :    " + nbFireIa, 23, sf::Vector2u(410,540), false, false));
  window->draw(setStaticText("Total hit                        :    " + nbTotIa, 23, sf::Vector2u(410,568), false, false));
  /* PLAYER */
  window->draw(setStaticText("Boat alive                    :    " + nbBoatMoi, 23, sf::Vector2u(10,400), false, false));
  window->draw(setStaticText("Size of boat alive        :    " + sizeBoatMoi, 23, sf::Vector2u(10,425), false, false));
  window->draw(setStaticText("Number of parts alive :    " + nbPartMoi, 23, sf::Vector2u(10,450), false, false));
  window->draw(setStaticText("Number of turns          :    " + turn, 23, sf::Vector2u(10,480), false, false));
  window->draw(setStaticText("Number of water hit    :    " + nbWaterMoi, 23, sf::Vector2u(10,510), false, false));
  window->draw(setStaticText("Number of boat hit      :    " + nbFireMoi, 23, sf::Vector2u(10,540), false, false));
  window->draw(setStaticText("Total hit                        :    " + nbTotMoi, 23, sf::Vector2u(10,568), false, false));
}
/* Pour afficher du texte static(qui ne bouge pas) choix de plusieurs param */
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

/*Affichage du texte static dans la main loop
 * A completer !!!!
 */
bool Display::blitStaticText(sf::RenderWindow *window)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;
    if (!textureBG.loadFromFile("img/Mer.png", sf::IntRect(0, 0, 800, 600)))
        return false;
    spriteBG.setTexture(textureBG);
    window->draw(spriteBG);
    window->draw(setStaticText("You", 25, sf::Vector2u(170,10), true, false));
    window->draw(setStaticText("Computer", 25, sf::Vector2u(550,10), true, false));
    return true;
}
/*Affichage du texte static dans le placementloop
 * Moment ou les bateaux sont placés par l'humain
 */
bool Display::textPlacementLoop(sf::RenderWindow *window)
{
    if (!textureBG.loadFromFile("img/waiting.png", sf::IntRect(0, 0, 800, 600)))
        return false;
    spriteBG.setTexture(textureBG);
    window->draw(spriteBG);
    window->draw(setStaticText("A vos armes !", 30, sf::Vector2u(330,10), true, false));

    return true;
}
/*Affichage ecran final ! */
bool Display::textFinalWindow(sf::RenderWindow *window, bool win){
  if (!font.loadFromFile("arial.ttf"))
    return false;
  if (!textureBG.loadFromFile("img/final.png", sf::IntRect(0, 0, 800, 600)))
    return false;
  spriteBG.setTexture(textureBG);
  window->draw(spriteBG);
  if (win)
    window->draw(setStaticText("YOU WIN !!!", 100, sf::Vector2u(100,300), true, false));
  else
    window->draw(setStaticText("YOU LOOSE ...", 100, sf::Vector2u(100,300), true, false));
  return true;
}
/*Affichage du texte et des sprites du StartMenu*/
bool Display::StartMenuAndDifficulty(sf::RenderWindow *window, int pos, bool isStartMenu)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;
    if(isStartMenu){
      if (!textureBG.loadFromFile("img/background_start_menu.png", sf::IntRect(0, 0, 800, 600)))
        return false;
    }else{
      if (!textureBG.loadFromFile("img/boatDiff.png", sf::IntRect(0, 0, 800, 600)))
        return false;
    }
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
    if (isStartMenu)
      window->draw(setStaticText("Welcome to the Navalbattle", 50, sf::Vector2u(80,30), true, false));
    else
      window->draw(setStaticText("Choose your difficulty", 50, sf::Vector2u(80,30), true, false));
    if(isStartMenu){
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
    }else{
      if (pos == 0)
          window->draw(setStaticText("EASY", 30, sf::Vector2u(300, 250), false, false));
      else
          window->draw(setStaticText("EASY", 25, sf::Vector2u(300, 250), false, false));
      if (pos == 1)
          window->draw(setStaticText("MEDIUM", 30, sf::Vector2u(300, 300), false, false));
      else
          window->draw(setStaticText("MEDIUM", 25, sf::Vector2u(300, 300), false, false));
      if (pos == 2)
          window->draw(setStaticText("HARD", 30, sf::Vector2u(300, 350), false, false));
      else
          window->draw(setStaticText("HARD", 25, sf::Vector2u(300, 350), false, false));
    }

    return true;
}
/*Affiche le text clignotant*/
bool Display::flashingText(sf::RenderWindow *window)
{
    if (!font.loadFromFile("arial.ttf"))
        return false;
        for (int i = 0; i<4; i++)
            window->draw(setStaticText("Press \"Enter\" to continue ", 20, sf::Vector2u(560, 575), false, true));
    return true;
}

