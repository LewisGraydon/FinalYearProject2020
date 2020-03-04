#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

#define NUMBER_OF_ACTIONS 4
#define NUMBER_OF_STATES 5

class ReinforcementLearning
{
public:

	ReinforcementLearning();
	~ReinforcementLearning();

	const int iterations = 15;

	int initialStates[NUMBER_OF_ACTIONS] = {0,0,0,0};
	int R[NUMBER_OF_STATES][NUMBER_OF_ACTIONS] = {	{0,0,0,0},
													{0,0,0,0}, 
													{0,0,0,0}, 
													{0,0,0,0}, 
													{0,0,0,0} };

	int QTable[NUMBER_OF_STATES][NUMBER_OF_ACTIONS];
	int currentState;

	void Episode(int initialState);
	void ChooseAction();
	int GetRandomAction(int upperBound, int lowerBound);
	int Maximum(int state, bool returnIndexOnly);
	int Reward(int action);

private:


};

