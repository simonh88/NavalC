#include "getTxt.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
// test if the file is readable or not
// return
bool is_readable( const string & fileName )
{
    ifstream file( file.c_str() );
    return !file.fail();
}
// Print the contents of the .txt
void read( const string & file )
{
    ifstream fichier( file.c_str () );
    char charTemp;
    while ( fichier.get( charTemp ) )
    {
        cout << charTemp;
    }
    cout << endl;
}



