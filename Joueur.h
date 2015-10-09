#ifndef JOUEUR_H
#define JOUEUR_H
#include <board.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Joueur 
{
    public:
        Joueur();
        virtual ~Joueur();
    protected:
    private:
		Board plateau;
		bool ia; // vrais = ordi, faux = humain
		
};

#endif // JOUEUR_H
