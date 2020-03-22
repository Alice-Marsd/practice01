#include<stdio.h>
void growCore(char* grass,int m,int n,int i,int j,int k,bool* visited)
{
	if(grass==NULL||m<0||n<0||i<m||j<n||k<0||i>0||j>0||!visited[m*i+j])
	return;
	if(k>0)
	{
		visited[m*i+j]=1;
		grass[m*i+j]='g';
		growCore(grass,m,n,i+1,j,k-1,visited);
		growCore(grass,m,n,i-1,j,k-1,visited);
		growCore(grass,m,n,i,j+1,k-1,visited);
		growCore(grass,m,n,i,j-1,k-1,visited);
		
	}
}
void grow(char* grass,int m,int n,int k)
{
	if(grass==NULL||m<0||n<0||k<0)
	return;
	bool* visited=new bool[m*n];
	for(int i=0;i<m*n;++i)
		visited[i]=0;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(grass[i*m+j]=='g')
			{
				growCore(grass,m,n,i,j,k,visited);
			}
		}
	}
	for(int i=0;i<m;++i)
	{
	for(int j=0;j<n;++j)
		{
			//printf("%c",grass[i*m+j]);
			printf("%d",visited[i*m+j]);
		}
		printf("\n");
	}
}
int main()
{
	char grass[1000000];
	int m,n,k;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%c",&grass[i*m+j]);
		}
	}
	scanf("%d",&k);
	grow(grass,m,n,k);
	

}
