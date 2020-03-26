#include<iostream>
#include<cstring>
using namespace std;
bool Increment(char* numbers)
{
	bool isOverFlow=false;
	int  nTakeOver=0;
	int length=strlen(numbers);
	for(int i=length-1;i>=0;--i)
	{
		int nSum=numbers[i]-'0'+nTakeOver;
		if(i==length-1)
		 nSum++;
		if(nSum>=10)
		{
			if(i==0)
			isOverFlow=true;
			else{
				nSum-=10;
				nTakeOver=1;
				numbers[i]='0'+nSum;
			}
		}
		else{
			numbers[i]='0'+nSum;
			break;
		}
	}
	return isOverFlow;
	
}
void Print(char* numbers)
{
	bool isBeginning=false;
	int len=strlen(numbers);
	for(int i=0;i<len;++i)
	{
		if(!isBeginning && numbers[i]!='0')
			isBeginning=true;
		if(isBeginning)
			printf("%c",numbers[i]);
	}
	printf("\t");
}
void PrintToMaxDigital(int num)
{
	if(num<=0)
	return ;
	char* numbers=new char[num+1];
	memset(numbers,'0',num);
	numbers[num]='\0';
	while(!Increment(numbers))
	{
		Print(numbers);
	}
	delete []numbers;
}
int main()
{
	int num;
	cin >> num;
	PrintToMaxDigital(num);
		
} 
