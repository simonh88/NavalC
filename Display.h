#ifndef DISPLAY_H
#define DISPLAY_H
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Display
{
    public:
        Display();
        void initCheckerboard (const std::vector<std::vector<int> > & dataMap);
        virtual ~Display();
        void refreshCheckerboard();
        //Just for test
        void printCheckerboard();
        //idem
        void tailleComposants(sf:: RenderWindow *window);

    private:
    std::vector<std::vector<int> > realCheckerboard;

};

#endif // DISPLAY_H
