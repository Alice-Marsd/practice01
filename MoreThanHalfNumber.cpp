#include<iostream>
using namespace std;
bool Check(int *a,int n)
{
	bool Invalid=false;
	if(!a||n<0)
		Invalid=true;
	
	return Invalid;
}
int Partition(int *a,int len,int start,int end)
{
	int small=start-1;
	int index=start;
	int temp=a[index];
		a[index]=a[end];
		a[end]=temp;
	for(index=start;index<end;++index)
	{
		if(a[index]<a[end])
		{
			++small;
			if(small!=index)
			{
				temp=a[index];
				a[index]=a[small];
				a[small]=temp;
			}
		}
	}
	++small;	
	temp=a[end];
	a[end]=a[small];
	a[small]=temp;
	return small;
}
bool CheckMoreThanHalf(int* a,int len,int result)
{
	int count=0;
	for(int i=0;i<len;++i)
	{
		if(a[i]==result)
		++count;
		
	}
	if(2*count<=len)
	return false;
	else
	return true;
}
int MoreThanHalfNum(int *a,int len)
{
	if(Check(a,len))
	return 0;
	int middle=len>>1;
	int start=0;
	int end=len-1;
	int index=Partition(a,len,start,end);
	while(index != middle)
	{
		if(index > middle)
		{
			end=index-1;
			index=Partition(a,len,start,end);
		}else{
			start=index+1;
			index=Partition(a,len,start,end);
		}
	}
	int result=a[middle];
	if(!CheckMoreThanHalf(a,len,result))
	result=0;
	return result;
}
int main()
{
	int n=9;
	int a[]={2,3,1,2,2,2,5,4,2};
//	cin>>n;
//	cin>>a;
	cout <<MoreThanHalfNum(a,n)	<<endl;
	
	
	
}
