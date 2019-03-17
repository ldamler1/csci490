/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

#define true1 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.CHIMP.align.true.fa"
#define true2 "/home/turing/z1761739/csci490/assign2/dataset02/HUMAN.CHIMP.align.true.fa"
#define true3 "/home/turing/z1761739/csci490/assign2/dataset03/HUMAN.CHIMP.align.true.fa"
#define true4 "/home/turing/z1761739/csci490/assign2/dataset04/HUMAN.CHIMP.align.true.fa"
#define true5 "/home/turing/z1761739/csci490/assign2/dataset05/HUMAN.CHIMP.align.true.fa"
#define true6 "/home/turing/z1761739/csci490/assign2/dataset06/HUMAN.CHIMP.align.true.fa"
#define true7 "/home/turing/z1761739/csci490/assign2/dataset07/HUMAN.CHIMP.align.true.fa"
#define true8 "/home/turing/z1761739/csci490/assign2/dataset08/HUMAN.CHIMP.align.true.fa"
#define true9 "/home/turing/z1761739/csci490/assign2/dataset09/HUMAN.CHIMP.align.true.fa"
#define true10 "/home/turing/z1761739/csci490/assign2/dataset10/HUMAN.CHIMP.align.true.fa"
#define maf1 "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.CHIMP.L3000.O300.maf"
#define maf2 "/home/turing/z1761739/csci490/assign2/dataset02/HUMAN.CHIMP.L3000.O300.maf"
#define maf3 "/home/turing/z1761739/csci490/assign2/dataset03/HUMAN.CHIMP.L3000.O300.maf"
#define maf4 "/home/turing/z1761739/csci490/assign2/dataset04/HUMAN.CHIMP.L3000.O300.maf"
#define maf5 "/home/turing/z1761739/csci490/assign2/dataset05/HUMAN.CHIMP.L3000.O300.maf"
#define maf6 "/home/turing/z1761739/csci490/assign2/dataset06/HUMAN.CHIMP.L3000.O300.maf"
#define maf7 "/home/turing/z1761739/csci490/assign2/dataset07/HUMAN.CHIMP.L3000.O300.maf"
#define maf8 "/home/turing/z1761739/csci490/assign2/dataset08/HUMAN.CHIMP.L3000.O300.maf"
#define maf9 "/home/turing/z1761739/csci490/assign2/dataset09/HUMAN.CHIMP.L3000.O300.maf"
#define maf10 "/home/turing/z1761739/csci490/assign2/dataset10/HUMAN.CHIMP.L3000.O300.maf"

int main()
{
	string trueFile;
	string mafFile;
	
	MainProcess call1;
	//cout << trueFile << endl << mafFile << endl;
	
	trueFile = true1;
	mafFile = maf1;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true2;
	mafFile = maf2;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true3;
	mafFile = maf3;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true4;
	mafFile = maf4;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true5;
	mafFile = maf5;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true6;
	mafFile = maf6;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true7;
	mafFile = maf7;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true8;
	mafFile = maf8;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true9;
	mafFile = maf9;
	call1.mainCall(mafFile, trueFile);
	
	trueFile = true10;
	mafFile = maf10;
	call1.mainCall(mafFile, trueFile);
	
	call1.print();
	call1.clear();

	return 0;
}

