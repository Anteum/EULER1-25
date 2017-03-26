#include "connect.h"

int nine()//find abc where a^2+b^2=c^2 and a+b+c=1000
{
	int aSqd[261], bSqd[191], cSqd[71];
	for(int i=32;i<293;i++)//isos. r. tri. with perim. 1000 gives max for a, min for b, min for c
	{					//skinniest possible tri. with perim. 1000 gives min for a, max for b, max for c
		aSqd[i-32]=i*i;
		//cout<<i*i<<" ";
	}
	for(int i=293;i<484;i++)
	{
		bSqd[i-293]=i*i;
		//cout<<i*i<<" ";
	}
	for(int i=414;i<485;i++)
	{
		cSqd[i-414]=i*i;
		//cout<<i*i<<" ";
	}
	for(int i=414;i<485;i++)
	{
		for(int j=293;j<484;j++)
		{
			for(int k=32;k<293;k++)
			{
				if (cSqd[i - 414] - bSqd[j - 293] == aSqd[k - 32])
					cout << i << " " << j << " " << k << " " << i + j + k << "  " << i*j*k << endl;
			}
		}
	}
	return 0;
}
