
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <cstddef>

using namespace std;

class MainProcess
{
	private:
		int cnt;
		int match, mismatch, gap;
	public:
		MainProcess();
		void mainCall(string, string);
		string getSequenceMaf(string, size_t &);
		/*void specCount(int*, string &, string &, string &, unsigned int);
		void counter(int*, string &, string &, unsigned int);
		string getSequenceTrue(string);
		void gapCount(map<int,int> &, string &, string &, string);
		void print(double &, double &, double &);*/
};


