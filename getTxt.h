#ifndef GETTXT_H
#define GETTXT_H
#include <cstdlib>
#include <string>
#include <iostream>


class getTxt
{
    public:
    bool is_readable( const string & fileName );
    void read(const string & file);
    private:
    string fileName;
    const int heigt;
    const int length;
};

#endif // GETTXT_H
