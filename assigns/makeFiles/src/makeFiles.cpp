/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstddef>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

int getdir (string, vector<string> &);

int main()
{
	string path = "";
	string dir = string("filesTemp");
	vector<string> files;
	vector<string> trueFiles, mafFiles, tempFiles;

	ifstream ifmafFiles;
	ifstream iftrueFiles;
	string trueBuff, mafBuff;

	iftrueFiles.open("filesTemp/trueFiles.txt");
	if(iftrueFiles.fail())
			cout << "ERROR: Failure to open file: filesTemp/trueFiles.txt\n";

	while(getline(iftrueFiles, trueBuff))
	{
		trueFiles.push_back(trueBuff);
	}
	iftrueFiles.close();

	ifmafFiles.open("filesTemp/mafFiles.txt");
	if(ifmafFiles.fail())
		cout << "ERROR: Failure to open file: filesTemp/mafFiles.txt\n";

	while(getline(ifmafFiles, mafBuff))
	{
		mafFiles.push_back(mafBuff);
	}

/*
	for(unsigned int i = 0; i < mafFiles.size(); i++)
	{
		cout << mafFiles[i] << endl << trueFiles[i] << endl;
	}
*/

	//Gets file list form directory
	getdir(dir,files);

	for (unsigned int i = 0; i < files.size(); i++) {
	    cout << files[i] << endl;
	}
	files.erase(files.begin(), files.begin()+2);

	for(unsigned int j = 0; j < files.size(); j++)
	{
		string str = files[j].substr(0, files[j].length()-4)+".txt";
		string path = "files/"+str;

		//tempFiles = mafFiles;
		for(unsigned int i = 0; i < mafFiles.size(); i++)
		{
			tempFiles.push_back(mafFiles[i].substr(0,mafFiles[i].length()-1) + files[j]);
		}
		//Redirect cout to file
		//file2 = path to direct output files
		ofstream out(path);
		streambuf *coutbuf = std::cout.rdbuf();
		cout.rdbuf(out.rdbuf());

		for(unsigned int i = 0; i < mafFiles.size(); i++)
			cout << trueFiles[i] << endl;
		for(unsigned int i = 0; i < mafFiles.size(); i++)
			cout << tempFiles[i] << endl;

		cout.rdbuf(coutbuf);
		tempFiles.erase(tempFiles.begin(),tempFiles.end());
	}

	//TODO handle inversions
	return 0;
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
