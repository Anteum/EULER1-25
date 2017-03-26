#include "connect.h"

int three()//find prime factors of given number
{
	long long num = 600851475143;
	for (int i = 2; i <= num; i++)
	{
		if (num%i == 0)
		{
			num /= i;
			cout << i << endl;
			i--;
		}
	}



	/*
	const double limit = 600851475143;
	double total = 1;
	bool done;
	for(double i=2.0;i<limit;i+=1.0)//2->limit
	{
		done=false;
		if(fmod(limit,i)==0.0)//i is a factor of limit
		{
			double j=i-1.0;
			while(!done)
			{
				if(j==1.0)//i is prime
				{
					cout << i << " is a prime factor of " << limit << '\n';
					total *= i;
					done = true;
				}
				else if(fmod(i,j)==0.0)//i is not prime
				{
					done = true;
				}
				j--;
			}
		}
		if (total == limit)//ends after finding largest prime factor
			return 0;
	}
	*/

	return 0;
}
