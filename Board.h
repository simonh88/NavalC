#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Board : public sf::Drawable, public sf::Transformable
{
    public:
        Board();
        virtual ~Board();
        void printCheckerboard();
        void updateCheckerboard (const std::vector<std::vector<int> > & dataMap);
        bool loadTileMap(const std::string& tileset, sf::Vector2u tileSize,
        unsigned int width, unsigned int height);
        std::vector<std::vector<int> > newBoard();

    private:
    std::vector<std::vector<int> > realCheckerboard;
    sf::VertexArray vertices;
    sf::Texture myTileset;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
    // on applique la transformation
    states.transform *= getTransform();
    states.texture = &myTileset;
    target.draw(vertices, states);
    }
};

#endif // BOARD_H
