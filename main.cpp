#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
int main()
{
 
    sf::RenderWindow window(sf::VideoMode(1900, 1080), "Formes");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
    // erreur...
    }
    sf::Text text;

    // choix de la police à utiliser
    text.setFont(font); // font est un sf::Font

    // choix de la chaîne de caractères à afficher
    text.setString("Hello world");

    // choix de la taille des caractères
    text.setCharacterSize(24); // exprimée en pixels, pas en points !

    // choix de la couleur du texte
    text.setColor(sf::Color::Red);

    // choix du style du texte
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
 
    sf::ConvexShape carrer1;
    carrer1.setPointCount(4);
    carrer1.setFillColor(sf::Color::Green);
    carrer1.setOutlineColor(sf::Color::Red);
    carrer1.setOutlineThickness(1);
    
    sf::ConvexShape carrer2;
    carrer2.setPointCount(4);
    carrer2.setFillColor(sf::Color::Green);
    carrer2.setOutlineColor(sf::Color::Red);
    carrer2.setOutlineThickness(1);
    int a = 0;
    sf::ConvexShape carrer3;
    carrer3.setPointCount(4);
    carrer3.setFillColor(sf::Color::Blue);
    carrer3.setOutlineColor(sf::Color::Red);
    carrer3.setOutlineThickness(1);
 
 
    carrer1.setPoint(0,sf::Vector2f(200,200));
    carrer1.setPoint(1,sf::Vector2f(840,200));
    carrer1.setPoint(2,sf::Vector2f(840,840));
    carrer1.setPoint(3,sf::Vector2f(200,840));
    
    carrer2.setPoint(0,sf::Vector2f(1000,200));
    carrer2.setPoint(1,sf::Vector2f(1640,200));
    carrer2.setPoint(2,sf::Vector2f(1640,840));
    carrer2.setPoint(3,sf::Vector2f(1000,840));
    
    carrer3.setPoint(0,sf::Vector2f(200,200));
    carrer3.setPoint(1,sf::Vector2f(264,200));
    carrer3.setPoint(2,sf::Vector2f(264,264));
    carrer3.setPoint(3,sf::Vector2f(200,264));
 
    window.UseVerticalSync(true);
 
    while (window.isOpen()) // Boucle principal
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();
        }
	  a = a +1;
	carrer3.setPoint(2,sf::Vector2f(a,264));
        window.clear(sf::Color::Black);
        window.draw(carrer1);
	window.draw(carrer2);
	window.draw(carrer3);
	window.draw(text);
        window.display();
 
    }
 
    return 0;
}