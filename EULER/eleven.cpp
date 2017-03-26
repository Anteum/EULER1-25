#include "connect.h"

int eleven()//grid multiplying
{
	cout<<87*97*94*89<<'\n';//found it by looking...done?
	int max=0,temp=0;
	int grid[20][20];
	ifstream ints;
	ints.open("numgrid.txt");
	for(int i=0;i<20;i++)//create array
	{
		for(int j=0;j<20;j++)
		{
			ints>>grid[i][j];// ">>" extracts characters until whitespace which is ideal here
		}
	}
	for(int i=0;i<20;i++)//print array
	{
		for(int j=0;j<20;j++)
		{
			if(grid[i][j]<10)//add leading 0 to single digit numbers
				cout<<'0';
			cout<<grid[i][j]<<' ';
		}
		cout<<'\n';
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 3; j < 20; j++)
		{
			temp = grid[i][j] * grid[i][j - 1] * grid[i][j - 2] * grid[i][j - 3];//goes left from [i][j]
			if (temp>max)
				max = temp;
		}
	}
	for (int i = 3; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			temp = grid[i][j] * grid[i - 1][j] * grid[i - 2][j] * grid[i - 3][j];//goes up from [i][j]
			if (temp>max)
				max = temp;
		}
	}
	for(int i=3;i<20;i++)//find diagonals
	{
		for(int j=3;j<20;j++)
		{
			temp=grid[i][j]*grid[i-1][j-1]*grid[i-2][j-2]*grid[i-3][j-3];//diag up&left from [i][j]
			if(temp>max)
				max=temp;
			temp=grid[i][j-3]*grid[i-1][j-2]*grid[i-2][j-1]*grid[i-3][j];//makes 'X' with diag up&left
			if(temp>max)
				max=temp;
		}
	}
	ints.close();
	cout<<max;
	return 0;
}