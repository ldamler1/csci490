#include "MainProcess.h"

MainProcess::MainProcess()
{
	match = 0, mismatch = 0, gap = 0;
	cnt = 0;
}

void MainProcess::mainCall(string fileMaf, string fileTrue)
{
	ifstream inFileMaf;
	ifstream inFileTrue;
	
	size_t seqStartHuman = 0, seqStartOther = 0;
	
	string dataMaf, dataTrue;
	string mafHuman, mafOther;
	string trueHuman, trueOther;
	//string* mafSeq = new string[2];
	//string* trueSeq = new string[2];
	
	inFileMaf.open(fileMaf);
	inFileTrue.open(fileTrue);
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
			cout << ">MAF Human " << seqStartHuman << endl  << mafHuman << endl;
			getline(inFileMaf, dataMaf);
			cnt++;
		}
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 1))
		{
			mafOther = getSequenceMaf(dataMaf, seqStartOther);
			cout << ">MAF Other " << seqStartOther << endl  << mafOther << endl;
			cnt++;
		}
		cnt = 0;
	}
	
	//GET TRUE
	while(getline(inFileTrue, dataTrue))
	{
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 0))
		{
			getline(inFileTrue, dataTrue);
			trueHuman = dataTrue;
			cout << ">TRUE Human\n" << trueHuman << endl;
			getline(inFileTrue, dataTrue);
			cnt++;
		}
		if((dataTrue.substr(0,1) == ">")  && (cnt%2 == 1))
		{
			getline(inFileTrue, dataTrue);
			trueOther = dataTrue;
			cout << ">TRUE Other\n" << trueOther << endl;
			cnt++;
		}
		cnt = 0;
	}

	inFileMaf.close();
	inFileTrue.close();

	/*gap = 0;
	map<int,int>::iterator it = gapMap.begin();
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
		gap += it->second;
	
	subRate = double(mismatch)/(double(mismatch+match));
	gapRate = double(gap)/(double(mismatch+match+gap));
	titv = double(transPtr[0])/double(transPtr[1]);
	
	print(subRate, titv, gapRate);*/
}
