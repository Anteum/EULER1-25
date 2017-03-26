#include "connect.h"

int eightn()//find path with greatest sum thru the pyramid (numtri.txt)
{
	int tri[15][15],maxPath=0;
	char paths[14][16384];//14 possible choices create 16384 (2^14) possible paths of 14 instructions
	bool goDown=false;
	ifstream ints;
	ints.open("numtri.txt");
	cout<<'\n';
	for(int i=0;i<15;i++)//fill triarray
	{
		for(int j=0;j<=i;j++)
		{
			ints>>tri[i][j];
		}
	}
	ints.close();
	for(int i=0;i<14;i++)//create array of all possible paths
	{
		for(int j=0;j<16384;j++)//create special pattern of all combinations of d & r
		{
			int temp=pow(2,(13-i));//decreasing powers of 2 determine when to switch between d & r
			if(j%temp==0)
				goDown=!goDown;
			if(goDown==true)
				paths[i][j]='d';//down
			else
				paths[i][j]='r';//(down) & right
		}
	}
	///*
	for(int i=0;i<16384;i++)//take the paths
	{
		int x=0,y=0,pathSum=tri[x][y];//every path starts with first number
		for(int j=0;j<14;j++)
		{
			if(paths[j][i]=='d')//down
				x++;
			else if(paths[j][i]=='r')//(down) & right
			{
				x++;
				y++;
			}
			pathSum+=tri[x][y];
		}
		if(pathSum>maxPath)
			maxPath=pathSum;
	}
	cout<<maxPath<<" BOOM!";
	//*/
	/*
	for(int j=0;j<16384;j++)//print path array
	{
		for(int i=13;i>=0;i--)
		{
			cout<<paths[i][j]<<' ';
		}
		cout<<'\n';
	}
	//*/
	/*
	for(int i=0;i<15;i++)//print triarray
	{
		for(int j=0;j<=i;j++)
		{
			if(tri[i][j]<10)
				cout<<'0';
			cout<<tri[i][j]<<' ';
		}
		cout<<'\n';
	}
	//*/
	
	return 0;
}