#include "PlayerSnake.h"

PlayerSnake::PlayerSnake(sf::VideoMode screenSize, sf::Vector2i minBounds, sf::Vector2i maxBounds) : BaseSnakeClass(screenSize), minGameBounds(minBounds), maxGameBounds(maxBounds)
{

}


PlayerSnake::~PlayerSnake()
{

}

void PlayerSnake::setDirection(EDirection newDirection)
{
	BaseSnakeClass::setDirection(newDirection);
}

void PlayerSnake::Update(sf::Event& event, sf::RenderWindow& window, sf::VideoMode screenSize)
{
	BaseSnakeClass::Update(event, window, screenSize);
	EDirection dir = BaseSnakeClass::getDirection();

	// Switch upon the key code itself, and change the direction of the snake to be the key pressed. If the key pressed is opposite to the snake's current direction however, nothing will happen.
	switch (event.key.code)
	{
	case sf::Keyboard::Up:

		if (dir != BaseSnakeClass::eDown && dir != BaseSnakeClass::eNone)
		{
			if (getDirection() != EDirection::eUp)
			{
				setDirection(BaseSnakeClass::eUp);
				SaveData(window, screenSize);
			}
		}
		break;

	case sf::Keyboard::Down:

		if (dir != BaseSnakeClass::eUp)
		{
			if (getDirection() != EDirection::eDown)
			{
				setDirection(BaseSnakeClass::eDown);
				SaveData(window, screenSize);
			}
		}
		break;

	case sf::Keyboard::Left:

		if (dir != BaseSnakeClass::eRight)
		{
			if (getDirection() != EDirection::eLeft)
			{
				setDirection(BaseSnakeClass::eLeft);
				SaveData(window, screenSize);
			}
		}
		break;

	case sf::Keyboard::Right:

		if (dir != BaseSnakeClass::eLeft)
		{
			if (getDirection() != EDirection::eRight)
			{
				setDirection(BaseSnakeClass::eRight);
				SaveData(window, screenSize);
			}
		}
		break;

	default:
		break;
	}
}

void PlayerSnake::SaveData(sf::RenderWindow& window, sf::VideoMode screenSize)
{
	std::fstream outputData;
	outputData.open("SnakeTrainingData.txt", std::ios::in | std::ios::out | std::ios::app);

	if (outputData.good())
	{
		int actionArray[1] = { 0 };
		int dataArray[NUM_ROWS * NUM_COLUMNS] = { };
		sf::Texture tex;
		tex.create(screenSize.width, screenSize.height);
		tex.update(window);
		sf::Image screenshot = tex.copyToImage();

		switch (getDirection())
		{
			case EDirection::eUp:
				actionArray[0] = 0;
				break;

			case EDirection::eDown:
				actionArray[0] = 1;
				break;

			case EDirection::eLeft:
				actionArray[0] = 2;
				break;

			case EDirection::eRight:
				actionArray[0] = 3;
				break;

			default:
				break;
		}
		
		for (int y = 0; y < NUM_COLUMNS; y++)
		{
			for (int x = 0; x < NUM_ROWS; x++)
			{
				sf::Color col = screenshot.getPixel(minGameBounds.x + TILE_LENGTH / 2 + x * TILE_LENGTH, minGameBounds.y + TILE_LENGTH / 2 + y * TILE_LENGTH);
				if (col == sf::Color::Blue)
				{
					dataArray[x + NUM_ROWS * y] = 0;
				}

				else if (col == sf::Color::Green)
				{
					dataArray[x + NUM_ROWS * y] = -1;
				}

				else if (col == sf::Color::Red)
				{
					dataArray[x + NUM_ROWS * y] = -2;
				}

				else if (col == sf::Color::Magenta)
				{
					dataArray[x + NUM_ROWS * y] = 1;
				}
			}
		}

		std::string outputString = "";
		
		for (int count = 0; count < sizeof(dataArray) / sizeof(dataArray[0]); count++)
		{
			outputString.append(std::to_string(dataArray[count]) + ",");
		}

		outputString.append(std::to_string(actionArray[0]) + ",");

		outputData << outputString << std::endl;
		outputData.close();
	}
	else
	{
		std::cerr << "Unable to open file" << std::endl;
	}
}
