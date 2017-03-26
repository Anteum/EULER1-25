#include "connect.h"

const int sizeLim = 1000;//what n = when fibo[0] != 0 
int leadInd = 0;//(fibonacci num grows from right to left, when it reaches left end, its length has become sizeLim)
void arraySum(int array1[],int array2[],int sum[])//array2>=array1
{
	int temp;
	for(int i=0;i<sizeLim;i++)//find used length of array2
	{
		if(array2[i]!=0)
		{
			leadInd=i;
			break;
		}
	}
	for(int i=0;i<sizeLim;i++)//zero out sum array
		sum[i]=0;
	for(int i=sizeLim-1;i>=leadInd-1;i--)//right to left
	{
		temp=array1[i]+array2[i];
		if(temp+sum[i]>=10)
		{
			sum[i]=(temp+sum[i])%10;
			sum[i-1]=1;//the addition of 2 single digits only requires a carry of max of 1
		}
		else
			sum[i]+=temp;
	}
}

void dispArray(int array[])//basic array displayer
{
	for(int i=0;i<sizeLim;i++)
		cout<<array[i]<<' ';
	cout<<endl;
}

int twyfiv()//the location in the fibonacci sequence of the first 1000 digit element
{
	int rFibo[sizeLim]={},pFibo[sizeLim]={},sFibo[sizeLim]={};//all array elements are initialized to the int default of 0
	int n=0;//fibo seq index
	bool done=false;
	rFibo[sizeLim-1]=1,pFibo[sizeLim-1]=1;//first 2 elements of fib. seq.
	n++,n++;
	while(!done)//r, p, s go in loop ("rock, paper, scissors")
	{	
		arraySum(rFibo,pFibo,sFibo);//r+p->s
		n++;
		//dispArray(sFibo);
		if (sFibo[0] != 0)//fibo seq has reached 1000 digits
			break;
		
		arraySum(pFibo,sFibo,rFibo);//p+s->r
		n++;
		//dispArray(rFibo);
		if (rFibo[0] != 0)
			break;
			
		arraySum(sFibo,rFibo,pFibo);//s+r->p
		n++;
		//dispArray(pFibo);
		if (pFibo[0] != 0)
			break;
	}
	cout<<endl<<n;

	return 0;
}