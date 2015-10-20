#ifndef GETTXT_H
#define GETTXT_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

class GetTxt
{
    public:
    GetTxt();
    virtual ~GetTxt();

    unsigned int getNbRock();
    bool is_readable(const std::string & fileName);
    void read(const std::string & file);
    void Test();
    void fillCheckerboard(const std::string & fileName);
    std::vector<std::vector<int> > getCheckerboard();
    char readAChar(const std::string & fileName, int pos);
    int leaveAligne(const std::string & fileName);
    //Just for check
    void printCheckerboard();
    private:
    std::vector<int> row;
    std::vector<std::vector<int> > dataMap;
    unsigned int rock;

};

#endif // GETTXT_H
