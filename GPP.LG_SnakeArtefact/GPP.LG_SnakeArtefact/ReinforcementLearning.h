#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

class ReinforcementLearning
{
public:

	ReinforcementLearning();
	~ReinforcementLearning();
	
	void Train();

private:

	alglib::mlptrainer trn;
	alglib::multilayerperceptron net;
	alglib::mlpreport rep;
};

