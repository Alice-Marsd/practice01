#include<iostream>
using namespace std;
void DisPlay(bool* visited,int m,int n)
{
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<visited[m*i+j]<<"  "; 
		}
		cout<<endl;
	}
}
int getDigitSum(int num)
{
	int sum=0;
	while(num)
	{
		sum+=num%10;
		num=num/10;
	}
	return sum;
}
bool check(int k,int m,int n,int i,int j,bool* visited)
{
	if(i>=0 && i<m && j<n && j>=0 && getDigitSum(i)+getDigitSum(j)<=k && !visited[m*i+j])
	return true;
	return false;
}
int RangeCore(int  m,int n,int k,int i,int j,bool* visited)
{
	int count=0;
	if(check(k,m,n,i,j,visited))
	{
		visited[m*i+j]=true;
		count=1+RangeCore(m,n,k,i+1,j,visited)+RangeCore(m,n,k,i-1,j,visited)
		+RangeCore(m,n,k,i,j+1,visited)+RangeCore(m,n,k,i,j-1,visited);
	}
		
	return count; 	
}
int range(int m,int n,int k)
{
	if(m<=0||n<=0||k<0)
	return 0;
	bool* visited=new bool[m*n];
	for(int i=0;i<m*n;++i)
	visited[i]=false;
	int count=RangeCore(m,n,k,0,0,visited);
	DisPlay(visited,m,n);
	delete[] visited;
	return count;
	
}

int main()
{
	int m,n,k;
	k=5;
	m=10,n=10;
	cout<<range(m,n,k)<<endl;
}
