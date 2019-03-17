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

	double* t;//  = trueProcess(trueHuman, trueOther, tTotal);
	
	double sensitivity, specificity;
	double* totals;
	
	inFileMaf.open(fileMaf);
	inFileTrue.open(fileTrue);
	if(inFileMaf.fail())
		cout << "ERROR: Failure to open MAF";
	if(inFileTrue.fail())
		cout << "ERROR: Failure to open file TRUE";
	
	//cout << "Thinking...\n";
	
	//GET TRUE
	while(getline(inFileTrue, dataTrue))
	{
		if((dataTrue.substr(0,1) == ">") && (cnt%2 == 0))
		{
			getline(inFileTrue, dataTrue);
			trueHuman = dataTrue;
			//cout << ">TRUE Human\n" << trueHuman << endl;
			getline(inFileTrue, dataTrue);
			cnt++;
		}
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 1))
		{
			getline(inFileTrue, dataTrue);
			trueOther = dataTrue;
			//cout << ">TRUE Other\n" << trueOther << endl;
			cnt++;
		}
		cnt = 0;
	}
	
	t = trueProcess(trueHuman, trueOther, tTotal);

	//GET MAF
	
	getLineCount(fileMaf, lineCount);

	string* mafHuman = new string[lineCount];
	string* mafOther = new string[lineCount];
	unsigned int mafCount = 0;
	size_t* seqStartHuman = new size_t[lineCount];
	size_t* seqStartOther = new size_t[lineCount];
	
	//TODO PLACE IN METHOD THAT TAKES KEY
	while(getline(inFileMaf, dataMaf) && mafCount < lineCount)
	{
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 0))
		{
			mafHuman[mafCount] = getSequenceMaf(dataMaf, seqStartHuman[mafCount]);
			//cout << ">MAF Human " << seqStartHuman << endl  << mafHuman << endl;
			getline(inFileMaf, dataMaf);
			cnt++;
		}
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 1))
		{
			mafOther[mafCount] = getSequenceMaf(dataMaf, seqStartOther[mafCount]);
			//cout << ">MAF Other " << seqStartOther << endl  << mafOther << endl;
			cnt++;
			mafCount++;
		}
		cnt = 0;
	}
	
	totals = mafProcess(mafHuman, mafOther, seqStartHuman, seqStartOther, t, lineCount);
	
	/*for(unsigned int i = 0; i < lineCount; i++)
	{
		cout << "Human\n" << mafHuman[i] << endl;
		cout << "Other\n" << mafOther[i] << endl;
	}*/
	
	//cout << "Correct: " << totals[0] << endl;
	//cout << "cTotal: " << totals[1] << endl;
	//cout << "tTotal: " << tTotal << endl;
	
	sensitivity = totals[0]/double(tTotal);
	specificity = totals[0]/totals[1];
	
	sens.push_back(sensitivity);
	spec.push_back(specificity);

	//cout << "Sensitivity: " << sensitivity*100 << "%\n";
	//cout << "Specificity: " << specificity*100 << "%\n";

	inFileMaf.close();
	inFileTrue.close();

	//TODO Make clear method
	//Make t and total private
	delete[] t;
	delete[] totals;

	//TODO make std deviation
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
	for(unsigned int i = 0; i < sens.size(); i++)
	{
		cout << sens[i]*100 << "," << spec[i]*100 << endl;
	}
	/*for(const double &i : sens)
	{
		cout << "Sensitivity: " << i*100 << "%\n";
	}

	for(const double &i : spec)
	{
		cout << "Specificity: " << i*100 << "%\n";
	}*/
}
