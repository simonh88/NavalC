#include "GetTxt.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
/*Constructeur utilisant la surcharge pour initialiser notre board à 0
 * et le nombre de cailloux à 0
 */
GetTxt::GetTxt() : row(10, 0), dataMap(10, row), rock(0)
{

}
GetTxt::~GetTxt()
{

}

unsigned int GetTxt::getNbRock()
{
    return rock;
}

// test if the file is readable or not
// return
bool GetTxt::is_readable(const std::string & fileName)
{
    std::ifstream file(fileName.c_str());
    return !file.fail();
}
// Print the contents of the .txt
void GetTxt::read(const std::string & fileName)
{
    std::ifstream file( fileName.c_str() );
    char charTemp;
    while ( file.get( charTemp ) )
    {
        cout << charTemp;
    }
    cout << endl;
}
//Affiche le fichier en entier
void GetTxt::Test()
{
    if ( is_readable( "config.txt" ) )
    {
        read("config.txt");
    }
    else
    {
        cout << "Le Fichier inexistant ou non lisible.\n";
    }
}
void GetTxt::fillCheckerboard(const std::string & fileName)
{

    //bool fichier_mal_ecrit_voir_readme(false);
    char tmp;
    int currentPos(0);
    bool flag(false);
    int counter(0);
    int i(0),j(0);
    if (is_readable( fileName.c_str() ) )
    {
        do
        {
            tmp = readAChar(fileName.c_str(), currentPos);
            /*fichier_mal_ecrit_voir_readme = (tmp == '#' || tmp == '0' ||tmp == '1' || tmp == '=' ||
            tmp == '^' || tmp == 'v' || tmp == '|' || tmp == '<' || tmp == '>');
            assert(fichier_mal_ecrit_voir_readme);
            cout << tmp << endl;
            */
            if (tmp == '#')
            {
                //cout << "Pas intéressant" << endl;
                currentPos = leaveAligne(fileName.c_str());
                counter++;
                //cout << tmp << endl;
                if (counter == 2)
                { // On a fini de remplir le tab
                    flag = true;
                }
            }
            else if (tmp == ' ' || tmp == '\n')
            {
                currentPos++;
            }
            else
            {
                //cout << tmp << endl;
                if (tmp == '0')
                    dataMap[i][j] = 0; //MER
                if (tmp == '1')
                {
                    rock ++;
                    dataMap[i][j] = 1; //CAILLOU
                }
                if ((tmp == '=')||(tmp == '<')||(tmp == '>')) // boat flat
                    dataMap[i][j] = 2;
                if ((tmp == '|')||(tmp == '^')||(tmp == 'v')) // boat top
                    dataMap[i][j] = 3;
                //cout << " pos(" << i << ":" << j << ") "<< dataMap[i][j];

                if (j<9)
                    j++;
                else
                {
                    j = 0;
                    i++;
                }
                currentPos++;
            }
        }while(!flag);

    }
    else
    {
        cout << "Le Fichier inexistant ou non lisible.\n";
    }
}

char GetTxt::readAChar(const std::string & fileName, int pos)
{
    std::ifstream file( fileName.c_str() );
    file.seekg(pos);
    char charTemp;
    file.get( charTemp);
    //cout << endl << "position : " << pos << " valeur : " << charTemp;
    return charTemp;
}

int GetTxt::leaveAligne(const std::string & fileName)
{
    unsigned int myCurrentPos(0);
    std::string tmp;
    std::ifstream file( fileName.c_str() );
    std::getline(file, tmp);
    myCurrentPos = file.tellg();
    return myCurrentPos;
}


void GetTxt::printCheckerboard()
{
    cout << endl;
    for (int i(0); i<10; i++)
    {
        for (int j(0); j<10; j++)
        {
            cout << " pos(" << i << ":" << j << ") "<< dataMap[i][j] << endl;
        }

    }
}
std::vector<std::vector<int> > GetTxt::getCheckerboard()
{
    return dataMap;
}
