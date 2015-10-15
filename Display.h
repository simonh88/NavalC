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
    bool textStartMenu(sf::RenderWindow *window);
    bool flashingText(sf::RenderWindow *window);
    void opacitychange();

private:
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Color color;
    bool receding; // Need for lighting
};

#endif // DISPLAY_H
