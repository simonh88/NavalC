#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>


class Display
{
    public:
        Display();
        virtual ~Display();
        void refreshCheckerboard();

    private:
    std::vector<std::vector<int> > realCheckerboard;

};

#endif // DISPLAY_H
