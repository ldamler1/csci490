/*
 * MainProcess.h
 *
 *  Created on: Nov 5, 2018
 *      Author: Anon
 */

#ifndef MAINPROCESS_H_
#define MAINPROCESS_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <cstddef>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define cPath "C0";
const int c = 0;

using namespace std;

struct Sequence
{
	size_t seqStart;
	string seq;
};
struct Avg
{
	string parms;
	string species;
	double sens;
	double spec;
};

class MainProcess
{
	private:
		vector<Sequence> trueHuman;
		vector<Sequence> trueOther;
		vector<Sequence> mafHuman;
		vector<Sequence> mafOther;
		vector<pair<double,double>> totals;
		vector<double> t;
		vector<double> sens;
		vector<double> spec;
	public:
		MainProcess();
		~MainProcess();
		void mainCall(string, string);
		void getSequenceMaf(string, vector<Sequence> &);
		void adjustInversion(vector<Sequence> &, vector<Sequence> &, vector<Sequence> &, vector<Sequence> &);
		size_t getGenomeSize(string &);
		size_t getSeqSize(string &);
		size_t getStartPos(string &);
		string searchString(string);
		void trueProcess(vector<Sequence> &, vector<Sequence> &, vector<double> &, size_t &);
		void mafProcess(vector<Sequence> &, vector<Sequence> &, vector<double> &t, vector<pair<double,double>> &);
		size_t getArrSize(vector<Sequence> &, vector<Sequence> &);
		void getTrueHelper(string &, string &, vector<Sequence> &, vector<Sequence> &);
		void getMafHelper(string &, vector<Sequence> &, vector<Sequence> &);
		void clear();
		void clearVec();
		void print();
		void stdProcess();
		void processSTDFile(vector<Avg> &, string);
		double standardDeviation(vector<double> &, double &);
		int getdir (string, vector<string> &);
		string getVal(string, string);
		void processVecT1_2(vector<Avg> &, vector<Avg> &, vector<Avg> &,
							vector<Avg> &, vector<Avg> &, vector<Avg> &,
							vector<string> &);
		void processVecT0(vector<Avg> &, vector<Avg> &, vector<Avg> &,
						  vector<Avg> &, vector<Avg> &, vector<Avg> &,
						  vector<string> &);
		void getMax(vector<Avg> &);
};

#endif /* MAINPROCESS_H_ */
