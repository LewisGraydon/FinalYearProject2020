#include "PlayerSnake.h"

PlayerSnake::PlayerSnake(sf::VideoMode screenSize) : BaseSnakeClass(screenSize)
{

}

PlayerSnake::~PlayerSnake()
{

}

void PlayerSnake::setDirection(EDirection newDirection)
{
	BaseSnakeClass::setDirection(newDirection);
}

void PlayerSnake::Update(sf::Event& event)
{
	BaseSnakeClass::Update(event);
	EDirection dir = BaseSnakeClass::getDirection();

	switch (event.key.code)
	{
	case sf::Keyboard::Up:

		if (dir != BaseSnakeClass::eDown && dir != BaseSnakeClass::eNone)
		{
			setDirection(BaseSnakeClass::eUp);
		}
		break;

	case sf::Keyboard::Down:

		if (dir != BaseSnakeClass::eUp)
		{
			setDirection(BaseSnakeClass::eDown);
		}
		break;

	case sf::Keyboard::Left:

		if (dir != BaseSnakeClass::eRight)
		{
			setDirection(BaseSnakeClass::eLeft);
		}
		break;

	case sf::Keyboard::Right:

		if (dir != BaseSnakeClass::eLeft)
		{
			setDirection(BaseSnakeClass::eRight);
		}
		break;

	default:
		break;
	}
}