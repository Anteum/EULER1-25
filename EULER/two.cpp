#include "connect.h"

int two()//sum even fibonaccis < 4 000 000
{
	int front=1, second=0, temp=0, evenSum=0;
	temp = front+second;
	//cout<<second<<" "<<first<<" ";
	while (temp < 4000000)//
	{
		if(temp%2==0)
		{
			evenSum+=temp;
		}
		second=front;
		front=temp;
		//cout<<temp<<" ";
		temp = front+second;
	}
	cout<<evenSum;
	return 0;
}
