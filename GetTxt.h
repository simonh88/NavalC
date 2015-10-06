#ifndef GETTXT_H
#define GETTXT_H
#include <cstdlib>
#include <string>
#include <iostream>


class GetTxt
{
    public:
    GetTxt();
    virtual ~GetTxt();
    bool is_readable(const std::string & fileName);
    void read(const std::string & file);
    void Test();
    void fillCheckerboard(const std::string & fileName);
    char readAChar(const std::string & fileName, int pos);
    int leaveAligne(const std::string & fileName);
    //Just for check
    void printCheckerboard();
    private:
    int dataMap[10][10];

};

#endif // GETTXT_H
