#include "connect.h"

/*
int summ(int end)//sigma n=1 to end
{
	if (end <= 0)
		return 0;
	else
		return summ(end - 1) + end;
}
int mtdiag(int min, int max)//returns sum of hypotenuse of mttrisum tri
{
	if (max <= min)
		return min;
	else
		return mtdiag(min, max - 1) + summ(max) - summ(min - 1);
}
int mttrisum(int min, int max)//returns sum of products on mult. table within isos. r. tri. with r. ang. at min and other at max
{
	int total = 0;
	for (int i = max; i >= min; i--)
	{
		for (int j = i; j >= min; j--)
		{
			total += summ(j)-summ(min-1);
		}
	}
	return total;
}
*/

int six()//difference between (1+2+3+...)^2 and 1^2+2^2+3^2+...with 100 terms...
{
	/*
	(1+2+3+...n)^2 is the sum of all entries in a n x n multiplication table
	1^2+2^2+3^2+...n^2 is the sum of the diagonal of a n x n multiplication table
	so the difference is every entry except the diagonal
	*/
	int sum = 0, temp = 0;//my solution using only addition
	for (int i = 1; i <= 100; i++)
	{
		temp = 0;
		for (int j = i + 1; j <= 100; j++)
		{
			temp += j;
		}
		for (int j = 1; j <= i; j++)
		{
			sum += temp;
		}
	}
	cout << sum + sum << endl;
	/*
	int total = mttrisum(1,199)-2*mttrisum(101,199);
	for (int i = 1; i <= 100; i++)
		total -= i*i;
	cout << total;
	//*/
	/*
	int total = 0;
	const int max = 100;
	for (int i = 1; i <= max; i++)
	{
		for (int j = i+1; j <= max; j++)
			total += i*j*2;
	}
	cout << total;
	*/
	
	/*
	int sumSqs=0,sqdSum=0;
	for(int i=1;i<=100;i++)
	{
		sumSqs+=i*i;
		sqdSum+=i;
	}
	sqdSum=sqdSum*sqdSum;
	cout<<sqdSum<<'\n'<<sumSqs<<'\n'<<sqdSum-sumSqs;
	*/
	return 0;
}