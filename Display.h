#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include <Color.hpp>


class Display
{
public:
    Display();
    virtual ~Display();
    void tailleComposants(sf::RenderWindow *window);
    bool blitStaticText(sf::RenderWindow *window);
    sf::Text setStaticText(const std::string& word, unsigned int sizeOfFont,
    sf::Vector2u initPos, bool bold, bool flashing);
    bool StartMenuAndDifficulty(sf::RenderWindow *window, int pos, bool isStartMenu);
    bool flashingText(sf::RenderWindow *window);
    void opacitychange();
    bool textPlacementLoop(sf::RenderWindow *window);
    void blitStatistics(sf::RenderWindow *window, const std::string& turn);

private:
    sf::Font font;
    sf::Texture textureBG;
    sf::Sprite spriteBG;
    sf::Texture textureKeyUp;
    sf::Sprite spriteKeyUp;
    sf::Texture textureKeyDown;
    sf::Sprite spriteKeyDown;
    sf::Color color;
    bool receding; // Need for lighting
};

#endif // DISPLAY_H
