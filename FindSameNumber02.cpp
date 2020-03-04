#include<stdio.h>
int countRange(const int *numbers,int length,int start,int end)
{
	if(numbers==NULL)
	return 0;
	int count=0;
	for(int i=0;i<length;++i)
	{
		if(numbers[i]>=start && numbers[i]<=end)
		++count;
	}
	return count;
	
}
int getduplicate(const int *numbers,int length)
{
	if(numbers==NULL || length<0)
	{
		printf("该数组为空！！"); 
		return -1;
	}
	
	for(int i=0;i<length;++i)
	{
		if(numbers[i]>length-1)
		{
			printf("%d数字不符合要求",numbers[i]); 
			return -1;
		} 
	}
	printf("\n------------------分割线-------------------------\n");
	int start=0;
	int end=length-1;
	while(end>=start)
	{
		printf("start--->%d,end--->%d\t",start,end); 
		int middle=((end-start)>>1)+start;
		printf("middle---->%d\t",middle);
		int count=countRange(numbers,length,start,middle);
		printf("count--->%d\t",count);
		if(start==end)
		{
			if(count>1)
				return start;
			else
				break;	
		}
		if(count > (middle-start))
			end=middle;
		else
			start=middle+1;
		printf("\n");
	}
	printf("循环结束！！"); 
	return -1;
	
}
int main()
{
	const int numbers[]={2,3,5,4,3,2,6,7};
	int n;
	int b;
    for(n=0;numbers[n];++n)
	printf("%d\t",n);
	printf("\n");
    for(n=0;numbers[n];++n)
	printf("%d\t",numbers[n]);
	printf("\n");
   	b=getduplicate(numbers,n-1) ;
   	printf("b------->%d",b);
}
