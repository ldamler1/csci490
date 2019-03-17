/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:   
*****************************************************************/

#include "SeqCalc.h"

const string file1 = "/home/turing/mhou/csci652fall2018/data/human.chr22.chimp.maf";
const string file2 = "/home/turing/mhou/csci652fall2018/data/human.chr22.mouse.maf";

int main()
{
	cout << file1 << endl; 
	mainCall(file1);

	cout << file2 << endl;
	mainCall(file2);

	return 0;
}

