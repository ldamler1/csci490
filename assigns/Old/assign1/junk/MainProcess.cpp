#include "MainProcess.h"

MainProcess::MainProcess()
{
	ptrA = new int[4];
	ptrC = new int[4];
	ptrG = new int[4];
	ptrT = new int[4];
	
	for(int i = 0; i < 4; i++)
		{ptrA[i] = 0; ptrC[i] = 0; ptrG[i] = 0; ptrT[i] = 0;}
	
	//tranitions and transvertions
	transPtr = new int[2];
	transPtr[0] = 0;
	transPtr[1] = 0;
	
	a = "A", c = "C", g = "G", t = "T", dash = "-";
	
	match = 0, mismatch = 0, gap = 0;
	cnt = 0, sequences = 0;
}

void MainProcess::mainCall(string file)
{
	ifstream inFile;
	
	string data, seq1, seq2;
	
	inFile.open(file);
	if(inFile.fail())
		cout << "ERROR: Failure to open file";
	
	cout << "Thinking...\n";
	while(getline(inFile, data))
	{
		if((data.substr(0,1) == "s") && (cnt%2 == 0))
		{
			seq1 = getSequence(data);
			getline(inFile, data);
			cnt++;
		}
		if((data.substr(0,1) == "s") && (cnt%2 == 1))
		{	
			seq2 = getSequence(data);
			cnt++;
			sequences++;
		}

		if(data.substr(0,1) == "s")
		{
			for(unsigned int i = 0; i < seq1.length(); i++)
			{
				specCount(ptrA, seq1, seq2, a, i);
				specCount(ptrC, seq1, seq2, c, i);
				specCount(ptrG, seq1, seq2, g, i);
				specCount(ptrT, seq1, seq2, t, i);
				
				if(seq1.substr(i,1) == seq2.substr(i,1))
					match++;
				else if((seq1.substr(i,1) != dash && seq2.substr(i,1) != dash) && (seq1.substr(i,1) != dash || seq2.substr(i,1) != dash))
				{
					mismatch++;
					counter(transPtr, seq1, seq2, i);
				}
			}
		}

		if(data.substr(0,1) == "s")
			gapCount(gapMap, seq1, seq2, dash);

		cnt = 0;
	}

	gap = 0;
	map<int,int>::iterator it = gapMap.begin();
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
		gap += it->second;
	
	subRate = double(mismatch)/(double(mismatch+match));
	gapRate = double(gap)/(double(mismatch+match+gap));
	titv = double(transPtr[0])/double(transPtr[1]);
	
	print(subRate, titv, gapRate);
}
