#include "connect.h"

int one()//sum multiples of 3 & 5
{
	const int limit = 1000;
	int sum=0;
	
	for(int i=0;i<limit;i++)
	{
		if (i%3==0)
		{
			sum += i;
		}
		else if(i%5==0)
		{
			sum += i;	
		}
	}

	cout<<sum;
	
	return 0;
}