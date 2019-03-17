#include "MainProcess.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

//Get block lengths
void MainProcess::getLineCount(string &file, unsigned int &lineCount)
{
	int cnt = 0;

	string dataMaf;

	ifstream inFileMaf;

	inFileMaf.open(file);
	if(inFileMaf.fail())
		cout << "ERROR: Failure to open " << file << endl;

	while(getline(inFileMaf, dataMaf))
	{
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 0))
		{
			lineCount++;
			getline(inFileMaf, dataMaf);
			cnt++;
		}
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 1))
		{
			cnt++;
		}
		cnt = 0;
	}
}

//Gets sequence and puts in string
string MainProcess::getSequenceMaf(string data, size_t &pos)
{
	bool flag = false;
	string seq, tempStr = "";
	int tempStart, tempEnd;

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

	tempStart = data.find_first_of("01234567890");

	for(unsigned int i = tempStart; i < data.length()/2; i++)
	{
		if(iswspace(data[i]))
		{
			tempEnd = i;
			break;
		}

	}

	tempStr = data.substr(tempStart, (tempEnd-tempStart));
	pos = stoi(tempStr);

	return seq;
}

//Processes true alignment files
double* MainProcess::trueProcess(string &human, string &other, size_t &tTotal)
{
	double* t = new double[human.length()];
	size_t pos1 = 0;
	size_t pos2 = 0;

	for(size_t i = 0; i < human.length(); i++)
	{
		if(human[i] != '-')
		{
			if(other[i] != '-')
				t[pos1] = pos2;
			else
			{
				t[pos1] = (pos2-(0.5));
			}
			pos1++;
		}
		if(other[i] != '-')
		{
			pos2++;
		}
	}
	tTotal = pos1;

	return t;
}

//Processes maf alignment files
double* MainProcess::mafProcess(string* human, string* other, size_t* humanStart, size_t* otherStart, double* t, unsigned int lineCount)
{
	size_t cTotal = 0;
	size_t correct = 0;
	double* sensSpec = new double[2];
	for(size_t j = 0; j < lineCount; j++)
	{
		size_t pos1 = humanStart[j];
		size_t pos2 = otherStart[j];
		double p,k,dif;
		int c = 0;

		for(size_t i = 0; i < human[j].length(); i++)
		{
			if(human[j].substr(i,1) != "-")
			{
				p = t[pos1];
				if(other[j].substr(i,1) != "-")
					k = pos2;
				else
					k = pos2-(0.5);
				dif = abs(p-k);
				if(dif <= c)
					correct++;
				pos1++;
				cTotal++;
			}
			if(other[j].substr(i,1) != "-")
				pos2++;

		}
	}

	sensSpec[0] = correct;
	sensSpec[1] = cTotal;
	return sensSpec;
}
