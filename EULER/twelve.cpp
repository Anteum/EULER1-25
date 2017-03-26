#include "connect.h"

int twelve()//1st triangle number with >500 factors
{
	int tri = 6, factors;
	const int howManyFactorsYouWant = 500;
	//cout << "Loading..." << endl;
	for(int i = 4; i < 1000000; i++)
	{
		factors = 2;
		for(int j = sqrt(tri); j > 1; j--)
		{		
			if(tri % j == 0)
			{
				factors += 2;//square numbers have a double factor...counts as 2 or 1?
				if(factors > howManyFactorsYouWant)
					goto Finish;					
			}
		}
		//cout<<tri<<"   "<<factors<<endl;
		tri += i;
	}
	Finish:
		cout<<tri<<" has at least "<<factors;
	return 0;
}