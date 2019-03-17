#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <cstddef>
#include <vector>

using namespace std;

class MainProcess
{
	private:
		vector<double> sens;
		vector<double> spec;
	public:
		MainProcess();
		~MainProcess();
		void mainCall(string, string);
		void getLineCount(string &, unsigned int &);
		string getSequenceMaf(string, size_t &);
		double* trueProcess(string &, string &, size_t &);
		double* mafProcess(string*, string*, size_t*, size_t*, double*, unsigned int);
		void clear();
		void print();
};

#endif
