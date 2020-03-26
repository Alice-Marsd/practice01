#include<iostream>
#include<cstring>
using namespace std;
bool Increment(char* number)
{
	bool isOverflow false;
	int nTakeOver=0;
	int nLength=strlen(number);
	for(int i=nLength-1;i>=0;--i)
	{
		int nSum=number[i]-'0'-nTakeOver;
		if(i==nLength-1)
		 nSum++;
		 
	}
}
void PrintNumber(int num)
{
	if(num<=0)
	return ;
	char *number=new char[num+1];
	memset(number,'0',n);
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
