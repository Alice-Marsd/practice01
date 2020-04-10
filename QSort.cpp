#include<iostream>
using namespace std;
void Swap(int* p1,int* p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int Partition(int* number,int n,int start,int end)
{
	int index=start;
	Swap(&number[index],&number[end]);
	int small=start-1;
	for(int index=start;index < end;++index)
	{
		if(number[index]<number[end])
		{
			small++;
			if(index!=small)
			Swap(&number[index],&number[small]);
		}
	}
	small++;
	Swap(&number[small],&number[end]);
	return small;
}
void QuickSort(int* number,int n,int start,int end)
{
	if(start==end)
	return ;
	int index=Partition(number,n,start,end);
	if(index>start)
		QuickSort(number,n,start,index-1);
	if(index<end)
		QuickSort(number,n,index+1,end);
}
int main()
{
	int number[100];
	int n;
	cin >>n;
	for(int i=0;i<n;++i)
	cin >> number[i]; 
	QuickSort(number,n,0,n-1);
	for(int i=0;i<n;++i)
	cout <<number[i] <<" ";
 } 
