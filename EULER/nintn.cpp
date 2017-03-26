#include "connect.h"

int dayOfWeek(int day,int month,int year)//returns day of week (1-7~Sun-Sat) between Jan 1,1900 and Feb 28,2100
{
	int totalTimeInDays=0,newDOW;
	const int dStart=1,mStart=1,yStart=1900;//Jan 1, 1900 was a monday
	bool leap=false;
	int dCur=dStart,mCur=mStart,yCur=yStart;
	while(!(dCur==day&&mCur==month&&yCur==year))
	{
		if(mCur==2&&dCur==28&&leap==false)//feb
		{
			dCur=1;
			mCur++;	
			totalTimeInDays++;
		}		
		else if(mCur==2&&dCur==29)//feb(leap)
		{
			dCur=1;
			mCur++;	
			totalTimeInDays++;
		}	
		else if(dCur==30&&(mCur==4||mCur==6||mCur==9||mCur==11))//apr,jun,sep,nov
		{
			dCur=1;
			mCur++;	
			totalTimeInDays++;
		}
		else if(dCur==31)//&&(mCur==1||mCur==3||mCur==5||mCur==7||mCur==8||mCur==10||mCur==12))
		{
			dCur=1;
			mCur++;
			totalTimeInDays++;		
			if(mCur==13)//wrap months over to next year
			{				
				mCur=1;
				yCur++;
				if(yCur%4==0)
					leap=true;
				else
					leap=false;
			}
		}
		else//default day forward
		{
			totalTimeInDays++;
			dCur++;
		}

	}
	newDOW = (totalTimeInDays + 1) % 7 + 1;//+1 shifts start date from mon to sun and then +1 makes 0-6 -> 1-7
	return newDOW;
}

int nintn()//how many months start with sunday in 20th century
{
	//cout<<"Day of week: "<<dayOfWeek(14,2,2013)<<'\n';
	int sundays=0;
	for(int i=1;i<=12;i++)
	{
		for(int j=1901;j<=2000;j++)
		{
			if(dayOfWeek(1,i,j)==1)
				sundays++;
		}
	}
	cout<<sundays;
	return 0;
}