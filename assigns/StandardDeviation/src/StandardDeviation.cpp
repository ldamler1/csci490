#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

double standardDeviation(vector<double> &, double &);
int getdir (string, vector<string> &);

int main()
{
	//Directory for averages files for calculating standard deviation
	//TODO make "std_files/C5" global value
	string dir = string("std_files/C5");
	vector<string> files;

	//Gets file list in directory
	getdir(dir,files);

	for (unsigned int i = 0; i < files.size(); i++)
	{
	    cout << files[i] << endl;
	}
	files.erase(files.begin(), files.begin()+2);

	for(unsigned int i = 0; i < files.size(); i++)
	{
		ifstream inFile;

		string buff;
		string delim = ",";

		string temp;
		string tempLocation = "std_files/C5/"+files[i];

		size_t pos;
		double avgSens, avgSpec;

		double sensSD, specSD;

		//Opens file in directory
		inFile.open(tempLocation);
		if(inFile.fail())
				cout << "ERROR: Failure to open " << tempLocation << endl;

		vector<double> sens;
		vector<double> spec;

		//TODO put in getList method
		while(getline(inFile, buff))
		{
			pos = buff.find(delim);
			temp = buff.substr(0,pos);
			sens.push_back(strtod(temp.c_str(), NULL));
			temp = buff.substr(pos+1, buff.length()-pos);
			spec.push_back(strtod(temp.c_str(), NULL));
		}


		//Standard Deviation
		sensSD = standardDeviation(sens, avgSens);
		specSD = standardDeviation(spec, avgSpec);

		//Direct cout to file
		//Path to place output files
		ofstream out("StandardDeviation/"+files[i]);
		streambuf *coutbuf = std::cout.rdbuf();
		cout.rdbuf(out.rdbuf());

		cout << avgSens << endl;
		cout << avgSpec << endl;
		cout << sensSD << endl;
		cout << specSD << endl << endl;

		cout.rdbuf(coutbuf);
	}
}

//Calculates standard deviation
double standardDeviation(vector<double> &v, double &xBar)
{
	xBar = 0;
	double Esum = 0;
	double stdDev;

	for_each(v.begin(), v.end(), [&](double n){xBar += n;});
	xBar = xBar/v.size();

	for_each(v.begin(), v.end(), [&](double n){Esum += pow((n - xBar),2);});

	stdDev = sqrt((Esum/(v.size()-1)));

	return stdDev;
}

//Gets directory list of files and places in vector
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}
