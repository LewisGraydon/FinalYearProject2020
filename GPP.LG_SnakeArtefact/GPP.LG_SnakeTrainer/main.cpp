#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ExternalSources/ALGLib-3.16.0/dataanalysis.h"
#include "ExternalSources/ALGLib-3.16.0/stdafx.h"

#include <fstream>

int main()
{
	alglib::mlptrainer trn;
	alglib::mlpcreatetrainer(400, 1, trn);

	alglib::real_2d_array xy;	// Okay, this should be the inputs from the data set. I.e. the first array will be the first data set, ending with a number
																		// between 1 and 3 as well as a ; on the end which will be used to tell the program to use next line.
	xy.setlength(10015, 401);

	std::ifstream inFile("outputData.txt", std::ios::in);
	
	int count = 0;
	int columnCount = 0;

	std::string line;
	while (std::getline(inFile, line, ','))
	{
		std::cout << "Row Count: " << count << ", Column Count:" << columnCount << ", The value is: " << std::stof(line) << std::endl;

		xy(count, columnCount) = std::stof(line);
		columnCount++;

		if (columnCount > 400)
		{
			if (count > 10014)
			{
				break;
			}

			columnCount = 0;
			count++;
		}	
	}

	inFile.close();

	alglib::mlpsetdataset(trn, xy, 4);

	double stoppingCriteria = 0.000;
	alglib::ae_int_t maxNumberOfIterations = 100;
	alglib::mlpsetdecay(trn, 0.01);
	alglib::mlpsetcond(trn, stoppingCriteria, maxNumberOfIterations);

	alglib::multilayerperceptron net;
	alglib::mlpreport rep;

	alglib::mlpcreate1(400, 270, 1, net); // paramaters = { number inputs, number hidden neurons, number outputs, output network}; // Number of hidden neurons = ~2/3 input layers + output layers.
	alglib::mlptrainnetwork(trn, net, 100, rep); // parameters = { trainer object, network, number of restarts, report};

	// Writing the network to a file?

	std::ifstream::pos_type size = sizeof(net);
	alglib::multilayerperceptron* memblock;
	memblock = &net;

	std::ofstream outputData;
	outputData.open("Network100Restarts", std::ios::binary);
	
	if (outputData.good())
	{
		outputData.seekp(0, std::ios::beg);
		outputData.write((char*)&memblock, size);
		outputData.close();
	}

	return 0;
}