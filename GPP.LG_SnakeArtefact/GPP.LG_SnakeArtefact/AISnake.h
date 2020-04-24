#pragma once
#include "BaseSnakeClass.h"

#include <fstream>
#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

class AISnake : public BaseSnakeClass
{
public:
	AISnake(sf::VideoMode screenSize);
	~AISnake();

	void Update(sf::Event& event);

private:
	alglib::multilayerperceptron net;
};

