#include "connect.h"
#include <sstream>

int thirtn()//sum the 100 numbers in numlist.txt...output is backwards
{
	string list[100], summy;
	int sum = 0, temp;
	ifstream numlist;
	numlist.open("numlist.txt");
	for(int i=0;i<100;i++)
	{
			numlist >> list[i];
	}
	for(int j=49;j>=0;j--)
	{
		for(int i=0;i<100;i++)
		{
			temp = list[i][j]-'0';//-'0' converts the number char to its int
			sum += temp;
			//cout<<temp<<' ';
		}
		summy = to_string(sum);//convert sum to string (later back to int) for quicker access to its digits
		cout << summy[2] << ' ';//assumes sum > 99
		sum = (summy[0]-'0')*10 + (summy[1]-'0');//carries the tens and hundreds
		//cout<<' '<<sum<<'\n';
	}
	cout << sum / 10 << ' ' << sum % 10;//output leftovers
	/*
	for(int i=0;i<100;i++)
	{
			cout<<list[i]<<'\n';
	}
	//*/
	numlist.close();
	return 0;
}