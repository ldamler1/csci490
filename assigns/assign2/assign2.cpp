/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

int main()
{
	string file = "~/csci490/assign2/DOG_L2000_O300.txt";
	string buff;
	vector<string> mafFile;
	vector<string> trueFile;
	int i = 0;
	
	ifstream inFile;
	inFile.open(file);
	if(inFile.fail())
		cout << "ERROR: Failure to open MAF";
		
	while(getline(inFile, buff))
	{
		mafFile.push_back(buff);
		getline(inFile, buff);
		trueFile.push_back(buff);
		i++;
	}

	for(unsigned int i = 0; i < mafFile.size(); i++)
	{
		cout << i << " " << mafFile[i] << endl << trueFile[i] << endl;
	}
	
	MainProcess call1;
	//cout << trueFile << endl << mafFile << endl;
	
	call1.mainCall(mafFile[0], trueFile[0]);

	call1.mainCall(mafFile[1], trueFile[1]);
	
	call1.mainCall(mafFile[2], trueFile[2]);
	
	call1.mainCall(mafFile[3], trueFile[3]);
	
	call1.mainCall(mafFile[4], trueFile[4]);
	
	call1.mainCall(mafFile[5], trueFile[5]);
	
	call1.mainCall(mafFile[6], trueFile[6]);
	
	call1.mainCall(mafFile[7], trueFile[7]);
	
	call1.mainCall(mafFile[8], trueFile[8]);
	
	call1.mainCall(mafFile[9], trueFile[9]);

	call1.print();
	call1.clear();

	return 0;
}

