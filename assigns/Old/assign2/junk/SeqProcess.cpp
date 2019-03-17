#include "MainProcess.h"

//Gets sequence and puts in string
string MainProcess::getSequenceMaf(string data, int &pos)
{
	bool flag = false;
	string seq;
	
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	
	for(unsigned int i = 0; i < data.length(); i++)
	{
		//Possibly if == digit grab all digits till white space
		pos = data.find_first_of("0123456789");
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


//print method
/*void MainProcess::print(double &subRate, double &titv, double &gapRate)
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
}*/
