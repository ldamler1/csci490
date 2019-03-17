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
		int cnt;
		int match, mismatch, gap;
	public:
		MainProcess();
		void mainCall(string, string);
		string getSequenceMaf(string, int &);
		/*void specCount(int*, string &, string &, string &, unsigned int);
		void counter(int*, string &, string &, unsigned int);
		string getSequenceTrue(string);
		void gapCount(map<int,int> &, string &, string &, string);
		void print(double &, double &, double &);*/
};

#endif
