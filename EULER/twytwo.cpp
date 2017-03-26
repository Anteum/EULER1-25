#include "connect.h"

void selSort(string unsorted[],int size)//selection(slow) (alpha) sort of array of strings
{
	//*//works over mine...(from internet)
	while(size>0)
	{
		size--;
		int maxInd=size;
		for(int i=0;i<size;i++)
		{
			if(unsorted[i]>unsorted[maxInd])
				maxInd=i;
		}
		if(maxInd!=size)
			swap(unsorted[size],unsorted[maxInd]);
	}
	//*/
	/*//my sort is slow...
	for(int sortedInd=0;sortedInd<size;sortedInd++)
	{
		for(int curInd=sortedInd+1;curInd<size;curInd++)
		{
			if(unsorted[curInd]<=unsorted[sortedInd])
				swap(unsorted[sortedInd],unsorted[curInd]);
		}
	}
	//*/
}


int twytwo()//sum of name "scores" where score is location in ordered list * sum of letters in name's location in alphabet
{
	const int census=5163;
	string names[census];
	long long superSum=0;
	ifstream txt;
	txt.open("names.txt");
	while(txt.good())
	{
		for(int i=0;i<census;i++)
		{
			getline(txt,names[i],',');//look for commas to break up stream
		}		
	}
	for(int i=0;i<census;i++)
	{
		names[i]=names[i].substr(1,names[i].length()-2);//get rid of quotatation marks
	}
	txt.close();
	//for(int i=0;i<census;i++)//before
		//cout<<names[i]<<'\n';
	
	selSort(names,census);//alphabetize!
	cout<<"\n\n\n";

	for(int i=0;i<census;i++)//find sum of name according to alphanumeric code
	{
		int placeInList=i+1, alphaSum=0, alphaNum;
		string test=names[i], temp;
		char curLet;
		for(int letter=0;letter<test.length();letter++)
		{
			curLet = test[letter];//string to char
			alphaNum = curLet - 64;//char to int (ascii)
			alphaSum+=alphaNum;
		}
		cout<<names[i]<<'\t'<<alphaSum<<'\t'<<placeInList<<'\n';
		superSum+=(alphaSum*placeInList);
	}
	cout<<"\n\n\n"<<superSum;

	//for(int i=0;i<census;i++)after
		//cout<<names[i]<<'\n';
	return 0;
}