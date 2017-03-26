#include "connect.h"

int pdivsum(int num)//s(n): sum of proper divisors of n where "proper" discounts n itself
{
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
	{
		if (num%i == 0)
			sum += i;
	}
	return sum;
}

int twyone()//sum of amicable numbers < 10000
{//amicable numbers are pairs of numbers whose proper divisors sum to the other
	int sum = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (pdivsum(i) > i && pdivsum(pdivsum(i)) == i)//looking for i's amicable as greater than i counts each pair only once
			sum += (i + pdivsum(i));
	}
	cout << sum;
	
	/*
	bool checked[10000];
	int divisorSum,num1,num2,amicableSum=0;
	for(int i=0;i<10000;i++)
		checked[i]=false;
	for(int i=0;i<200;i++)
		checked[i]=true;
	//for(int i=0;i<10000;i++)
		//cout<<checked[i]<<' ';
	for(int i=200;i<10000;i++)
	{
		if(checked[i]==false)
		{
			num1=-1;
			num2=i;
			Start:
			divisorSum=0;
			for(int j=num2/2;j>0;j--)
			{
				if(num2%j==0)
					divisorSum+=j;
			}
			if(divisorSum==num1)
			{
				amicableSum+=num1;
				amicableSum+=num2;
				cout<<num1<<' '<<num2<<'\n';
			}
			//cout<<i<<' '<<divisorSum<<'\n';
			checked[num2]=true;
			num1=num2;
			num2=divisorSum;
			
			if(num2<10000&&checked[num2]==false)
			{
				goto Start;
			}
		}
	}
	cout<<'\n'<<amicableSum;
	//*/
	return 0;
}