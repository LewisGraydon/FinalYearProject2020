#include <SFML/Graphics.hpp>
#include "GameManager.h"

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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//Draw calls

		gm.DrawMainMenu(window);

		window.display();
	}

	return 0;
}