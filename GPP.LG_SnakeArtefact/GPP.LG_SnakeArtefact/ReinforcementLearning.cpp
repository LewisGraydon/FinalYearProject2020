#include "ReinforcementLearning.h"

ReinforcementLearning::ReinforcementLearning()
{
	
}

ReinforcementLearning::~ReinforcementLearning()
{
}

void ReinforcementLearning::Train()
{
	alglib::mlpcreatetrainer(10, 4, trn);

	alglib::real_2d_array xy = "[[1,1,1],[1,2,2],[2,1,2],[2,2,4]]"; // We will read in the values from a file in this format.
	mlpsetdataset(trn, xy, 4);

	double wstep = 0.000f;
	alglib::ae_int_t maxits = 500;
	alglib::mlpsetdecay(trn, 0.01f);
	alglib::mlpsetcond(trn, wstep, maxits);

	alglib::mlpcreate1(10, 5, 4, net);
	alglib::mlptrainnetwork(trn, net, 100, rep); 
}