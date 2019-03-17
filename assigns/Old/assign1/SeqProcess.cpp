/*****************************************************************
// FILE:      SeqProcess.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  
// PURPOSE:   
*****************************************************************/

#include "MainProcess.h"

//counts for table excluding dashes
void MainProcess::specCount(int* pointer, string &seq1, string &seq2, string &key, unsigned int i)
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
string MainProcess::getSequence(string data)
{
	bool flag = false;
	string seq;
	
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	
	for(unsigned int i = 0; i < data.length(); i++)
	{
		if(data.substr(i,1) == "-" || data.substr(i,1) == "+")
		{
			if(flag)
				break;
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
void MainProcess::counter(int* count, string &seq1, string &seq2, unsigned int i)
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
void MainProcess::gapCount(map<int,int> &gapMap, string &seq1, string &seq2, string dash)
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
void MainProcess::print(double &subRate, double &titv, double &gapRate)
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
	cout << "Gap Length\tGap Count\tGap Frequency\n";
	for(it = gapMap.begin(); it != gapMap.end(); ++it)
	{
		cout << it->first << "\t" << it->second << "\t" << (double(it->second)/double(gap))*100 << "%" ;
		cout << endl;
	}
	cout << endl;
}
