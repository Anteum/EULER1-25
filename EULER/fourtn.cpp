#include "connect.h"

int fourtn()//find longest Collatz sequence with start under 1 000 000
{
	int seqLength, maxLength = 0, maxInt = 0;
	long long n;
	for(int i=2;i<=1000000;i++)
	{
		n = i;
		seqLength = 1;
		//cout<<'.'<<'\n'<<n<<' ';
		while(n>1)
		{		
			if(n%2==0)//definition of Collatz seq
				n = n / 2;
			else
				n = 3 * n + 1;
			seqLength++;
			//cout<<n<<' ';
		}
		if(seqLength>=maxLength)
		{
			maxLength = seqLength;
			maxInt = i;
		}
		//cout<<' '<<seqLength<<'\n';//<<maxInt<<" has seq length: "<<maxLength<<'\n';
	}
	cout << '\n' << maxInt << " gave max length: " << maxLength << '\n';
	return 0;
}