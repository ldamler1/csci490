/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

#define file1 "/home/turing/mhou/csci652fall2018/data/human.chr22.chimp.maf"
#define file2 "/home/turing/mhou/csci652fall2018/data/human.chr22.mouse.maf"

int main()
{
	string f1 = file1;
	string f2 = file2;

	MainProcess call1;
	cout << f1 << endl; 
	call1.mainCall(f1);

	MainProcess call2;
	cout << f2 << endl;
	call2.mainCall(f2);

	return 0;
}

