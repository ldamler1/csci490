/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

#define maf1 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.L2000.O300.maf"
#define maf2 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.L3000.O300.maf"
#define maf3 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.L5000.O300.maf"
#define maf4 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.L3000.O200.maf"
#define maf5 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.L3000.O500.maf"
#define true1 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.DOG.align.true.fa"


int main()
{
	string trueFile = true1;
	string mafFile;
	
	mafFile = maf1;
	MainProcess call1;
	cout << mafFile << endl << trueFile << endl; 
	call1.mainCall(mafFile, trueFile);
	cout << endl;
	
	mafFile = maf2;
	MainProcess call2;
	cout << mafFile << endl << trueFile << endl; 
	call2.mainCall(mafFile, trueFile);
	cout << endl;
	
	mafFile = maf3;
	MainProcess call3;
	cout << mafFile << endl << trueFile << endl; 
	call3.mainCall(mafFile, trueFile);
	cout << endl;
	
	mafFile = maf4;
	MainProcess call4;
	cout << mafFile << endl << trueFile << endl; 
	call4.mainCall(mafFile, trueFile);
	cout << endl;
	
	mafFile = maf5;
	MainProcess call5;
	cout << mafFile << endl << trueFile << endl; 
	call5.mainCall(mafFile, trueFile);
	cout << endl;
	
	return 0;
}

