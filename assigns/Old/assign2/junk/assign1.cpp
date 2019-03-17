/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

#define maf "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.CHIMP.L3000.O300.maf"
#define true "/home/turing/z1761739/csci490/assign2/dataset01/HUMAN.CHIMP.align.true.fa"

int main()
{
	string mafFile = maf;
	string trueFile = true;

	MainProcess call1;
	cout << f1 << endl; 
	call1.mainCall(mafFile, trueFile);

	/*MainProcess call2;
	cout << f2 << endl;
	call2.mainCall(f2);*/

	return 0;
}

