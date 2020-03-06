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

	// Something about sparse matrix may be useful?
	alglib::sparsematrix testDataSet;
	//alglib::sparsecreate(5, 1, testDataSet);
	//alglib::sparseset(testDataSet, 0, 1, 1.0);
};

