

int main()
{
	
	int lineCnt1 = 0, lineCnt2 = 0;
	int cnt = 0;
	
	ifstream inFileMaf;
	
	inFileMaf.open("HUMAN.DOG.L3000.O300.maf");
	if(inFileMaf.fail())
		cout << "ERROR: Failure to open MAF";
	
	cout << "Thinking...\n";
	
	while(getline(inFileMaf, dataMaf))
	{
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 0))
		{
			lineCnt1++;
			getline(inFileMaf, dataMaf);
			cnt++;
		}
		if((dataMaf.substr(0,1) == "s") && (cnt%2 == 1))
		{
			lineCnt2++;
			cnt++;
		}
		cnt = 0;
	}
	
	cout << "LINE COUNT1: " << lineCnt1 << endl;
	cout << "LINE COUNT2: " << lineCnt2 << endl;
		
	return 0;
}
