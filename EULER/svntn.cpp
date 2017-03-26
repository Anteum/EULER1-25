#include "connect.h"

string dt(int digit)//digit -> text
{
	switch (digit)
	{
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	default:
		return "error";
	}
}
string dzt(int digit)//digit & zero -> text
{
	switch (digit)
	{
	case 1:
		return "ten";//unused
	case 2:
		return "twenty";
	case 3:
		return "thirty";
	case 4:
		return "forty";
	case 5:
		return "fifty";
	case 6:
		return "sixty";
	case 7:
		return "seventy";
	case 8:
		return "eighty";
	case 9:
		return "ninety";
	default:
		return "error";
	}
}
string odt(int digit)//one & digit -> text
{
	switch (digit)
	{
	case 0:
		return "ten";
	case 1:
		return "eleven";
	case 2:
		return "twelve";
	case 3:
		return "thirteen";
	case 4:
		return "fourteen";
	case 5:
		return "fifteen";
	case 6:
		return "sixteen";
	case 7:
		return "seventeen";
	case 8:
		return "eighteen";
	case 9:
		return "nineteen";
	default:
		return "error";
	}
}
int nthdigit(int num, int n)//returns nth digit of num where n is: ones: 1, tens: 2, hundreds: 3, etc
{
	return (num / int(pow(10, n - 1))) % 10;
}
string inttotext(int num)//works with nums less than 1 000 000 (uses British conventions)
{
	string text = "";
	if (nthdigit(num, 4) > 0 || nthdigit(num, 5) > 0 || nthdigit(num, 6) > 0)
	{
		if (nthdigit(num, 6) > 0)
		{
			text += (dt(nthdigit(num, 6)) + " hundred");//one hundred,two hundred,etc thou
		}
		if (nthdigit(num, 5) > 0 || nthdigit(num, 4) > 0)
		{
			if (nthdigit(num, 6) > 0)
			{
				text += " and ";
			}
			if (nthdigit(num, 5) > 1)
			{
				text += dzt(nthdigit(num, 5));//twenty,thirty,etc thou
				if (nthdigit(num, 4) > 0)
				{
					text += ('-' + dt(nthdigit(num, 4)));//-one,-two,etc thou
				}
			}
			else if (nthdigit(num, 5) == 1)
			{
				text += odt(nthdigit(num, 4));//ten,eleven,twelve,etc thou
			}
			else if (nthdigit(num, 5) == 0)
			{
				text += dt(nthdigit(num, 4));//one,two,etc thou
			}
		}
		text += " thousand";
		if (nthdigit(num, 3) > 0 || nthdigit(num, 2) > 0 || nthdigit(num, 1) > 0)
		{
			text += ", ";
		}
	}
	if (nthdigit(num, 3) > 0)
	{
		text += (dt(nthdigit(num, 3)) + " hundred");//one hundred,two hundred,etc
	}
	if (nthdigit(num, 2) > 0 || nthdigit(num, 1) > 0)
	{
		if (nthdigit(num, 3) > 0 || nthdigit(num, 4) > 0 || nthdigit(num, 5) > 0 || nthdigit(num, 6) > 0)
		{
			text += " and ";
		}
		if (nthdigit(num, 2) > 1)
		{
			text += dzt(nthdigit(num, 2));//twenty,thirty,etc
			if (nthdigit(num, 1) > 0)
			{
				text += ('-' + dt(nthdigit(num, 1)));//-one,-two,etc
			}
		}
		else if (nthdigit(num, 2) == 1)
		{
			text += odt(nthdigit(num, 1));//ten,eleven,twelve,etc
		}
		else if (nthdigit(num, 2) == 0)
		{
			text += dt(nthdigit(num, 1));//one,two,etc
		}
	}
	return text;
}
int svntn()//sum of letters needed to write numbers to 1000
{
	int sum = 0;
	for (int n = 1; n <= 1000; n++)
	{
		string temp = inttotext(n);
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp.substr(i, 1) != " " && temp.substr(i, 1) != "-")//spaces and hypens aren't counted
				sum++;
		}
	}
	cout << sum;
	/*
	int sum=0,temp;
	for(int i=1;i<=1000;i++)
	{
		int ones=0,tens=0,huns=0,thous=0;
		temp=i;
		while(temp>=1000)//split the number into digits
		{
			temp-=1000;
			thous+=1;
		}
		while(temp>=100)
		{
			temp-=100;
			huns+=1;
		}
		while(temp>=10)
		{
			temp-=10;
			tens+=1;
		}
		while(temp>=1)
		{
			temp-=1;
			ones+=1;
		}
		//cout<<thous<<huns<<tens<<ones<<'\n';
		if(ones==1||ones==2||ones==6)//ones
			sum+=3;
		else if(ones==4||ones==5||ones==9)
			sum+=4;
		else if(ones==3||ones==7||ones==8)
			sum+=5;
		if(tens==1)//tens
		{
			sum+=3;
			if(ones==4||ones==6||ones==7||ones==9)
				sum+=1;
		}
		else if(tens==4||tens==5||tens==6)
			sum+=5;
		else if(tens==2||tens==3||tens==8||tens==9)
			sum+=6;
		else if(tens==7)
			sum+=7;
		if((thous!=0||huns!=0)&&(tens!=0||ones!=0))//'and'
			sum+=3;
		if(huns==1||huns==2||huns==6)//hundreds
			sum+=10;
		else if(huns==4||huns==5||huns==9)
			sum+=11;
		else if(huns==3||huns==7||huns==8)
			sum+=12;
		if(thous==1||thous==2)//thousands (only up to 2)
			sum+=11;
	}
	cout<<sum;
	*/
	return 0;
}