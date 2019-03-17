/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:
*****************************************************************/
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "MainProcess.h"

int getdir (string, vector<string> &);

int main()
{
	//Path for directory containing file list
	string dir = string("assign2/files");
	vector<string> files;

	//Gets file list form directory
	getdir(dir,files);

	for (unsigned int i = 0; i < files.size(); i++) {
	    cout << files[i] << endl;
	}
	files.erase(files.begin(), files.begin()+2);

	//Opens each file from directory
	for(unsigned int j = 0; j < files.size(); j++)
	{

		string file = "files/"+files[j];
		string file2 = "std_files/"+files[j];
		string buff;

		//TODO move this
		vector<string> mafFile;
		vector<string> trueFile;
		int i = 0;

		ifstream inFile;
		//Path to open input files
		inFile.open(file);
		if(inFile.fail())
			cout << "\nERROR: Failure to open " << file << endl;

		while(getline(inFile, buff))
		{
			for(int i = 0; i < 10; i++)
			{
				trueFile.push_back(buff);
				getline(inFile, buff);
			}
			for(int i = 0; i < 10; i++)
			{
				mafFile.push_back(buff);
				getline(inFile, buff);
			}

			i++;
		}

		for(unsigned int i = 0; i < mafFile.size(); i++)
		{
			cout << i << " " << trueFile[i] << endl;
			cout << i << " " << mafFile[i] << endl;
		}

		MainProcess call1;

		//Passes in location of maf and true file
		call1.mainCall(mafFile[0], trueFile[0]);

		call1.mainCall(mafFile[1], trueFile[1]);

		call1.mainCall(mafFile[2], trueFile[2]);

		call1.mainCall(mafFile[3], trueFile[3]);

		call1.mainCall(mafFile[4], trueFile[4]);

		call1.mainCall(mafFile[5], trueFile[5]);

		call1.mainCall(mafFile[6], trueFile[6]);

		call1.mainCall(mafFile[7], trueFile[7]);

		call1.mainCall(mafFile[8], trueFile[8]);

		call1.mainCall(mafFile[9], trueFile[9]);

		//Redirect cout to file
		//file2 = path to direct output files
		ofstream out(file2);
		streambuf *coutbuf = std::cout.rdbuf();
		cout.rdbuf(out.rdbuf());

		call1.print();
		call1.clear();

		cout.rdbuf(coutbuf);
	}

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
