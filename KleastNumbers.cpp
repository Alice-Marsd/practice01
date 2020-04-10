#include<iostream>
using namespace std;
void Swap(int* p1,int* p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int Partition(int* input,int n,int start,int end)
{
	int index=start;
	Swap(&input[index],&input[end]);
	int small=start-1;
	for(index=start;index<end;++index)
	{
		if(input[index]<input[end])
		{
			++small;
			if(small!=index)
			Swap(&input[index],&input[small]);
		}
		
	}
	++small;
	Swap(&input[small],&input[end]);
	return small;
	
}
void GetLeastNumber(int* input,int n,int* output,int k)
{
	if( !input || !output || n<=0 || k>n ||k<0)
	return ;
	int start=0;
	int end=n-1;
	int index=Partition(input,n,start,end);
	while(index!=k-1)
	{
		if(index>k-1)
		{
			end=index-1;
			index=Partition(input,n,start,end);
		}else
		{
			start=index+1;
			index=Partition(input,n,start,end);
		}
	}
	for(int i=0;i<k;++i)
	 output[i]=input[i];
	for(int i=0;i<k;++i)
	cout<<output[i]<<" ";
}
int main()
{
	int number[]={4,5,1,6,2,7,3,8};
	GetLeastNumber(number,8,number,4);
	
}
