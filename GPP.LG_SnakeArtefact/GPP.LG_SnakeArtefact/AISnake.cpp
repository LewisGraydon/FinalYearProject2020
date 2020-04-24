#include "AISnake.h"

AISnake::AISnake(sf::VideoMode screenSize) : BaseSnakeClass(screenSize)
{
	std::ifstream inputFile;

	inputFile.open("Network100Restarts.txt", std::ios::binary);
	inputFile.read((char*)&net, sizeof(net));
	inputFile.close();

	//TODO - assign the network and such (need to look into this)
}

AISnake::~AISnake()
{
}

void AISnake::Update(sf::Event& event)
{
}
