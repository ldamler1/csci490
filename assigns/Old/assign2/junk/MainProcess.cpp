#include "MainProcess.h"

MainProcess::MainProcess()
{
	match = 0, mismatch = 0, gap = 0;
	cnt = 0, sequences = 0;
}

void MainProcess::mainCall(string file1, string file2)
{
	ifstream inFileMaf;
	ifstream inFileTrue;
	
	int seqStartHuman, seqStartOther;
	
	string dataMaf, dataTrue;
	string mafHuman, mafOther;
	stirng trueHuman, trueOther;
	//string* mafSeq = new string[2];
	//string* trueSeq = new string[2];
	
	inFile.open(file);
	if(inFileMaf.fail())
		cout << "ERROR: Failure to open MAF";
	if(inFileTrue.fail())
		cout << "ERROR: Failure to open file TRUE";
	
	cout << "Thinking...\n";
	
	//dataMaf((std::istreambuf_iterator<char>(inFileMaf)), std::istreambuf_iterator<char>());
	//dataTrue((std::istreambuf_iterator<char>(inFileTrue)), std::istreambuf_iterator<char>());
	
	//GET MAF
	//TODO PLACE IN METHOD THAT TAKES KEY
	while(getline(inFileMaf, dataMaf))
	{
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 0))
		{
			
			mafHuman = getSequenceMaf(dataMaf, seqStartHuman);
			cout << mafHuman << endl;
			getline(inFile, dataMaf);
			cnt++;
		}
		if((data.substr(0,1) == "s") && (cnt%2 == 1))
		{
			mafOther = getSequenceMaf(dataMaf, seqStartOther);
			cout << mafOther << endl;
			cnt++;
		}
		cnt = 0;
	}
	
	//GET TRUE
	while(getline(inFileTrue, dataTrue))
	{
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 0))
		{
			getline(inFile, dataTrue);
			trueHuman = dataTrue;
			cout << trueHuman << endl;
			getline(inFile, dataTrue);
		}
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 1))
		{
			getline(inFile, dataTrue);
			trueOther = dataTrue;
			cout << trueOther << endl;
			cnt++;
		}
		cnt = 0;
	}

	/*gap = 0;
	map<int,int>::iterator it = gapMap.begin();
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
		gap += it->second;
	
	subRate = double(mismatch)/(double(mismatch+match));
	gapRate = double(gap)/(double(mismatch+match+gap));
	titv = double(transPtr[0])/double(transPtr[1]);
	
	print(subRate, titv, gapRate);*/
}
