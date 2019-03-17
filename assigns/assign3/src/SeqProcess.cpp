#include "MainProcess.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

//Gets sequence and puts in string
void MainProcess::getSequenceMaf(string data, vector<Sequence> &v)
{
	bool flag = false, check = false;
	string seq;
	size_t pos, seqSize, genomeSize, invPos = 0;
	Sequence tempSeq;

	transform(data.begin(), data.end(), data.begin(), ::toupper);

	size_t numPos = data.find_last_of("0123456789");
	for(size_t i = numPos; i > 0; i--)
	{
		if(data.substr(i,1) == "-")
		{
			check = true;
			break;
		}
	}

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

	if(check)
	{
		pos = getStartPos(data);
		seqSize = getSeqSize(data);
		genomeSize = getGenomeSize(data);
		invPos = genomeSize-(pos+seqSize);

		tempSeq = {invPos, seq};
		v.push_back(tempSeq);
		check = false;
	}
	else
	{
		pos = getStartPos(data);
		tempSeq = {pos, seq};
		v.push_back(tempSeq);
	}

/*
	pos = getStartPos(data);
	tempSeq = {pos, seq};
	v.push_back(tempSeq);
*/
}

size_t MainProcess::getGenomeSize(string &data)
{
	string tempStr = "";
	unsigned int tempStart, tempEnd;
	size_t pos;

	tempEnd = data.find_last_of("0123456789");

	for(unsigned int i = tempEnd; i > 0; i--)
	{
		if(iswspace(data[i]))
		{
			tempStart = i;
			break;
		}
	}

	tempStr = data.substr(tempStart+1, (tempEnd-tempStart));
	pos = stoi(tempStr);

	return pos;
}

size_t MainProcess::getSeqSize(string &data)
{
	string tempStr = "";
	unsigned int tempStart, tempEnd;
	size_t pos;

	tempEnd = data.find_first_of("-");
	tempEnd -= 2;

	for(unsigned int i = tempEnd; i > 0; i--)
	{
		if(iswspace(data[i]))
		{
			tempStart = i;
			break;
		}
	}

	tempStr = data.substr(tempStart+1, (tempEnd-tempStart));
	pos = stoi(tempStr);

	return pos;
}

size_t MainProcess::getStartPos(string &data)
{
	string tempStr = "";
	unsigned int tempStart, tempEnd;
	size_t pos;

	tempStart = data.find_first_of("0123456789");

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

	return pos;
}

void MainProcess::getTrueHelper(string &fileTrue, string &search, vector<Sequence> &trueHuman, vector<Sequence> &trueOther)
{
	string dataTrue;
	unsigned int trueCount = 0;
	int cnt = 0;

	ifstream inFileTrue;
	inFileTrue.open(fileTrue);
	if(inFileTrue.fail())
		cout << "ERROR3: Failure to open file " << fileTrue << endl;
	while(getline(inFileTrue, dataTrue))
	{
		while(dataTrue.length() > 0)
		{
			string temp = dataTrue.substr(2,search.length());
			if((dataTrue.substr(0,1) == "s") && (dataTrue.substr(2,5) == "HUMAN"))
			{
				cnt++;
				getSequenceMaf(dataTrue, trueHuman);
			}
			else if((dataTrue.substr(0,1) == "s") && (temp == search))
			{
				cnt++;
				getSequenceMaf(dataTrue, trueOther);
			}
			getline(inFileTrue, dataTrue);
		}
		trueCount++;
		if(cnt < 2)
		{
			trueHuman.pop_back();
			cnt = 0;
		}
		else
			cnt = 0;
		getline(inFileTrue, dataTrue);
	}
	inFileTrue.close();
}

void MainProcess::getMafHelper(string &fileMaf, vector<Sequence> &mafHuman, vector<Sequence> &mafOther)
{
	string dataMaf;
	unsigned int mafCount = 0;

	ifstream inFileMaf;
	inFileMaf.open(fileMaf);
	if(inFileMaf.fail())
		cout << "ERROR4: Failure to open file " << fileMaf << endl;
	while(getline(inFileMaf, dataMaf))
	{
		while(dataMaf.length() > 0)
		{
			if((dataMaf.substr(0,1) == "s"))
			{
				getSequenceMaf(dataMaf, mafHuman);
				getline(inFileMaf, dataMaf);
			}
			if((dataMaf.substr(0,1) == "s"))
			{
				getSequenceMaf(dataMaf, mafOther);
			}
			getline(inFileMaf, dataMaf);
		}
		mafCount++;
		getline(inFileMaf, dataMaf);
	}
	inFileMaf.close();
}

string MainProcess::searchString(string search)
{
	int tempStart = search.find_first_of(".");
	int tempEnd;

	for(unsigned int i = tempStart+1; i < search.length(); i++)
	{
		if(ispunct(search[i]))
		{
			tempEnd = i;
			break;
		}
	}

	string tempStr = search.substr(tempStart+1, (tempEnd-tempStart-1));
	return tempStr;
}

//TODO fix array
//Processes true alignment files
void MainProcess::trueProcess(vector<Sequence> &human, vector<Sequence> &other, vector<double> &t, size_t &tTotal)
{
	size_t size = getArrSize(trueHuman, trueOther);

	for(unsigned int i = 0; i < size; i++)
		t.push_back(i);

	size_t pos1 = 0, pos2 = 0;
	string hTemp, oTemp;
	for(size_t j = 0; j < human.size(); j++)
	{
		pos1 = human[j].seqStart;
		pos2 = other[j].seqStart;
		hTemp = human[j].seq;
		oTemp = other[j].seq;

		for(size_t i = 0; i < human[j].seq.length(); i++)
		{
			if(hTemp[i] != '-')
			{
				if(oTemp[i] != '-')
					t[pos1] = (pos2);
				else
				{
					t[pos1] = (pos2-(0.5));
				}
				pos1++;
			}
			if(oTemp[i] != '-')
			{
				pos2++;
			}
		}
	}
	tTotal = pos1;
}

size_t MainProcess::getArrSize(vector<Sequence> &human, vector<Sequence> &other)
{
	size_t count = 0;
	string hTemp, oTemp;
	for(size_t j = 0; j < human.size(); j++)
	{
		hTemp = human[j].seq;
		oTemp = other[j].seq;

		for(size_t i = 0; i < human[j].seq.length(); i++)
		{
			if(hTemp[i] != '-')
			{
				if(oTemp[i] != '-')
					count++;
				else
				{
					count++;
				}
			}
		}
	}
	return count;
}

//Processes maf alignment files
void MainProcess::mafProcess(vector<Sequence> &human, vector<Sequence> &other, vector<double> &t, vector<pair<double,double>> &totals)
{
	if(human.size() < 0 || other.size() < 0)
		totals.push_back(make_pair(0, 0));
	else
	{
		size_t cTotal = 0;
		size_t correct = 0;
		for(size_t j = 0; j < human.size(); j++)
		{
			size_t pos1 = human[j].seqStart;
			size_t pos2 = other[j].seqStart;

			double p,k,dif;

			for(size_t i = 0; i < human[j].seq.length(); i++)
			{
				if(human[j].seq.substr(i,1) != "-")
				{
					p = t[pos1];
					if(other[j].seq.substr(i,1) != "-")
						k = pos2;
					else
						k = pos2-(0.5);
					dif = abs(p-k);
					if(dif <= c)
						correct++;
					pos1++;
					cTotal++;
				}
				if(other[j].seq.substr(i,1) != "-")
					pos2++;
			}
		}
		totals.push_back(make_pair(correct, cTotal));
	}
}
