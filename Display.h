#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Display
{
    public:
        Display();
        virtual ~Display();
        //Just for test
        void printCheckerboard();
        //idem
        void tailleComposants(sf::RenderWindow *window);

        bool blitStaticText(sf::RenderWindow *window);
        sf::Text setStaticText(const std::string& word, unsigned int sizeOfFont,
        sf::Vector2u initPos, bool bold);

    private:
    sf::Font font;
};

#endif // DISPLAY_H
