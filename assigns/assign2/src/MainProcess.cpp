#include "MainProcess.h"

MainProcess::MainProcess()
{
}

void MainProcess::mainCall(string fileMaf, string fileTrue)
{
	ifstream inFileMaf;
	ifstream inFileTrue;

	unsigned int lineCount = 0;
	int cnt = 0;

	string dataMaf, dataTrue;
	string trueHuman, trueOther;

	size_t tTotal = 0;

	double sensitivity, specificity;
	double* t;
	double* totals;

	inFileMaf.open(fileMaf);
	inFileTrue.open(fileTrue);
	if(inFileMaf.fail())
		cout << "ERROR: Failure to open " << fileMaf << endl;
	if(inFileTrue.fail())
		cout << "ERROR: Failure to open file " << fileTrue << endl;

	//GET true data
	while(getline(inFileTrue, dataTrue))
	{
		if((dataTrue.substr(0,1) == ">") && (cnt%2 == 0))
		{
			getline(inFileTrue, dataTrue);
			trueHuman = dataTrue;
			getline(inFileTrue, dataTrue);
			cnt++;
		}
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 1))
		{
			getline(inFileTrue, dataTrue);
			trueOther = dataTrue;
			cnt++;
		}
		cnt = 0;
	}

	t = trueProcess(trueHuman, trueOther, tTotal);

	//GET maf data
	getLineCount(fileMaf, lineCount);

	string* mafHuman = new string[lineCount];
	string* mafOther = new string[lineCount];
	unsigned int mafCount = 0;
	size_t* seqStartHuman = new size_t[lineCount];
	size_t* seqStartOther = new size_t[lineCount];

	//TODO place in method, takes keys
	while(getline(inFileMaf, dataMaf) && mafCount < lineCount)
	{
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 0))
		{
			mafHuman[mafCount] = getSequenceMaf(dataMaf, seqStartHuman[mafCount]);
			getline(inFileMaf, dataMaf);
			cnt++;
		}
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 1))
		{
			mafOther[mafCount] = getSequenceMaf(dataMaf, seqStartOther[mafCount]);
			cnt++;
			mafCount++;
		}
		cnt = 0;
	}

	totals = mafProcess(mafHuman, mafOther, seqStartHuman, seqStartOther, t, lineCount);

	sensitivity = totals[0]/double(tTotal);
	specificity = totals[0]/totals[1];

	sens.push_back(sensitivity);
	spec.push_back(specificity);

	inFileMaf.close();
	inFileTrue.close();

	//TODO fix clear method
	//Must make private
	delete[] t;
	delete[] totals;
	delete[] mafHuman;
	delete[] mafOther;
	delete[] seqStartHuman;
	delete[] seqStartOther;
}

MainProcess::~MainProcess()
{
	clear();
}

void MainProcess::clear()
{
	sens.erase(sens.begin(), sens.end());
	spec.erase(spec.begin(), spec.end());

}

void MainProcess::print()
{
	//TODO change file output format
	for(unsigned int i = 0; i < sens.size(); i++)
	{
		cout << sens[i]*100 << "," << spec[i]*100 << endl;
	}
}
