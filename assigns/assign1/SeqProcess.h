#ifndef SEQPROCESS_H
#define SEQPROCESS_H

#include "MainProcess.h"
		
class SeqProcess
{
	public:
		SeqProcess();
		void specCount(int*, string &, string &, string &, int);
		void counter(int*, string &, string &, string, string, string, string, string, int);
		string getSequence(string &);
		void gapCount(map<int,int> &, string &, string &, string);
		void print(double &, double &, double &, int*, int*, int*, int*, map<int,int> &, int, int);
};

#endif
