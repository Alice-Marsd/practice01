#include<iostream>
#include<cstdio>
using namespace std;
double func(int n,int m,int cnt)
{
	if(n==0)
	return 1;
	if(m<=0)
	return 0;
	//A 成功 
	double result=(n*1.0)/(m+n);
	//A 不成功 
	double tmp=(m*1.0)/(m+n);
	m--;
	if(m==0)
	return result;
	//B 取不成功 
	tmp *=(m*1.0)/(m+n);
	m--;
	//B  二次取 
	tmp*=((n*1.0)/(n+m) * func(n-1,m,cnt+1) + (m*1.0)/(n+m) * func(n,m-1,cnt+1)); 
	
	return result+tmp;
}
int main()
{
	int m,n;
	printf("%.4lf",func(2,3,0));
}
