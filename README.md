jeu de bataille navale en C, opposant un joueur à une IA
test
TEST2
http://rogerdudler.github.io/git-guide/index.fr.html -> aide git
sinon "github desktop" (pour windows seulement)

groupe 4 - bataille navale
LEFEBVRE Tristan
HAJEK Simon
RIDOLFI-MATTE Sacha

rendu 19 novembre

pour installer les libs : http://www.sfml-dev.org/tutorials/2.3/start-linux-fr.php



/**************** HELP *****************/
Pour traiter les redimensions : 

L'évènement Resized

L'évènement sf::Event::Resized est déclenché lorsque la fenêtre est redimensionnée, que ce soit par l'utilisateur ou bien programmatiquement avec window.setSize.

Vous pouvez utiliser cet évènement pour ajuster les propriétés de rendu : le viewport si vous utilisez OpenGL directement, ou la vue courante si vous utilisez sfml-graphics.

Le membre associé à cet évènement est event.size, il contient la nouvelle taille de la fenêtre.

if (event.type == sf::Event::Resized)
{
    std::cout << "new width: " << event.size.width << std::endl;
    std::cout << "new height: " << event.size.height << std::endl;
}

