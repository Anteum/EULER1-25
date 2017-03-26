#include "connect.h"

int twenty()//sum digits of 100 factorial
{
	vector<short> fact(1, 1);//solution will be in reverse
	int sum = 0, carry = 0, size = 1;
	for (int i = 2; i <= 100; i++)//goes thru numbers to be multiplied
	{
		for (int j = 0; j < size; j++)//goes thru digits in vector to multiply with them
		{
			fact[j] = fact[j] * i + carry;
			carry = fact[j] / 10;//carry is digits that "don't fit" in fact[j]
			fact[j] %= 10;//leave only fitting digit
		}
		if (carry > 0)//any remaining carry must be appended to end
		{
			fact.push_back(carry % 10);
			if (carry > 9)
				fact.push_back(carry / 10);
			carry = 0;
		}
		size = fact.size();//update size here so j doesn't get carried away
	}
	for (int x : fact)//<- a range-for-loop 
		sum += x;
		//cout << x << ' ';
	cout << sum;
	/*//done with arrays originally
	int leadInd,temp,bonus=0,bonus2=0,sum=0;
	int fact[158];//fits 100 factorial
	int copy[158];
	for(int i=0;i<158;i++)//fill with zeroes
	{
		fact[i]=0;
		copy[i]=0;
	}
	fact[157]=1;
	for(int n=1;n<=99;n++)//sum of digits of 99! is same as 100!
	{
		for(int i=0;i<158;i++)
		{
			if(fact[i]!=0)
			{
				leadInd=i;
				break;
			}
		}
		for(int j=leadInd;j<158;j++)
		{
			copy[j]=fact[j];
		}
		fact[157]=0;
		for(int k=157;k>=leadInd-2;k--)
		{
			temp=copy[k]*(n%10)+bonus+fact[k];
			fact[k]=temp%10;
			bonus=temp/10;
			temp=copy[k]*(n/10)+bonus2;
			fact[k-1]=temp%10;
			bonus2=temp/10;
		}
		
	}
	for(int i=0;i<158;i++)
			cout<<fact[i];
	for(int i=0;i<158;i++)
			sum+=fact[i];
	cout<<"\n\n"<<sum;
	//*/
	return 0;
}
