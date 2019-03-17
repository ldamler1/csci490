/*****************************************************************
// FILE:      gene.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  18 FEB 2018
// PURPOSE:
*****************************************************************/
#include "MainProcess.h"

const int dataSets = 10;

int main()
{
	string cp = cPath;
	cout << "Running C = " << cp << "...\n";
	MainProcess dirCall;
	//Path for directory containing file list
	string dir = string("files");
	vector<string> files;

	//Gets file list form directory
	dirCall.getdir(dir,files);
/*
	for (unsigned int i = 0; i < files.size(); i++) {
	    cout << files[i] << endl;
	}
*/
	files.erase(files.begin(), files.begin()+2);


	vector<string> trueFile;
	vector<string> mafFile;

	MainProcess call1;

	for(unsigned int i = 0; i < files.size(); i++)
	{
		cout << i << " Thinking...\n";

		string file = "files/"+files[i];
		string outpath = "std_files/"+cp+"/"+files[i];
		string buff;

		ifstream inFile;
		inFile.open(file);
		if(inFile.fail()){
			cout << "\nERROR1: failure to open file " << file << endl;
			exit(-1);
		}

		while(getline(inFile, buff))
		{
			for(int j = 0; j < dataSets; j++)
			{
				trueFile.push_back(buff);
				getline(inFile,buff);
			}
			for(int j = 0; j < dataSets; j++)
			{
				mafFile.push_back(buff);
				getline(inFile,buff);
			}
		}
		inFile.close();

		//TODO delete me
		for(unsigned int k = 0; k < mafFile.size(); k++)
		{
			cout << k << " " << trueFile[k] << endl;
			cout << k << " " << mafFile[k] << endl;
		}


		string trueTemp;
		string mafTemp;

		//Redirect cout to file
		//file2 = path to direct output files
		ofstream out(outpath);
		streambuf *coutbuf = std::cout.rdbuf();
		cout.rdbuf(out.rdbuf());

		for(unsigned int j = 0; j < mafFile.size(); j++)
		{
			if(j >= 9)
			{
				trueTemp = trueFile[j];
				mafTemp = mafFile[j];
			}
			else
			{
				mafTemp = mafFile[j];
				trueTemp = trueFile[j].substr(0,trueFile[j].length()-1);
			}
			call1.mainCall(mafTemp, trueTemp);
		}

		call1.print();
		call1.clear();

		cout.rdbuf(coutbuf);

		trueFile.clear();
		mafFile.clear();

		cout << i << " Thinking End\n";
	}

	cout << "Main CALL END\n\n";

	cout << "STD CALL START\n";
	MainProcess stdCall;

	stdCall.stdProcess();
	stdCall.clear();

	cout << "STD CALL END\n";

	return 0;
}

//Gets directory list of files and places in vector
int MainProcess::getdir(string dir, vector<string> &files)
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
