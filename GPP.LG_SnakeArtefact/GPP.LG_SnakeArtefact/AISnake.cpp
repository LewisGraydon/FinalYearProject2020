#include "AISnake.h"

AISnake::AISnake(sf::VideoMode screenSize, sf::Vector2i minBounds, sf::Vector2i maxBounds) : BaseSnakeClass(screenSize), minGameBounds(minBounds), maxGameBounds(maxBounds)
{
	std::ifstream inputFile;
	std::string netString = "";
	std::string tempString = "";
	inputFile.open("SnakeTrainedNetwork1000Restarts.txt", std::ios::in | std::ios::out);

	if (inputFile.good())
	{
		while (inputFile >> tempString)
		{
			netString.append(tempString + " ");
		}
	}

	inputFile.close();
	alglib::mlpunserialize(netString, net);
}

AISnake::~AISnake()
{
}

void AISnake::Update(sf::Event& event, sf::RenderWindow& window, sf::VideoMode screenSize)
{
	BaseSnakeClass::Update(event, window, screenSize);
	DetermineDirection(window, screenSize);
	
	// So, my snake is a bit of an idiot. Hopefully normalising the y value helps make it slightly smarter.
	float direction = y[0] / 3;

	std::cout << "Direction: " << direction << std::endl;
	
	// Since the snake is very stupid when it comes to the boundaries, this should prevent it killing itself.
	float dir = MakeAISmartAgain(direction);
	
	if (dir > -1)
	{
		direction = dir;
	}		
	
	if (direction >= 0 && direction < 0.25)
	{
		if (getDirection() != EDirection::eDown)
		{
			setDirection(BaseSnakeClass::eUp);
		}
	}

	else if (direction >= 0.25 && direction < 0.5)
	{
		if (getDirection() != EDirection::eUp)
		{
			setDirection(EDirection::eDown);
		}
	}

	else if (direction >= 0.5 && direction < 0.75)
	{
		if (getDirection() != EDirection::eRight)
		{
			setDirection(EDirection::eLeft);
		}
	}

	else if (direction >= 0.75 && direction <= 1.0)
	{
		if (getDirection() != EDirection::eLeft)
		{
			setDirection(EDirection::eRight);
		}
	}

	std::cout << " New Direction: " << direction << std::endl;
}

void AISnake::DetermineDirection(sf::RenderWindow& window, sf::VideoMode screenSize)
{
	// on update we want the snake to make a decision on which direction to go in. To that extent, we will take the 400 inputs on the board (the 20x20) and pass that into mlpprocess(network, x, y); where net is
	// the network, x is an array of the 400 inputs and y will be the output direction (that we will check and set the snake direction to be)

	alglib::real_1d_array dataArray;
	dataArray.setlength(NUM_ROWS * NUM_COLUMNS);

	sf::Texture tex;
	tex.create(screenSize.width, screenSize.height);
	tex.update(window);
	sf::Image screenshot = tex.copyToImage();

	for (int y = 0; y < NUM_COLUMNS; y++)
	{
		for (int x = 0; x < NUM_ROWS; x++)
		{
			sf::Color col = screenshot.getPixel(minGameBounds.x + TILE_LENGTH / 2 + x * TILE_LENGTH, minGameBounds.y + TILE_LENGTH / 2 + y * TILE_LENGTH);
			if (col == sf::Color::Blue)
			{
				dataArray[(double)x + (NUM_ROWS * (double)y)] = 0;
			}

			else if (col == sf::Color::Green)
			{
				dataArray[(double)x + (NUM_ROWS * (double)y)] = -1;
			}

			else if (col == sf::Color::Red)
			{
				dataArray[(double)x + (NUM_ROWS * (double)y)] = -2;
			}

			else if (col == sf::Color::Magenta)
			{
				dataArray[(double)x + (NUM_ROWS * (double)y)] = 1;
			}
		}
	}

	alglib::mlpprocess(net, dataArray, y);
	std::cout << y[0] << std::endl;
}

float AISnake::MakeAISmartAgain(float currentDirection)
{
	float direction = -1.0;

	// Top Left
	if (getSnakeSegments()[0].x <= minGameBounds.x && getSnakeSegments()[0].y <= minGameBounds.y && getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH)
	{
		direction = 0.25;
	}

	else if (getSnakeSegments()[0].x <= minGameBounds.x && getSnakeSegments()[0].y <= minGameBounds.y && getSnakeSegments()[0].y == getSnakeSegments()[1].y - TILE_LENGTH)
	{
		direction = 0.75;
	}

	// Bottom Left
	else if (getSnakeSegments()[0].x <= minGameBounds.x && getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH)
	{
		direction = 0.0;
	}

	else if (getSnakeSegments()[0].x <= minGameBounds.x && getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && getSnakeSegments()[0].y == getSnakeSegments()[1].y + TILE_LENGTH)
	{
		direction = 0.75;
	}

	// Bottom Right
	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && getSnakeSegments()[0].x == getSnakeSegments()[1].x + TILE_LENGTH)
	{
		direction = 0.0;
	}

	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && getSnakeSegments()[0].y == getSnakeSegments()[1].y + TILE_LENGTH)
	{
		direction = 0.5;
	}

	// Top Right
	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && getSnakeSegments()[0].y <= minGameBounds.y && getSnakeSegments()[0].x == getSnakeSegments()[1].x + TILE_LENGTH)
	{
		direction = 0.25;
	}

	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && getSnakeSegments()[0].y <= minGameBounds.y && getSnakeSegments()[0].y == getSnakeSegments()[1].y - TILE_LENGTH)
	{
		direction = 0.5;
	}

	// Left
	else if (getSnakeSegments()[0].x <= minGameBounds.x && (getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH || getSnakeSegments()[0].y == getSnakeSegments()[1].y - TILE_LENGTH) && currentDirection >= 0.5 && currentDirection < 0.75)
	{
		direction = 0.0;
	}

	else if (getSnakeSegments()[0].x <= minGameBounds.x && getSnakeSegments()[0].y == getSnakeSegments()[1].y + TILE_LENGTH && direction >= 0.5 && currentDirection < 0.75)
	{
		direction = 0.25;
	}

	// Right
	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && (getSnakeSegments()[0].x == getSnakeSegments()[1].x + TILE_LENGTH || getSnakeSegments()[0].y == getSnakeSegments()[1].y + TILE_LENGTH) && currentDirection >= 0.75)
	{
		direction = 0.25;
	}

	else if (getSnakeSegments()[0].x >= maxGameBounds.x - TILE_LENGTH && getSnakeSegments()[0].y == getSnakeSegments()[1].y - TILE_LENGTH && currentDirection >= 0.75)
	{
		direction = 0.0;
	}

	// Top
	else if (getSnakeSegments()[0].y <= minGameBounds.y && (getSnakeSegments()[0].y == getSnakeSegments()[1].y - TILE_LENGTH || getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH) && currentDirection < 0.25)
	{
		direction = 0.75;
	}

	else if (getSnakeSegments()[0].y <= minGameBounds.y && getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH && currentDirection < 0.25)
	{
		direction = 0.5;
	}

	// Bottom
	else if (getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && (getSnakeSegments()[0].y == getSnakeSegments()[1].y + TILE_LENGTH || getSnakeSegments()[0].x == getSnakeSegments()[1].x - TILE_LENGTH) && currentDirection >= 0.25 && currentDirection < 0.5)
	{
		direction = 0.5;
	}
	
	else if (getSnakeSegments()[0].y >= maxGameBounds.y - TILE_LENGTH && getSnakeSegments()[0].x == getSnakeSegments()[1].x + TILE_LENGTH && currentDirection >= 0.25 && currentDirection < 0.5)
	{
		direction = 0.75;
	}

	return direction;
}
