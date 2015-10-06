#include "getTxt.h"

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

getTxt::getTxt()
{

}
getTxt::~getTxt()
{

}
// test if the file is readable or not
// return
bool getTxt::is_readable(const std::string & fileName)
{
    std::ifstream file(fileName.c_str());
    return !file.fail();
}
// Print the contents of the .txt
void getTxt::read(const std::string & fileName)
{
    std::ifstream file( fileName.c_str() );
    char charTemp;
    while ( file.get( charTemp ) )
    {
        cout << charTemp;
    }
    cout << endl;
}

void getTxt::Test()
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
void getTxt::fillCheckerboard(const std::string & fileName)
{
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
            else if (tmp == ' ')
            {
                currentPos++;
            }
            else
            {
                //cout << tmp << endl;
                if (tmp == '0')
                {
                    dataMap[i][j] = 0; //MER
                }
                if (tmp == '1')
                {
                    dataMap[i][j] = 1; //CAILLOU
                }
                    //cout << " pos(" << i << ":" << j << ") "<< dataMap[i][j];
                    if (j<10)
                    {
                        j++;
                    }
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

char getTxt::readAChar(const std::string & fileName, int pos)
{
    std::ifstream file( fileName.c_str() );
    file.seekg(pos);
    char charTemp;
    file.get( charTemp);
    cout << endl << "position : " << pos << " valeur : " << charTemp;
    return charTemp;
}

int getTxt::leaveAligne(const std::string & fileName)
{
    int myCurrentPos(0);
    std::string tmp;
    std::ifstream file( fileName.c_str() );
    std::getline(file, tmp);
    myCurrentPos = file.tellg();
    return myCurrentPos;
}

void getTxt::printCheckerboard()
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
