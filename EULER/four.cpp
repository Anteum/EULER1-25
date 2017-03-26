#include "connect.h"

int four()//find largest palindromic product of two 3 digit numbers
{
	int product, tcudorp, power, rpower, max=0;
	//int ones, tens, hunds, thous, tenths, hunths;

	for(int i=100;i<1000;i++)
	{
		for(int j=i;j<1000;j++)
		{
			product = i*j;//product is 5 or 6 digits
			tcudorp = 0, rpower=0;
			if (product < 100000)//if product is 5 digits
				power = 4;//product is on order of 10^4
			else
				power = 5;//product is on order of 10^5
			int y = product;
			for (int x = power; x >= 0; x--)//for each digit in product starting from left
			{
				while(y >= pow(10, x))//while there is still at least one in the powers place of product
				{
					tcudorp += int(pow(10, rpower));//add one to rpowers place of tcudorp
					y -= int(pow(10, x));//subtract one from powers place
				}//this takes the digits from a copy of product and places them in reverse into tcudorp
				rpower++;
			}
			if (product == tcudorp && product > max)//if product is largest palindrome so far
				max = product;
			/*ones=0,tens=0,hunds=0,thous=0,tenths=0,hunths=0;
			
			while(product>100000)
			{
				product-=100000;
				hunths+=1;
			}
			while(product>10000)
			{
				product-=10000;
				tenths+=1;
			}
			while(product>1000)
			{
				product-=1000;
				thous+=1;
			}
			while(product>100)
			{
				product-=100;
				hunds+=1;
			}
			while(product>10)
			{
				product-=10;
				tens+=1;
			}
			while(product>0)
			{
				product-=1;
				ones+=1;
			}
			if(i*j<100000)
			{
				if(ones==tenths && tens==thous )
				{
					cout<<i*j<<" ";
				}
			}
			else if(ones==hunths && tens == tenths && hunds==thous)
			{
				cout<<i*j<<"  ";
			}
			*/
		}
	}
	cout << max;

	return 0;
}
