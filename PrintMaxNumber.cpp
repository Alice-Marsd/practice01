#include<iostream>
#include<cstring>
using namespace std;
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver=0;
	int nLength=strlen(number);
	for(int i=nLength-1;i>=0;--i)
	{
		int nSum=number[i]-'0'+nTakeOver;
		if(i==nLength-1)
		 nSum++;
		 if(nSum>=10)
		 {
		 	if(i==0)
		 		isOverflow = true;
		 	else
			 {
			 	nSum-=10;
			 	nTakeOver=1;
			 	number[i]='0'+nSum;
		 		
			 }
		 }else{
		 	number[i]='0'+nSum;
		 	break;
		 }
	}
	return isOverflow;
}
void PrintNumber(char* number)
{
	bool isBeginning0=true;
	int nLength=strlen(number);
	for(int i=0;i<nLength;++i)
	{
		if(isBeginning0 && number[i]!='0')
			isBeginning0=false;
		if(!isBeginning0)
		{
			printf("%c",number[i]);
		}
	}
	printf("\t");
}
void PrintNumber(int num)
{
	if(num<=0)
	return ;
	char *number=new char[num+1];
	memset(number,'0',num);
	number[num]='\0';
	while(!Increment(number))
	{
		PrintNumber(number);
	} 
	delete []number;
}
int main()
{
	int num;
	cin>>num;
	PrintNumber(num);
 } 
