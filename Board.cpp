#include "Board.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using std::cout;
using std::endl;

/*Constructeur */
Board::Board()
{
    //ctor
}
/* Destructeur */
Board::~Board()
{
    //dtor
}

int Board::getNbParts(){
  return nbParts;
}
/*Getteur du checkerboard */
std::vector<std::vector<int> > Board::getCheckerboard()
{
    return realCheckerboard;
}

/*Initialisation d'un board tout initialisé à 0
 *Donc tout de l'eau
 *On return ce nouveau board
 */
std::vector<std::vector<int> > Board::newBoard()
{
    std::vector<int> row(10, 0);
    std::vector<std::vector<int> > myNewBoard(10, row);
    //cout << endl << "NewBoard : " << myNewBoard[1][1] << endl;
    return myNewBoard;
}
/*Fonction permettant de convertir un int en string*/
std::string Board::intToString (int a)
{
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

/*Affichage console du checkerboard
 * Pour debugage
 */
void Board::printCheckerboard()
{
    cout << endl;
    for (int i(0); i<10; i++)
    {
        for (int j(0); j<10; j++)
        {
            cout << realCheckerboard[i][j];
        }
        cout << endl;
    }
}
/*Affichage console du tableau de bateau
 * pour debug
 */
void Board::printBateaux(std::vector<int> bateaux)
{

    int sizetab;
    sizetab = bateaux.size();
    //cout << sizetab << endl;
    cout << "{ ";
    for (int i = 0; i<sizetab; i++)
    {
        cout << bateaux[i];
        if (i != sizetab-1)
            cout << ", ";
    }
    cout << "}";
}
std::string Board::sBateaux(std::vector<int> bateaux){
  std::string rep;
  int sizetab;
  sizetab = bateaux.size();
  rep += "{";
  for (int i = 0; i<sizetab; i++){
    rep += intToString(bateaux[i]);
    if(i != sizetab-1) rep += ", ";
  }
  rep += " }";
  return rep;
}

std::string Board::sNbParts(std::vector<int> bateaux){
  int rep, sizetab;
  rep = 0;
  sizetab = bateaux.size();
  for (int i = 0; i<sizetab; i++){
    rep += bateaux[i];
  }
  nbParts = rep;
  return intToString(rep);
}

/*Affichage du nombre de bateaux
 * pour debug
 */
std::string Board::printNbBateaux()
{
    // ce sera actualiser a chaque comptage de bateaux.
    return intToString(nbBoat);
}
/* Comptage du nombre de bateaux d'un board
 * Return un tableau contenant les tailles des bateaux(vector)
 */
std::vector<int> Board::nbBateaux(std::vector<std::vector<int> > checkerBoard)
{
    int tailleHor(0);
    int tab[10] = {0};
    //printCheckerboard();
    std::vector<int> bateaux; //MAX de bateaux 50

    for (int i(0); i<10; i++)
    {
        for (int j(0); j<10; j++)
        {
            if (checkerBoard[i][j] == 2)
                tailleHor++;
            if (checkerBoard[i][j] == 3)
            {
                tab[j] += 1;
            }
            if ((checkerBoard[i][j] == 0 || checkerBoard[i][j] == 1) && tailleHor > 0 )
            {
                bateaux.push_back(tailleHor);
                //cout << bateaux[1] << endl;
                tailleHor = 0;
            }
            /*if ((checkerBoard[i][j] == 0 || checkerBoard[i][j] == 1 || checkerBoard[i][j] == 2) && tailleVer > 0 && j == memCol)
            {
                bateaux.push_back(tailleVer);
                tailleVer = 0;
                memCol = -1;
            }*/
        }
    }
    if(tailleHor>0) // exception quand le bateau touche le coin droit en bas
        bateaux.push_back(tailleHor);
    for (int k(0); k<10; k++)
    {
        if (tab[k]>0)
            bateaux.push_back(tab[k]);
    }
    nbBoat = bateaux.size();
    return bateaux;
}

/*Pour actualiser le private checkerboard et donc actualiser l'affichage
 * En quelques sortes setter du realCheckerboard (moddifieur)
 */
void Board::updateCheckerboard (const std::vector<std::vector<int> > & dataMap)
{
    realCheckerboard = dataMap;
}

/*Chargement du tileset et donc du tilemap
 * Plus d'infos :
 */
/**http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array-fr.php **/
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
    for (unsigned int i = 0; i < width; i++){
        for (unsigned int j = 0; j < height; j++)
        {
            // backup id at this moment for the tile
            int tileNumber = realCheckerboard[j][i];
            //cout << "tileNumber :" << tileNumber << " ";

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
        cout << endl;
    }
    return true;
}

/* Setter d'une seule case du checkerboard */
void Board::setBoard(int x, int y, int value)
{
	this->realCheckerboard[x][y] = value;
}
/* Getter d'une seule case du checkerboard */
int Board::getBoard(int x, int y)
{
    if (x >= 10 || y >= 10 || x <0 || y <0)
        return 10; //ERROR
    else
        return this->realCheckerboard[x][y];
}
