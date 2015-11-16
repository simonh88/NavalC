#include "Game.h"


using std::cout;
using std::endl;


/*Constructeur utilisant la surcharge pour init pos et les deux booleens */
Game::Game() : pos(0), continuingStartMenu(true), placementMenu(false), difficultyMenu(false)
{
	maRecup.fillCheckerboard("config.txt");
	nbRock = maRecup.getNbRock();

	moi.plat.updateCheckerboard(maRecup.getCheckerboard());
	//moi.plat.updateCheckerboard(moi.plat.newBoard()); // si tu veux un board clean
	moi.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
	moi.plat.setPosition(50, 50);

	ia.plat.updateCheckerboard(ia.plat.newBoard());
	//ia.plat.printCheckerboard();
	ia.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
	ia.plat.setPosition(450, 50);
	ia.setDifficulty(1); // de base facile

	tmp.plat.updateCheckerboard(tmp.plat.newBoard());
	tmp.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
	tmp.plat.setPosition(450, 50);
}
/*Destructor*/
Game::~Game()
{
	//dtor
}

/*Fonction gerant le menu de start */
void Game::startMenu(sf::RenderWindow *window)
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
			// fenêtre fermée
		case sf::Event::Closed:
			window->close();
			break;
			// touche pressée
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (pos == 2)
					pos = 0;
				else
					pos++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (pos == 0)
					pos = 2;
				else
					pos--;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))//"Enter"
			{
				switch (pos)
				{
				case 0:
					continuingStartMenu = false;
					placementMenu = true;
					break;
				case 1:
					//A completer
					continuingStartMenu = false;
					difficultyMenu = true;
					cout << "DIFFICULTY" << endl;
					break;
				}
			}
			break;

		case sf::Event::MouseButtonPressed:
			cout << "position en x souris : " << event.mouseButton.x << endl;
			cout << "position en y souris : " << event.mouseButton.y << endl;
			break;
			// on ne traite pas les autres types d'évènements
		default:
			break;
		}
	}
	window->clear(sf::Color::Black);
	blitText.StartMenuAndDifficulty(window, pos, true);
	blitText.flashingText(window);
	window->display();
}
/* Fonction gérant le niveau de difficulté de l'ia */
void Game::difficultyLoop(sf::RenderWindow *window){
  while (window->pollEvent(event))
	{
    switch (event.type)
		{
		case sf::Event::Closed:
      window->close();
      break;
    case sf::Event::KeyPressed:
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        continuingStartMenu = true;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (pos == 2)
					pos = 0;
				else
					pos++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (pos == 0)
					pos = 2;
				else
					pos--;
			}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))//"Enter"
			{
				switch (pos)
				{
				case 0:
          ia.setDifficulty(1);
          difficultyMenu = false;
          continuingStartMenu = true;
          break;
        case 1:
          ia.setDifficulty(2);
          difficultyMenu = false;
          continuingStartMenu = true;
          break;
        case 2:
          ia.setDifficulty(3);
          difficultyMenu = false;
          continuingStartMenu = true;
          break;
				}
      }
      default:
        break;
    }
  }
  window->clear(sf::Color::Black);
  blitText.StartMenuAndDifficulty(window, pos, false);
	blitText.flashingText(window);
  window->display();
}

/*Fonction gérant le moment ou il faut placer les bateaux*/
void Game::placementLoop(sf::RenderWindow *window)
{
	/* Au cas ou c'est modif (recommencer une partie)*/
	/*if (tmp.plat.getPosition().x != 50)
		tmp.plat.setPosition(50, 150);*/
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				continuingStartMenu = true; // retour au menu
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				ia.placeBateauIA(); // Placement des bateaux de l'ia en secret
				ia.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
				/* TEMPORAIRE IA VS IA
				moi.placeBateauIA();
				moi.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
				*/
				placementMenu = false;
			}
			break;
		default:
			break;
		}
	}
	window->clear(sf::Color::Black);
	blitText.textPlacementLoop(window);
	window->draw(tmp.plat);
	window->display();
}
/*Fonction gérant l'affichage du déroulement de la partie */
void Game::mainLoop(sf::RenderWindow *window)
{
	while (window->pollEvent(event))
	{
		// évènement "fermeture demandée" : on ferme la fenêtre
		/*if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::)
		*/
		switch (event.type)
		{
			// fenêtre fermée
		case sf::Event::Closed:
			window->close();
			break;

			// touche pressée
		case sf::Event::KeyPressed:
			//...
			break;

		case sf::Event::MouseButtonPressed:
			cout << "position en x souris : " << event.mouseButton.x << endl;
			cout << "position en y souris : " << event.mouseButton.y << endl;

			//res = moi.joueurJoue(ia.plat, tmp.plat, event.mouseButton.x, event.mouseButton.y);
			bool res;
			res = moi.joueurJoue(&ia.plat, &tmp.plat, event.mouseButton.x, event.mouseButton.y);

			if (res == true) {
				ia.plat.printCheckerboard();

				this->ia.ordiJoue(&moi.plat);
				tmp.plat.printCheckerboard();
				ia.plat.printBateaux(this->ia.plat.nbBateaux(this->ia.plat.getCheckerboard()));
				this->ia.plat.printNbBateaux();
				moi.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
				tmp.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
				//ia.placeBateauIA();
				//ia.plat.loadTileMap("img/tileSet.png", sf::Vector2u(30, 30), 10, 10);
			   // ia.plat.printCheckerboard();
				//ia.plat.updateCheckerboard(ia.getcheckerBoard());
			}
			break;
			// on ne traite pas les autres types d'évènements
		default:
			break;
		}
	}
	//cout << "nombre de rochers : " << nbRock << endl;
	window->clear(sf::Color::Black);
	blitText.tailleComposants(window);
	blitText.blitStaticText(window);
	blitText.blitStatistics(window);
	window->draw(moi.plat);
	window->draw(tmp.plat);
	//window->draw(ia.plat);
	window->display();
}
/*Fonction gérant le déroulement de A à Z le jeu */
void Game::generalLoop(sf::RenderWindow *window)
{
	//ia.plat.printCheckerboard();
	if (continuingStartMenu)
		startMenu(window);
	else if (placementMenu)
		placementLoop(window);
	else if (difficultyMenu)
    difficultyLoop(window);
  else
		mainLoop(window);
}

