#include "MainProcess.h"
#include <math.h>

/*
 * TODO
 * THIS IS A MESS OF A SOURCE FILE
 * DON'T JUDGE ME
 * FIX LATER
 */


vector<Avg> K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2,
			K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20;
vector<Avg> baboonAvg, catAvg, chimpAvg, cowAvg, dogAvg, mouseAvg, pigAvg, ratAvg;

void clearAvgVec();
void printVec(vector<Avg> &, vector<Avg> &, vector<Avg> &k, vector<Avg> &, vector<Avg> &, vector<Avg> &);
void printSpecies(vector<Avg> &, vector<Avg> &);
void sortSpecies(vector<Avg> &, vector<Avg> &, vector<Avg> &);

void MainProcess::stdProcess()
{
	string cp = cPath;
	//Directory for averages files for calculating standard deviation
	string dir = string("files");
	vector<string> files;

	//Gets file list in directory
	getdir(dir,files);


	files.erase(files.begin(), files.begin()+2);
/*
	for (unsigned int i = 0; i < files.size(); i++) {
	    cout << files[i] << endl;
	}
	cout << endl;
*/

	string species[] = {"BABOON","CAT","CHIMP","COW","DOG","MOUSE","PIG","RAT"};
	vector<string> baboon, cat, chimp, cow, dog, mouse, pig, rat;

	//TODO make method for sorting avgs into proper vector
	string search;
	for(unsigned int i = 0; i < files.size(); i++)
	{
		search = searchString(files[i]);
		if(search == species[0]){baboon.push_back(files[i]);}
		else if(search == species[1]){cat.push_back(files[i]);}
		else if(search == species[2]){chimp.push_back(files[i]);}
		else if(search == species[3]){cow.push_back(files[i]);}
		else if(search == species[4]){dog.push_back(files[i]);}
		else if(search == species[5]){mouse.push_back(files[i]);}
		else if(search == species[6]){pig.push_back(files[i]);}
		else if(search == species[7]){rat.push_back(files[i]);}
	}

	//Direct cout to file
	//Path to place output files
	ofstream out("StandardDeviation/"+cp+"_T1T2.txt");//+path[0]);
	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	//TODO place in helper method
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, baboon);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, cat);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, chimp);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, cow);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, dog);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, mouse);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, pig);
	processVecT1_2(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2, rat);

	printVec(K_T1, O_T1, KO_T1, K_T2, O_T2, KO_T2);

	cout.rdbuf(coutbuf);

	//Direct cout to file
	//Path to place output files
	ofstream out2("StandardDeviation/"+cp+"_W12W20.txt");
	streambuf *coutbuf2 = std::cout.rdbuf();
	cout.rdbuf(out2.rdbuf());
	//K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, baboon);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, cat);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, chimp);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, cow);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, dog);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, mouse);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, pig);
	processVecT0(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20, rat);

	printVec(K_T0_W12, O_T0_W12, KO_T0_W12, K_T0_W20, O_T0_W20, KO_T0_W20);

	cout.rdbuf(coutbuf2);

	//TODO place in helper
	getMax(K_T1);
	getMax(O_T1);
	getMax(KO_T1);
	getMax(K_T2);
	getMax(O_T2);
	getMax(KO_T2);
	getMax(K_T0_W12);
	getMax(O_T0_W12);
	getMax(KO_T0_W12);
	getMax(K_T0_W20);
	getMax(O_T0_W20);
	getMax(KO_T0_W20);

	//Direct cout to file
	//Path to place output files
	ofstream out3("StandardDeviation/"+cp+"_max_Sens_Spec.txt");
	streambuf *coutbuf3 = std::cout.rdbuf();
	cout.rdbuf(out3.rdbuf());
	//TODO place in helper
	vector<Avg> sortSens, sortSpec;
	sortSpecies(sortSens, sortSpec, baboonAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, catAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, chimpAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, cowAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, dogAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, mouseAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, pigAvg);
	printSpecies(sortSens, sortSpec);
	sortSpecies(sortSens, sortSpec, ratAvg);
	printSpecies(sortSens, sortSpec);

	cout.rdbuf(coutbuf3);
}

void sortSpecies(vector<Avg> &sortSens, vector<Avg> &sortSpec, vector<Avg> &v)
{
	sortSens = v;
	sortSpec = v;
	sort(sortSens.begin(), sortSens.end(), [](Avg a1, Avg a2){return a1.sens > a2.sens;});
	sort(sortSpec.begin(), sortSpec.end(), [](Avg a1, Avg a2){return a1.spec > a2.spec;});
}

void MainProcess::processSTDFile(vector<Avg> &v, string files)
{
	string species = searchString(files);

	string cp = cPath;
	ifstream inFile;

	string buff;
	string delim = ",";

	string temp;
	string tempLocation = "std_files/"+cp+"/"+files;

	size_t pos;

	double sensSD, specSD;
	double avgSens, avgSpec;

	//Opens file in directory
	inFile.open(tempLocation);
	if(inFile.fail())
		cout << "ERROR: Failure to open " << tempLocation << endl;

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

	Avg tempAvg = {files, species, avgSens, avgSpec};

	v.push_back(tempAvg);

	clear();
}

//Calculates standard deviation
double MainProcess::standardDeviation(vector<double> &v, double &xBar)
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

//TODO make stdSearch process source file
string MainProcess::getVal(string search, string valToFind)
{
	int startStr = search.find_first_of(".");
	int start;
	for(unsigned int i = startStr+1; i < search.length(); i++){
		if(ispunct(search[i]))
		{
			start = i;
			break;
		}
	}

	string searchStr = search.substr(start, search.length());

	int tempStart = searchStr.find_first_of(valToFind);
	int tempEnd;

	for(unsigned int i = tempStart; i < searchStr.length(); i++)
	{
		if(ispunct(searchStr[i]))
		{
			tempEnd = i;
			break;
		}
	}

	string tempStr = searchStr.substr(tempStart, (tempEnd-tempStart));
	return tempStr;
}

//TODO place in source file
void MainProcess::processVecT1_2(vector<Avg> &K_T1, vector<Avg> &O_T1, vector<Avg> &KO_T1,
								 vector<Avg> &K_T2, vector<Avg> &O_T2, vector<Avg> &KO_T2,
								 vector<string> &species)
{
	string oVal, kVal, tVal, wVal;
	//K change, T = 1,2, K_T1 K_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(oVal == "O300" && tVal == "T1")
			processSTDFile(K_T1, species[i]);
		if(oVal == "O300" && tVal == "T2")
			processSTDFile(K_T2, species[i]);
	}
	//O change, T = 1,2, O_T1 O_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(tVal == "T1" && kVal == "K2000")
			processSTDFile(O_T1, species[i]);
		if(tVal == "T2" && kVal == "K2000")
			processSTDFile(O_T2, species[i]);
	}
	//KO change, T = 1,2, KO_T1 KO_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(tVal == "T1" && ((kVal == "K2000" && oVal == "O300") || (kVal == "K5000" && oVal == "O500")))
			processSTDFile(KO_T1, species[i]);
		if(tVal == "T2" && ((kVal == "K2000" && oVal == "O300") || (kVal == "K5000" && oVal == "O500")))
			processSTDFile(KO_T2, species[i]);
	}
}

//TODO can stream line. Use same method. Check if use tVal or wVal
void MainProcess::processVecT0(vector<Avg> &K_T0_W12, vector<Avg> &O_T0_W12, vector<Avg> &KO_T0_W12,
							   vector<Avg> &K_T0_W20, vector<Avg> &O_T0_W20, vector<Avg> &KO_T0_W20,
							   vector<string> &species)
{
	//TODO make me work w/ T0
	//Change T=1/2 to wVal == ?
	string oVal, kVal, tVal, wVal;
	//K change, W = 12,20, K_T1 K_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(oVal == "O300" && wVal == "W12")
			processSTDFile(K_T0_W12, species[i]);
		if(oVal == "O300" && wVal == "W20")
			processSTDFile(K_T0_W20, species[i]);
	}
	//O change, W = 12,20, O_T1 O_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(wVal == "W12" && kVal == "K2000")
			processSTDFile(O_T0_W12, species[i]);
		if(wVal == "W20" && kVal == "K2000")
			processSTDFile(O_T0_W20, species[i]);
	}
	//KO change, W = 12,20, KO_T1 KO_T2
	for(unsigned int i = 0; i < species.size(); i++)
	{
		kVal = getVal(species[i], "K");
		oVal = getVal(species[i], "O");
		tVal = getVal(species[i], "T");
		wVal = getVal(species[i], "W");

		if(wVal == "W12" && ((kVal == "K2000" && oVal == "O300") || (kVal == "K5000" && oVal == "O500")))
			processSTDFile(KO_T0_W12, species[i]);
		if(wVal == "W20" && ((kVal == "K2000" && oVal == "O300") || (kVal == "K5000" && oVal == "O500")))
			processSTDFile(KO_T0_W20, species[i]);
	}
}

void printVec(vector<Avg> &k1, vector<Avg> &o1, vector<Avg> &ko1, vector<Avg> &k2, vector<Avg> &o2, vector<Avg> &ko2)
{

	string species;
	species = k1[0].species;
	cout << "K2000-5000, O300 T1W12\nSensitivity\n";
	for(unsigned int i = 0; i < k1.size(); i++)
	{
		if(k1[i].species == species)
			cout << k1[i].sens << "\t";
		if(k1[i].species != species)
		{
			cout << endl;
			species = k1[i].species;
			cout << k1[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = k1[0].species;
	for(unsigned int i = 0; i < k1.size(); i++)
	{
		if(k1[i].species == species)
			cout << k1[i].spec << "\t";
		if(k1[i].species != species)
		{
			cout << endl;
			species = k1[i].species;
			cout << k1[i].spec << "\t";
		}
	}

	species = o1[0].species;
	cout << "\n\nK2000, O300-500 T1W12\n";
	for(unsigned int i = 0; i < o1.size(); i++)
	{
		if(o1[i].species == species)
			cout << o1[i].sens << "\t";
		if(o1[i].species != species)
		{
			cout << endl;
			species = o1[i].species;
			cout << o1[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = o1[0].species;
	for(unsigned int i = 0; i < o1.size(); i++)
	{
		if(o1[i].species == species)
			cout << o1[i].spec << "\t";
		if(o1[i].species != species)
		{
			cout << endl;
			species = o1[i].species;
			cout << o1[i].spec << "\t";
		}
	}

	species = ko1[0].species;
	cout << "\n\nK2000.O300, K5000.O500 T1W12\nSensitivity\n";
	for(unsigned int i = 0; i < ko1.size(); i++)
	{
		if(ko1[i].species == species)
			cout << ko1[i].sens << "\t";
		if(ko1[i].species != species)
		{
			cout << endl;
			species = ko1[i].species;
			cout << ko1[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = ko1[0].species;
	for(unsigned int i = 0; i < ko1.size(); i++)
	{
		if(ko1[i].species == species)
			cout << ko1[i].spec << "\t";
		if(ko1[i].species != species)
		{
			cout << endl;
			species = ko1[i].species;
			cout << ko1[i].spec << "\t";
		}
	}

	species = k2[0].species;
	cout << "\n\nK2000-5000, O300 T2W20\nSensitivity\n";
	for(unsigned int i = 0; i < k2.size(); i++)
	{
		if(k2[i].species == species)
			cout << k2[i].sens << "\t";
		if(k2[i].species != species)
		{
			cout << endl;
			species = k2[i].species;
			cout << k2[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = k2[0].species;
	for(unsigned int i = 0; i < k2.size(); i++)
	{
		if(k2[i].species == species)
			cout << k2[i].spec << "\t";
		if(k2[i].species != species)
		{
			cout << endl;
			species = k2[i].species;
			cout << k2[i].spec << "\t";
		}
	}

	species = o2[0].species;
	cout << "\n\nK2000, O300-500 T2W20\nSensitivity\n";
	for(unsigned int i = 0; i < o2.size(); i++)
	{
		if(o2[i].species == species)
			cout << o2[i].sens << "\t";
		if(o2[i].species != species)
		{
			cout << endl;
			species = o2[i].species;
			cout << o2[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = o2[0].species;
	for(unsigned int i = 0; i < o2.size(); i++)
	{
		if(o2[i].species == species)
			cout << o2[i].spec << "\t";
		if(o2[i].species != species)
		{
			cout << endl;
			species = o2[i].species;
			cout << o2[i].spec << "\t";
		}
	}

	species = ko2[0].species;
	cout << "\n\nK2000.O300, K5000.O500 T2W20\nSensitivity\n";
	for(unsigned int i = 0; i < ko2.size(); i++)
	{
		if(ko2[i].species == species)
			cout << ko2[i].sens << "\t";
		if(ko2[i].species != species)
		{
			cout << endl;
			species = ko2[i].species;
			cout << ko2[i].sens << "\t";
		}
	}
	cout << "\nSpecificity\n";
	species = ko2[0].species;
	for(unsigned int i = 0; i < ko2.size(); i++)
	{
		if(ko2[i].species == species)
			cout << ko2[i].spec << "\t";
		if(ko2[i].species != species)
		{
			cout << endl;
			species = ko2[i].species;
			cout << ko2[i].spec << "\t";
		}
	}
	cout << endl;
}

void MainProcess::getMax(vector<Avg> &v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(v[i].species == "BABOON"){baboonAvg.push_back(v[i]);}
		else if(v[i].species == "CAT"){catAvg.push_back(v[i]);}
		else if(v[i].species == "CHIMP"){chimpAvg.push_back(v[i]);}
		else if(v[i].species == "COW"){cowAvg.push_back(v[i]);}
		else if(v[i].species == "DOG"){dogAvg.push_back(v[i]);}
		else if(v[i].species == "MOUSE"){mouseAvg.push_back(v[i]);}
		else if(v[i].species == "PIG"){pigAvg.push_back(v[i]);}
		else if(v[i].species == "RAT"){ratAvg.push_back(v[i]);}
	}
}

void printSpecies(vector<Avg> &sortSens, vector<Avg> &sortSpec)
{
	cout << sortSens[0].species << "\nSensitivity\n";
	cout << sortSens[0].parms << "\nHighest: " << sortSens[0].sens << "," << sortSens[0].spec << endl;
	cout << sortSens.back().parms << "\nLowest: " << sortSens.back().sens << "," << sortSens.back().spec << endl;

	cout << "-----------------------------\nSpecificity\n";
	cout << sortSpec[0].parms << "\nHighest: " << sortSpec[0].sens << "," << sortSpec[0].spec << endl;
	cout << sortSpec.back().parms << "\nLowest: " << sortSpec.back().sens << "," << sortSpec.back().spec << endl << endl;
}

void clearAvgVec()
{
	K_T1.clear();
	O_T1.clear();
	KO_T1.clear();
	K_T2.clear();
	O_T2.clear();
	KO_T2.clear();
	K_T0_W12.clear();
	O_T0_W12.clear();
	KO_T0_W12.clear();
	K_T0_W20.clear();
	O_T0_W20.clear();
	KO_T0_W20.clear();
}
