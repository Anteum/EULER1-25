#include "connect.h"

int ten()//sum all the primes!(< 2 000 000)...fast!...
{
	//*
	const int limit = 2000000;
	long long sum = 0;
	vector<bool> primes(limit, true);
	primes[0] = false; primes[1] = false;//0 & 1 are special non-primes
	for (int i = 0; i < limit; i++) 
	{
		if (primes[i])
		{
			for (int j = i * 2; j < limit; j += i)
			{
				primes[j] = false;
			}
		}
		//cout << i << endl;
	}
	for (int i = 0; i < limit; i++)
	{
		if (primes[i])
			sum += i;
	}
	cout << sum;
	//*/
	//add primes to sum but also to list and only check primes against new numbers
	/*
	long long sum = 0;
	vector<int> primes;
	primes.reserve(148933);
	primes.push_back(2);
	for (int i = 3; i <= 2000000; i++)
	{
		for (int j = 0; j < primes.size(); j++)
		{
			if (i%primes[j] == 0)
				break;
			if (j == primes.size() - 1)
			{
				primes.push_back(i);
				cout << i << ' ';
			}
		}
	}
	for (int i = 0; i < primes.size(); i++)
	{
		sum += primes[i];
	}
	cout << sum << ' ' << primes.size();

	//*/
	
	/*
	long long total=2000001000000;//sum of ints 1 to 2,000,000
	cout<<total<<' ';
	total-=38;
	for(int i=11;i<=2000000;i++)
	{
		//cout<<'\n'<<i<<' '<<total;
		//cout<<i<<' ';
		if(i%2==0)
		{
			total-=i;
			goto end;
		}
		else if(i%3==0)
		{
			total-=i;
			goto end;
		}
		else if(i%5==0)
		{
			total-=i;
			goto end;
		}
		else if(i%7==0)
		{
			total-=i;
			goto end;
		}
		for(int j=11;j<i/10;j++)
		{		
			if(i%j==0)
				total-=i;
		}
		
		end:;
		
	}
	cout<<'\n'<<total;
	//*/
	/*
	long long primeSum=17;
	const int max=2000000;
	cout<<'2'<<' '<<'3'<<' '<<'5'<<' '<<'7'<<' ';
	for(int i=11;i<max;i+=2)
	{
		for(int j=i/10;i>0;j--)
		{
			//cout<<" "<<'i'<<i<<' '<<j<<'j'<<" ";
			if(i%3==0)
				break;
			else if(i%5==0)
				break;
			else if(i%7==0)
				break;
			if(j==1)
			{
				primeSum+=i;
				cout<<i<<" ";
			}
			if(i%j==0)
				break;			
		}
	}
	cout<<'\n'<<primeSum<<"  Boom!";
	*/
	return 0;
}