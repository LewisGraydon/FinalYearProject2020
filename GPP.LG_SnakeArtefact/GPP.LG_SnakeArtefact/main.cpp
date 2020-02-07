#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>

int main()
{

	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopResolution, "LG Snake Artefact", sf::Style::Default);

	GameManager gm(desktopResolution);
	gm.SetupMainMenu();

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

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
						break;

					case 1:
						//AI Play button pressed
						break;

					case 2:
						//Exit button pressed
						window.close();
						break;
					}

				default:
					break;
				}		
			}		
		}

		window.clear();

		//Draw calls
		gm.DrawMainMenu(window);

		window.display();
	}

	return 0;
}