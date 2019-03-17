#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

class MainProcess
{
	private:
		int* ptrA;
		int* ptrC;
		int* ptrG;
		int* ptrT;
		int* transPtr;
		int cnt, sequences;
		int match, mismatch, gap;
		string a,c,g,t,dash;
		double subRate, gapRate, titv;
		map <int,int> gapMap;
	public:
		MainProcess();
		void mainCall(string);
		void specCount(int*, string &, string &, string &, unsigned int);
		void counter(int*, string &, string &, unsigned int);
		string getSequence(string);
		void gapCount(map<int,int> &, string &, string &, string);
		void print(double &, double &, double &);
};

#endif
