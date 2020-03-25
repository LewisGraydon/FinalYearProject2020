#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

int main()
{
	alglib::mlptrainer trn;
	alglib::mlpcreatetrainer(1600, 4, trn);

	alglib::real_2d_array xy = "[[0,0,0], [0,0,0], [0,0,0], [0,0,0]]";	// something?
	alglib::mlpsetdataset(trn, xy, 4);

	double stoppingCriteria = 0.000;
	alglib::ae_int_t maxNumberOfIterations = 100;
	alglib::mlpsetdecay(trn, 0.01);
	alglib::mlpsetcond(trn, stoppingCriteria, maxNumberOfIterations);

	alglib::multilayerperceptron net;
	alglib::mlpreport rep;

	alglib::mlpcreate1(1600, 5, 4, net); // paramaters = { number inputs, number hidden neurons, number outputs, output network};
	alglib::mlptrainnetwork(trn, net, 100, rep); // parameters = { trainer object, network, number of restarts, report};

	return 0;
}