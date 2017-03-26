#include "connect.h"

int sixtn()//find sum of digits of 2^1000  
{
	vector<short> powered(1, 1);//vector of 2^1000 digits will be reverse order
	int sum = 0, size = 1, carry = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < size; j++)
		{
			powered[j] = powered[j] * 2 + carry;//2 could be changed to take powers of different int <10
			carry = 0;
			if (powered[j] > 9)
			{
				if (j + 1 < size)//if not at end of number, carry
					carry = powered[j] / 10;
				else//if at end of number, stick extra on end
					powered.push_back(powered[j] / 10);
				powered[j] %= 10;
			}
		}
		size = powered.size();//update size here so above for ends correctly
	}
	for (int j = 0; j < powered.size(); j++)//sum & print final power
	{
		sum += powered[j];
		cout << powered[j] << ' ';
	}
	cout << endl << sum;

	/*//using array
	int leadInd=302,temp,sum=0,bonus=0;
	int powered[302];//originally size 1000, decreased after length of final power found
	for(int i=0;i<302;i++)
		powered[i]=0;
	powered[301]=1;//2^0
	for(int j=1;j<=1000;j++)//stops at 2^lim(j)
	{
		for(int i=0;i<302;i++)
		{
			if(powered[i]!=0)
			{
				leadInd=i;
				break;
			}
		}
		for(int k=301;k>=leadInd-1;k--)
		{
			temp=powered[k]*2+bonus;
			if(temp<10)
			{
				powered[k]=temp;
				bonus=0;
			}
			else
			{
				powered[k]=temp%10;
				bonus=1;
			}
		}
		/*
		for(int i=0;i<302;i++)
			cout<<powered[i];
		cout<<"\n\n";
	}
	for (int i = 0; i < 302; i++)
	{
		cout << powered[i];
		sum += powered[i];
	}
	cout << endl << endl << sum;
	*/

	//cout<<leadInd<<'\n';
	//*/
	/*
	const int max=20;
	int length=0;
	long long twoAndBeyond=1;
	for(int i=1;i<=50;i++)
	{
		twoAndBeyond=twoAndBeyond*2;
		for(int j=1;j<max;j++)
		{
			if(twoAndBeyond<pow(10,j)&&twoAndBeyond>pow(10,j-1))
				length=j;
		}
		for(int j=1;j<max-length;j++)
		{
			cout<<" ";
		}
		cout<<twoAndBeyond<<'\n';
	}
	*/
	return 0;
}