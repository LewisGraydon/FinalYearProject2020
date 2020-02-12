#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>

// To work on Uni labs, output directory needs to be C:\Users\s6021534\source\ at home it is C:\Users\lewis\source\

int main()
{

	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopResolution, "LG Snake Artefact", sf::Style::Default);

	GameManager gm(desktopResolution);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();

			case sf::Event::KeyReleased:

				switch (gm.gameState)
				{

				case gm.eMainMenu:
				
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						gm.getMainMenu().NavigateUp();
						break;

					case sf::Keyboard::Down:
						gm.getMainMenu().NavigateDown();
						break;

					case sf::Keyboard::Return:

						switch (gm.getMainMenu().getSelectedIndex())
						{
						case 0:
							//Play button pressed
							gm.SetupGameWorld(true);
							break;

						case 1:
							//AI Play button pressed
							gm.SetupGameWorld(false);
							break;

						case 2:
							//Exit button pressed					
							window.close();
							break;

						default:
							break;
						}
						break;

					default:
						break;
					}

				case gm.eNormalPlayMode:
				

				case gm.eAIPlayMode:

					switch (event.key.code)
					{
					case sf::Keyboard::Escape:
						gm.SetupMainMenu();
					}
					break;

				default:
					break;

				}		
			}		
		}

		window.clear();

		//Draw calls

		switch (gm.gameState)
		{
		case gm.eMainMenu:

			gm.DrawMainMenu(window);

			break;

		case gm.eNormalPlayMode:

			gm.DrawGameWorld(window);

			break;

		case gm.eAIPlayMode:

			gm.DrawGameWorld(window);

			break;
		}
		
		window.display();
	}

	return 0;
}