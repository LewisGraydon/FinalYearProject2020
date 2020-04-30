#include "AISnake.h"

AISnake::AISnake(sf::VideoMode screenSize, sf::Vector2i minBounds, sf::Vector2i maxBounds) : BaseSnakeClass(screenSize), minGameBounds(minBounds), maxGameBounds(maxBounds)
{
	std::ifstream inputFile;

	//TODO - assign the network and such (need to look into this)
	
	inputFile.open("Network100Restarts", std::ios::binary);

	unsigned long long beginning;
	unsigned long long end;

	beginning = inputFile.tellg();
	inputFile.seekg(0, std::ios::end);
	end = inputFile.tellg();

	std::ifstream::pos_type size = (sizeof(end) - sizeof(beginning));
	alglib::multilayerperceptron* memblock = new alglib::multilayerperceptron;

	inputFile.seekg(0, std::ios::beg);
	inputFile.read((char*)&memblock, size);
	inputFile.close();

	net = *memblock;
}

AISnake::~AISnake()
{
}

void AISnake::Update(sf::Event& event, sf::RenderWindow& window, sf::VideoMode screenSize)
{
	BaseSnakeClass::Update(event, window, screenSize);
	DetermineDirection(window, screenSize);
	
	int directionInt = y[0];

	printf("Resulting direction is: " + directionInt);

	switch (directionInt)
	{
		case 0:
			setDirection(EDirection::eUp);
			break;

		case 1:
			setDirection(EDirection::eDown);
			break;

		case 2:
			setDirection(EDirection::eLeft);
			break;

		case 3:
			setDirection(EDirection::eRight);
			break;

		default:
			break;
	}
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
				dataArray[x + NUM_ROWS * y] = 0;
			}

			if (col == sf::Color::Green || col == sf::Color::Red)
			{
				dataArray[x + NUM_ROWS * y] = -1;
			}

			if (col == sf::Color::Magenta)
			{
				dataArray[x + NUM_ROWS * y] = 1;
			}
		}
	}

	alglib::mlpprocess(net, dataArray, y);

	//next time mark the head of the snake with a different number (as it's the highest priority)
}
