#include<iostream>
using namespace std;
int havenine(int num)
{
	int wei=0;
	int flag=0;
	while(num)
	{
		wei=num%10;
		num=num/10;
		if(wei==9)
		{
			flag=1;	
			break;
		}
	}
	return flag;
}
int main()
{
	int i,n;
	n=2019;
	int sum=0;
	for(i=1;i<=n;++i)
	{
		sum+=havenine(i);
	}
	cout<<sum<<endl;
}
