#include <SFML/Graphics.hpp>

int main()
{
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopResolution, "LG Snake Artefact", sf::Style::Default);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}