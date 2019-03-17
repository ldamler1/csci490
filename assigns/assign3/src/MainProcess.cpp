#include "MainProcess.h"

MainProcess::MainProcess()
{
	//TODO handle blank maf files
	//Initialize to 0
}

void MainProcess::mainCall(string fileMaf, string fileTrue)
{
	ifstream inFileMaf;
	ifstream inFileTrue;

	size_t tTotal = 0;

	string dataMaf;

	double sensitivity, specificity;

	string search = searchString(fileMaf);

	getTrueHelper(fileTrue, search, trueHuman, trueOther);
	trueProcess(trueHuman, trueOther, t, tTotal);

	getMafHelper(fileMaf, mafHuman, mafOther);
	mafProcess(mafHuman, mafOther, t, totals);

	sensitivity = totals[0].first/(double(tTotal));

	if(totals[0].second == 0)
		specificity = 0;
	else
		specificity = (totals[0].first)/(totals[0].second);

	sens.push_back(sensitivity);
	spec.push_back(specificity);

	clearVec();
}

MainProcess::~MainProcess()
{
	clear();
}

void MainProcess::clearVec()
{
	mafHuman.clear();
	mafOther.clear();
	trueHuman.clear();
	trueOther.clear();
	totals.clear();
	t.clear();
}

void MainProcess::clear()
{
	sens.clear();
	spec.clear();
	clearVec();
}

void MainProcess::print()
{
	unsigned int i = 0;
	for(i = 0; i < sens.size(); i++)
		cout << sens[i]*100 << "," << spec[i]*100 << endl;
}
