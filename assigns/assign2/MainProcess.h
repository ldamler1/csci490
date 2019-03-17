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
		//size_t gettTotal;
		/*void specCount(int*, string &, string &, string &, unsigned int);
		void counter(int*, string &, string &, unsigned int);
		string getSequenceTrue(string);
		void gapCount(map<int,int> &, string &, string &, string);
		void print(double &, double &, double &);*/
};

#endif
