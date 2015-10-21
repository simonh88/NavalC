#include "Board.h"
#include <cstdlib>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;


Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}

std::vector<std::vector<int> > Board::newBoard()
{
    std::vector<int> row(10, 0);
    std::vector<std::vector<int> > myNewBoard(10, row);
    //cout << endl << "NewBoard : " << myNewBoard[1][1] << endl;
    return myNewBoard;
}
void Board::printCheckerboard()
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

void Board::updateCheckerboard (const std::vector<std::vector<int> > & dataMap)
{
    realCheckerboard = dataMap;
}


bool Board::loadTileMap(const std::string& tileset, sf::Vector2u tileSize,
unsigned int width, unsigned int height)
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
            int tileNumber = realCheckerboard[j][i];

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


void Board::setBoard(int x, int y, int value)
{
	this->realCheckerboard[x][y] = value;
}

int Board::getBoard(int x, int y)
{
	return this->realCheckerboard[x][y];
}
