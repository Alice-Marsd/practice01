#include<stdio.h>
int main()
{
	int a[10000];
	int n;
	int i,j,k,count=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			for(k=j+1;k<n;++k)
			{
				if(a[i]<a[j] && a[j]<a[k])
				{
					count++;
					a[j]=0;
				}
			}
			
		}
	}
	printf("%d",count);	
}
