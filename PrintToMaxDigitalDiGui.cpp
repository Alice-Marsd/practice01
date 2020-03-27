#include<iostream>
#include<cstring>
//�����Ƕ���������λ��0-9���ֵ�������� 
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
void PrintTOMaxOfNDigitsRecursively(char* number,int length,int index)
{
	//�ݹ������ߵ�ÿλ���� 
	if(index == length-1)
	{
		PrintNumber(number);
		return;
	}
	for(int i=0;i<10;++i)
	{
		number[index+1]=i+'0';
		PrintTOMaxOfNDigitsRecursively(number,length,index+1);
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
		number[0]=i+'0';//�����ǵ�0�����ֵĿ��ƣ����� 
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
