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
        void setBoard(int x, int y, int value);
        int getBoard(int x, int y);
        std::vector<std::vector<int> > getCheckerboard();
        std::vector<int> nbBateaux(std::vector<std::vector<int> > checkerBoard);
        void printNbBateaux();
        void printBateaux(std::vector<int> bateaux);
        std::string sBateaux(std::vector<int> bateaux);
        std::string intToString (int a);
    private:
        std::vector<std::vector<int> > realCheckerboard;
        int nbBoat;
        sf::VertexArray vertices;
        sf::Texture myTileset;

    /** Plus d'infos : http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array-fr.php **/
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();
        states.texture = &myTileset;
        target.draw(vertices, states);
    }
};

#endif // BOARD_H
