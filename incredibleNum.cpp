#include<iostream>
using namespace std;
int incrediblenum(int num)
{
	int flag=0,x=0;
	while(num)
	{
		x=num%10;
		num=num/10;
		if(x < num%10)
		{
			flag=0;
			break;
		}else
		{
			flag=1;
		}
	}
	return flag;
}
int main()
{
	int n;
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		sum+=incrediblenum(i);
	}
	cout<<sum<<endl;
}
