#include<iostream>
using namespace std;
int zhiyingshu1(int n)
{
	int count=0;
	if(n>1)
	{
		int i;
		for(i=2;n%i;++i);
		if(i>=2)
		{
			++count;
			count+=zhiyingshu1(n/i);
		}			
	}
    return count;
}
int zhiyingshu2(int n)
{
	int count=0;
	int i=2;
	while(n>=2)
	{
		if(n%i==0)
		{
			++count;
			n/=i;
			i=2;			
		}else{
			++i;
		}
		
	}
	return count;
}
int main()
{
    int n;
    cin>>n;
    int sum=0;
 
    for(int i=2;i<=n;++i)
    {
    	sum+= zhiyingshu2(i);
	} 
	cout<<sum <<endl;
}
