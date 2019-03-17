#ifndef SEQCALC_H
#define SEQCALC_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

void mainCall(string &);
void specCount(int*, string, string, string, int);
void counter(int*, string, string, string, string, string, string, string, int);
string getSequence(string);
void gapCount(map<int,int> &, string, string, string);
void print(double &, double &, double &, int*, int*, int*, int*, map<int,int> &, int, int);

void mainCall(string file)
{
	ifstream inFile;
	
	map <int,int> gapMap;
	
	string data, seq1, seq2;
	int cnt = 0, sequences = 0;
	
	int* ptrA = new int[4];
	int* ptrC = new int[4];
	int* ptrG = new int[4];
	int* ptrT = new int[4];
	for(int i = 0; i < 4; i++)
		{ptrA[i] = 0; ptrC[i] = 0; ptrG[i] = 0; ptrT[i] = 0;}
	
	//tranitions and transvertions
	int* transPtr = new int[2];
	transPtr[0] = 0;
	transPtr[1] = 0;
	
	string a = "A", c = "C", g = "G", t = "T", dash = "-";
	
	int match = 0, mismatch = 0, gap = 0;;
	double subRate, gapRate, titv;
	
	inFile.open(file);
	if(inFile.fail())
		cout << "ERROR: Failure to open file";
	
	cout << "Thinking...\n";
	while(getline(inFile, data))
	{
		if((data.substr(0,1) == "s") && (cnt%2 == 0))
		{
			seq1 = getSequence(data);
			getline(inFile, data);
			cnt++;
		}
		if((data.substr(0,1) == "s") && (cnt%2 == 1))
		{	
			seq2 = getSequence(data);
			cnt++;
			sequences++;
		}
		
		if(data.substr(0,1) == "s")
		{
			for(unsigned int i = 0; i < seq1.length(); i++)
			{
				specCount(ptrA, seq1, seq2, a, i);
				specCount(ptrC, seq1, seq2, c, i);
				specCount(ptrG, seq1, seq2, g, i);
				specCount(ptrT, seq1, seq2, t, i);
				
				if(seq1.substr(i,1) == seq2.substr(i,1))
					match++;
				else if((seq1.substr(i,1) != dash && seq2.substr(i,1) != dash) && (seq1.substr(i,1) != dash || seq2.substr(i,1) != dash))
				{
					mismatch++;
					counter(transPtr, seq1, seq2, a, c, g, t, dash, i);
				}
			}
		}

		if(data.substr(0,1) == "s")
			gapCount(gapMap, seq1, seq2, dash);

		cnt = 0;
	}

	gap = 0;
	map<int,int>::iterator it = gapMap.begin();
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
		gap += it->second;
	
	subRate = double(mismatch)/(double(mismatch+match));
	gapRate = double(gap)/(double(mismatch+match+gap));
	titv = double(transPtr[0])/double(transPtr[1]);
	
	print(subRate, titv, gapRate, ptrA, ptrC, ptrG, ptrT, gapMap, sequences, gap);
}

//counts for table excluding dashes
void specCount(int* pointer, string seq1, string seq2, string key, int i)
{
	if(seq1.substr(i,1) == key && seq2.substr(i,1) == "A")
		pointer[0]++;
	else if(seq1.substr(i,1) == key && seq2.substr(i,1) == "C")
		pointer[1]++;
	else if(seq1.substr(i,1) == key && seq2.substr(i,1) == "G")
		pointer[2]++;
	else if(seq1.substr(i,1) == key && seq2.substr(i,1) == "T")
		pointer[3]++;
		
}

//Gets sequence and puts in string
string getSequence(string data)
{
	bool flag = false;
	string seq;
	
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	
	for(unsigned int i = 0; i < data.length(); i++)
	{
		if(data.substr(i,1) == "-" || data.substr(i,1) == "+")
		{
			if(flag)
			{
				break;
			}
			else
			{
			for(unsigned int j = i; j < data.length(); j++)
				{
					if(data.substr(j,1) == "A" || data.substr(j,1) == "C" || data.substr(j,1) == "G" || data.substr(j,1) == "T")
					{
						seq = data.substr(j,data.length());
						flag = true;
						break;
					}
					else if(data.substr(j+1,1) == "-")
					{
						seq = data.substr(j+1,data.length());
						flag = true;
						break;
					}
				}
			}
		}
	}
	return seq;		
}

//Checks for transition or transvertion
void counter(int* count, string seq1, string seq2, string a, string c, string g, string t, string dash, int i)
{
	if(seq1.substr(i,1) == a)
	{
		if(seq2.substr(i,1) == g)
			//transitions
			count[0]++;
		else if(seq2.substr(i,1) != dash)
			//transversions
			count[1]++;
	}
	else if(seq1.substr(i,1) == g)
	{
		if(seq2.substr(i,1) == a)
			count[0]++;
		else if(seq2.substr(i,1) != dash)
			count[1]++;
	}
	else if(seq1.substr(i,1) == t)
	{
		if(seq2.substr(i,1) == c)
			count[0]++;
		else if(seq2.substr(i,1) != dash)
			count[1]++;
		}
	else if(seq1.substr(i,1) == c)
	{
		if(seq2.substr(i,1) == t)
			count[0]++;
		else if(seq2.substr(i,1) != dash)
			count[1]++;
	}
}

//counts gap length
void gapCount(map<int,int> &gapMap, string seq1, string seq2, string dash)
{
	string seq = seq1 + " " +seq2;
	int tempGap = 0;
	bool flag = false;
	for(unsigned int i = 0; i < seq.length(); i++)
	{
		if(seq.substr(i,1) == dash)
		{
			tempGap++;	
			if(seq.substr(i+1,1) != dash)
			{
				flag = true;
			}
		}
		if(flag)
		{
			gapMap[tempGap]++;
			tempGap = 0;
			flag = false;
		}
	}
}

//print method
void print(double &subRate, double &titv, double &gapRate, int* ptrA, int* ptrC, int* ptrG, int* ptrT, map<int,int> &gapMap, int sequences, int gap)
{
	cout << "\nStatistics\n----------";
	cout << "\nNumber of Sequence Pairs: " << sequences << endl;
	cout << "\nSubstitution Rate: " << subRate;
	cout << "\nTi/Tv: " << titv;	
	cout << "\nGap Rate: " << gapRate;

	cout << endl << endl;
	
	cout << "\t\tSPECIES 2\n\t |A\tC\tG\tT\n";
	cout << "\t---------------------------\n";
	
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{
			cout << "\tA|";
		}
		cout << ptrA[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{
			cout << "SPECIES C|";
		}
		cout << ptrC[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{
			cout << "   1    G|";
		}
		cout << ptrG[i] << "\t";
	}
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		if(i == 0)
		{
			cout << "\tT|";
		}
		cout << ptrT[i] << "\t";
	}
	cout << endl;
	
	map<int,int>::iterator it = gapMap.begin();
	
	cout << endl;
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
	{
		cout << "Gap Length: " << it->first << "\tGap Count: " << it->second << "\tGap Frequency: " << (double(it->second)/double(gap))*100 << "%" ;
		cout << endl;
	}
	cout << endl;
}

#endif
