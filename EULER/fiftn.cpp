#include "connect.h"

long long factorial (int n)//factorial function (n!)  //long long overflows for n>20
{
	if (n > 1)
		return (n * factorial (n-1));
	else if (n==1)
		return 1;
	else
		return 0;
}

int fiftn()//count the paths through a grid starting in one corner to opposite and getting closer each step
{
	/*
	const int nSize=20;
	long long pathSum=0,temp=0;
	for(int r=0;r<=nSize;r++)
	{
		temp = factorial(nSize) / (factorial(r)*factorial(nSize - r));
		pathSum += temp*temp;//do not remember how this works so rewrote program below
		cout << temp << ' ';
	}
	//cout<<factorial(nSize);
	cout<<endl<<pathSum;
	//*/

	//have determined that grid paths are equal to sum of pascal's tri overlayed on grid + 1
	//will create "pascal square" array and sum
	const int gridSize = 20;
	long long grid[gridSize][gridSize], sum = 0;
	for (int i = 0; i < gridSize; i++)//start pascal square and sum
	{
		grid[0][i] = 1;
		sum++;
		grid[i][0] = 1;
		sum++;//counts grid[0][0] twice resulting in +1 which was needed anyway at some point
	}
	for (int i = 1; i < gridSize; i++)//fill in square and sum too
	{
		for (int j = 1; j < gridSize; j++)
		{
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			sum += grid[i][j];
		}
	}
	cout << sum << endl;
	//cout << factorial(2 * gridSize) / (factorial(gridSize)*factorial(gridSize));
	return 0;
}