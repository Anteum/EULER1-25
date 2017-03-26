#include "connect.h"

int seven()//10,001st prime number
{
	/*
	//p_n <= n log n + n (log log n - 0.9385) tight upper bound for nth prime for n>=7022
	const int n = 10001;
	int max = n * log(n) + n * (log(log(n)) - 0.9385);//eqauals the 10,018th prime.....
	for (int i = max; i > 0; i--)
	{
		for (int j = 2; j < max / 2; j++)
		{
			if (i%j == 0)
				break;
			else if (j == max / 2 - 1)
			{
				cout << i;
				return 0;
			}
		}
	}
	*/
	
	int primes=0,count=2;
	bool done=false;
	while(!done)
	{
		for(int i=int(sqrt(count)); i>0; i--)
		{
			if(i==1)//if count had no factors greater than 1 and is therefore prime
				primes++;
			else if(count%i==0)//if count has a factor
				break;//its not prime 
		}
		if(primes==10001)//if we have found 10,001st prime
		{
			cout<<count;
			done=true;
		}
		count++;	
	}
	
	return 0;
}