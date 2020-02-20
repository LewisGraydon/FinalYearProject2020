#include <SFML/Graphics.hpp>
#include "GameManager.h"

// To work on Uni labs, output directory needs to be C:\Users\s6021534\source\ at home it is C:\Users\lewis\source\

int main()
{
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopResolution, "LG Snake Artefact", sf::Style::Fullscreen);

	GameManager gm(desktopResolution);
	
	// In all fairness, this entire block of code can be moved to a runGame function within gameManager.cpp and then all we would do here would be create a gameManager and call runGame on it.
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time timeElapsed = clock.getElapsedTime();

		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();

			case sf::Event::KeyReleased:

				switch (gm.gameState)
				{
				// Main menu navigation controls.
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
							// Play button pressed.
							gm.SetupGameWorld(true);
							break;

						case 1:
							// AI Play button pressed.
							gm.SetupGameWorld(false);
							break;

						case 2:
							// Exit button pressed.					
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

		//Draw calls within each particular state.
		switch (gm.gameState)
		{
		case gm.eMainMenu:

			gm.DrawMainMenu(window);

			break;

		case gm.eNormalPlayMode:

		case gm.eAIPlayMode:

			gm.DrawGameWorld(window);

			// May need to tweak the actual float value for snek speed. 0.1 is normal. Speed up for AI play.
			if (timeElapsed.asSeconds() > 0.1)
			{
				timeElapsed = clock.restart();
				gm.getGameWorld().Update(event);
			}
			
			break;
		}

		window.display();
	}

	return 0;
}