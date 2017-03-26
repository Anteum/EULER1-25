#include "connect.h"

int twythr()//find sum of ints that are 'prime' to abundant sums under addition
{
	int abundants[6965],n=0,primishSum=0;
	bool primish[28124];
	for(int i=10;i<28123;i++)//creat array of abundant numbers
	{
		int divSum=0;
		for(int j=i/2;j>0;j--)
		{
			if(i%j==0)
				divSum+=j;	
		}
		if(divSum>i)
		{
			abundants[n]=i;
			n++;
		}
	}
	for(int i=0;i<28124;i++)//fill array
		primish[i]=true;
	for(int i=24;i<28124;i++)//test if primish
	{
		for(int j=0;abundants[j]<i;j++)//since abundants are in ascending order, this works ok
		{
			for(int k=0;abundants[k]<i;k++)
			{
				if(abundants[j]+abundants[k]==i)//test if any combo of abundants can make i
				{
					primish[i]=false;
					goto NextInt;
				}
			}
		}
		NextInt:;
	}
	for(int i=0;i<28124;i++)//sum primish numbers
	{
		if(primish[i]==true)
			primishSum+=i;
	}
	cout<<primishSum;
	//for(int i=0;i<6965;i++)//print abundants
		//cout<<abundants[i]<<'\n';
	return 0;
}