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

	// Switch upon the key code itself, and change the direction of the snake to be the key pressed. If the key pressed is opposite to the snake's current direction however, nothing will happen.
	switch (event.key.code)
	{
	case sf::Keyboard::Up:

		if (dir != BaseSnakeClass::eDown && dir != BaseSnakeClass::eNone)
		{
			setDirection(BaseSnakeClass::eUp);
			SaveData("Up");
			
		}
		break;

	case sf::Keyboard::Down:

		if (dir != BaseSnakeClass::eUp)
		{
			setDirection(BaseSnakeClass::eDown);
			SaveData("Down");
		}
		break;

	case sf::Keyboard::Left:

		if (dir != BaseSnakeClass::eRight)
		{
			setDirection(BaseSnakeClass::eLeft);
			SaveData("Left");
		}
		break;

	case sf::Keyboard::Right:

		if (dir != BaseSnakeClass::eLeft)
		{
			setDirection(BaseSnakeClass::eRight);
			SaveData("Right");
		}
		break;

	default:
		break;
	}
}

void PlayerSnake::SaveData(std::string outputString)
{
	std::fstream outputData;
	outputData.open("outputData.txt", std::ios::in | std::ios::out | std::ios::app);

	if (outputData.good())
	{
		outputData << outputString << std::endl;
		outputData.close();
	}
	else
	{
		std::cerr << "Unable to open file" << std::endl;
	}
}
