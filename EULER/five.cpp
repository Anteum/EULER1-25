#include "connect.h"

int five()//find lowest int with factors of 1-20
{
	const int end = 20;
	unsigned long long total = 1;//(max end of 50 will fit in long long)
	vector<int> factors;
	for (int i = 1; i <= end; i++)//for each number we are wanting factors of
	{
		int temp = i;
		for (int j = 0; j < factors.size(); j++)//for each factor in the list
		{
			if (temp%factors[j] == 0)//if factor in temp is not unique
			{
				temp /= factors[j];//remove that factor
			}	
		}
		//if(temp!=1)//every number is prime or made of 2 factors smaller
		factors.push_back(temp);//add remaining factor to list
	}
	for each  (int x in factors)//for each! //product all factors for solution
	{
		cout << x << " ";
		total *= x;
	}
	cout << total;
	
	
	
	/*
	int count = 20;
	bool done=false;
	while(!done)
	{
		for(int i=1;i<=20;i++)//for all ints 1 to 20
		{
			if(count%i!=0)//if count does not have int as factor
			{
				break;//nope that number 
			}
			if(i==20)//if count passes 20
			{
				cout<<count;
				done=true;
			}
		}
		count++;
	}
	*/
	return 0;
}