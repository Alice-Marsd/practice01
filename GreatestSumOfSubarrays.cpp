#include<iostream>
using namespace std;
bool g_InvalidInput=false;
int FindGreatestSumOfSubArray1(int* data,int n)
{
	if(data==NULL || n<=0)
	{
		g_InvalidInput=true;
		return 0;
	}
	
	int Sum=0;
	int max=0;
	for(int i=0;i<n;++i)
	{
		Sum+=data[i];
		if(Sum<0)
		Sum=0;
		if(max<Sum)
			max=Sum;
	}
	return max;
}
int FindGreatestSumOfSubArray2(int* data,int n)
{
	//¶¯Ì¬¹æ»® 
	if(data==NULL || n<=0)
	{
		g_InvalidInput=true;
		return 0;
	} 
	int max[n];
//	int sum=0;
	int i;
	for(i=0;i<n;++i)
	{
		if(i==0 || max[i-1]<=0)
			max[i]=data[i];
		else
		{
			max[i]=max[i-1]+data[i];
		}	
	}
	int maxi=0;
	for(i=0;i<n;++i)
	{
		if(max[i]>maxi)
		maxi=max[i];
	}
	return maxi;
	
}
int main()
{
	int data[]={1,-2,3,10,-4,7,2,-5};
	cout << FindGreatestSumOfSubArray1(data,8) << endl;
	cout << FindGreatestSumOfSubArray2(data,8) << endl;
}
