#include<iostream>
#include<cmath>
using namespace std;
int array[100001]={0,0};
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i=2;i<100001;i++)
		{
			array[i]=1;
		}
		int result=0;
		for(int a=4;a<=n;++a)
		{
			int i;
			int tmp=sqrt(a);
			for(i=2;i<=tmp;++i)
			{
				if(a%i==0)
				{
					array[a]=array[i]+array[a/i];
					break; 
				}
			}
		}
		for(int i=2;i<=n;i++)
		{
			result +=array[i];
		}
		cout<<result<<endl;
	}
}
