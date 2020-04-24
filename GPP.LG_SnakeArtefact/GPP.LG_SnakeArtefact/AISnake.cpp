#include "AISnake.h"

AISnake::AISnake(sf::VideoMode screenSize) : BaseSnakeClass(screenSize)
{
	std::ifstream inputFile;

	inputFile.open("trainedNetwork100Restarts.txt", std::ios::in);
	inputFile.read((char*)&net, sizeof(net));

	//TODO - assign the network and such (need to look into this)
}

AISnake::~AISnake()
{
}

void AISnake::Update(sf::Event& event)
{
}
