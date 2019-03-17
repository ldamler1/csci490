#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <algorithm>

#define chimpFile "assign2Chimp_L3000_O300.txt"
#define dogFile "assign2Dog_L3000_O300.txt"
#define mouseFile "assign2Mouse_L3000_O300.txt"

using namespace std;

double standardDeviation(vector<double> &);

int main()
{
	ifstream inFile;
	//ifstream inFileDog;
	//ifStream inFileMouse;
	
	string chimp = chimpFile;
	string dog = dogFile;
	string mouse = mouseFile;
	
	string buff;
	string delim = ",";
	
	string temp;
	
	size_t pos;
	
	double sensSD, specSD;
	
	inFile.open(mouse.c_str());
	//inFileDog.open(dog);
	//inFileMouse.open(mouse);
	
	vector<double> sens;
	vector<double> spec;
	
	size_t start;
	size_t end = 0;
	
	//TODO put in getList method
	while(getline(inFile, buff))
	{
		pos = buff.find(delim);
		temp = buff.substr(0,pos);
		sens.push_back(strtod(temp.c_str(), NULL));
		temp = buff.substr(pos+1, buff.length()-pos);
		spec.push_back(strtod(temp.c_str(), NULL));
	}
	
	for(const double &i : sens)
	{
		cout << "Sensitivity: " << i << endl;
	}
	
	for(const double &i : spec)
	{
		cout << "Specificity: " << i << endl;
	}
	
	//Standard Deviation
	sensSD = standardDeviation(sens);
	specSD = standardDeviation(spec);
	
	cout << "Sensitivity Standard Deviation: " << sensSD << endl;
	cout << "Specificity Standard Deviation: " << specSD << endl;
}

double standardDeviation(vector<double> &v)
{
	double xBar = 0; 
	double Esum = 0;
	double stdDev;
	
	for_each(v.begin(), v.end(), [&](double n){xBar += n;});
	xBar = xBar/v.size();
	
	for_each(v.begin(), v.end(), [&](double n){Esum += pow((n - xBar),2);});
	
	stdDev = sqrt((Esum/(v.size()-1)));
	
	return stdDev;
}
