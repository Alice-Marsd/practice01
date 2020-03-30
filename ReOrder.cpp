#include<iostream>
using namespace std;
bool func(int n)
{
	return (n & 0x1);
}
void ReorderOddEven(int *data,int length)
{
	if(data==NULL ||length==0)
	return;
	int *pBegin=data,*pEnd=data+length-1;
	while(pBegin<pEnd)
	{
		while(pBegin<pEnd && func(*pBegin))
		++(pBegin);
		while(pBegin<pEnd && !func(*pEnd))
		--(pEnd);
		if(pBegin<pEnd)
		{
			int temp;
			temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}
void printlink(int data[],int len)
{
	for(int i=0;i<len;++i)
	cout<<data[i];
	cout<<endl;

}
int main()
{
	int data[]={1,2,3,4,5};
	printlink(data,5);
	ReorderOddEven(data,5);
	printlink(data,5);
}
