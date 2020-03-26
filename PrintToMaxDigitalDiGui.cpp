#include<iostream>
#include<cstring>
using namespace std;
void PrintNumber(char* numbers)
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
void PrintTOMaxOfNDigitsRecursively(char* numbers,int length,int index)
{
	if(index==length-1)
	{
		PrintNumber(numbers);
		return;
	}
	for(int i=0;i<10;++i)
	{
		numbers[index+1]=i+'0';
		PrintTOMaxOfNDigitsRecursively(numbers,length,index+1);
	}
	
}
void PrintToMaxDigital(int num)
{
	if(num<=0)
	return;
	char* number=new char[num+1];
	number[num]='\0';
	for(int i=0;i<10;++i)
	{
		number[i]=i+'0';
		PrintTOMaxOfNDigitsRecursively(number,num,0);
	}
	delete []number;
}
int main()
{
	int num;
	cin>>num;
	PrintToMaxDigital(num);
}
