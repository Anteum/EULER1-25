#include "connect.h"

int twyfor()//find number based on location in ordered list of permutations of digits
{	
	int num = 1000000, n = 9;// find num-th perm of dig 0 to n
	vector<short> code, digits, sol;
	for (int i = 0; i <= n; i++)//create vector of 0,1,...n
		digits.push_back(i);
	for (n; n > 0; n--)//create code of sols location
	{
		int codig = 0;
		while (num > factorial(n))//for a lexicographic order of permutations, numbers change every factorial amount
		{
			num -= factorial(n);
			codig++;
		}
		code.push_back(codig);
	}
	for (int i = 0; i < code.size(); i++)//translate code into sol(ution)
	{
		sol.push_back(digits[code[i]]);//always want code[i]th smallest remaining digit
		digits.erase(digits.begin()+code[i]);//(erase requires iterator)//only use each digit once by deleting used
	}
	sol.push_back(digits[0]);//append final digit
	for (int i = 0; i < sol.size(); i++)//print vector
		cout << sol[i];

	
	/*
	const int loc=1000000;//location of perm in ordered list (make sure is <= factorial(n))
	const int n=10;//number of digits
	int digits[n],number[n];
	
	for(int i=0;i<n;i++)//fill arrays
	{
		digits[i]=i;
		number[i]=0;
	}

	int dist=loc;
	long long curFac;	

	for(int dig=(n-1);dig>0;dig--)//fill in number array with digits
	{
		int temp=0;
		curFac=factorial(dig);
		while(dist>curFac)
		{
			if(dist-curFac>0)
			{
				temp++;
				dist-=curFac;
			}
		}
		number[(n-dig-1)]=digits[temp];	
		for(int i=temp;i<n-1;i++)//delete element at index and shift array
			digits[i]=digits[(i+1)];
		
	}
	number[n-1]=digits[0];
	for(int i=0;i<n;i++)
		cout<<number[i]<<' ';
	*/
	return 0;
}