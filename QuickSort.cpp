#include<iostream>
#include<stdexcept>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;
void Swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
int Partition(int data[],int length,int start,int end)
{
	if(data==NULL||length<=0||start<0||end>=length)
	throw std::logic_error("Invalid Paramer");
	int index=start;
	Swap(&data[index],&data[end]);
	int small=start-1;
	for(index=start;index<end;++index)
	{
		if(data[index] < data[end])
		{
			++small;
			if(small!=index)
			Swap(&data[small],&data[index]);
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	return small;
}
void QuickSort(int data[],int length,int start,int end)
{
	if(start==end)
	return;
	int index=Partition(data,length,start,end);
	if(index>start)
		QuickSort(data,length,start,index-1);
	if(index<end)
		QuickSort(data,length,index+1,end);
}
int main()
{
	int data[]={3,2,5,8,4,7,6,9};
	QuickSort(data,8,0,7);
	for(int i=0;i<8;++i)
	{
		printf("%d ",data[i]);
	}
}
