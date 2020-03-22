#include<iostream>
using namespace std;
 int yueshu(int a)
{
	int count=0;
	for(int i=1;i<a;++i)
	{
		if(a%i==0)
		{
			++count;
		}
	}
	return count;
}
int main()
{
	int a=1200000;
	cout<<yueshu(a)<<endl;
}
