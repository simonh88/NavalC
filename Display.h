#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Display : public sf::Drawable, public sf::Transformable
{
    public:
        Display();
        void initCheckerboard (const std::vector<std::vector<int> > & dataMap);
        virtual ~Display();
        void refreshCheckerboard();
        //Just for test
        void printCheckerboard();
        //idem
        void tailleComposants(sf::RenderWindow *window);


        bool loadTileMap(const std::string& tileset, sf::Vector2u tileSize,
        std::vector<std::vector<int> > dataMap, unsigned int width,
        unsigned int height);

        bool blitStaticText(sf::RenderWindow *window);
        sf::Text setStaticText(const std::string& word, unsigned int sizeOfFont,
        sf::Vector2u initPos, bool bold);

    private:
    std::vector<std::vector<int> > realCheckerboard;
    sf::VertexArray vertices;
    sf::Texture myTileset;
    sf::Font font;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
    // on applique la transformation
    states.transform *= getTransform();
    states.texture = &myTileset;
    target.draw(vertices, states);
    }
};

#endif // DISPLAY_H
