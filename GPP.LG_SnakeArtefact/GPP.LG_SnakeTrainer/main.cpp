#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

int main()
{
	alglib::mlptrainer trn;
	alglib::mlpcreatetrainer(400, 4, trn);

	alglib::real_2d_array xy = "[[0,0,0], [0,0,0], [0,0,0], [0,0,0]]";	// Okay, this should be the inputs from the data set. I.e. the first array will be the first data set, ending with a number
																		// between 1 and 3 as well as a ; on the end which will be used to tell the program to use next line.
	alglib::mlpsetdataset(trn, xy, 4);

	double stoppingCriteria = 0.000;
	alglib::ae_int_t maxNumberOfIterations = 100;
	alglib::mlpsetdecay(trn, 0.01);
	alglib::mlpsetcond(trn, stoppingCriteria, maxNumberOfIterations);

	alglib::multilayerperceptron net;
	alglib::mlpreport rep;

	alglib::mlpcreate1(400, 270, 4, net); // paramaters = { number inputs, number hidden neurons, number outputs, output network}; // Number of hidden neurons = ~2/3 input layers + output layers.
	alglib::mlptrainnetwork(trn, net, 100, rep); // parameters = { trainer object, network, number of restarts, report};

	return 0;
}