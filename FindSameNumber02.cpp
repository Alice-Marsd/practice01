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
		printf("������Ϊ�գ���"); 
		return -1;
	}
	
	for(int i=0;i<length;++i)
	{
		if(numbers[i]>length-1)
		{
			printf("%d���ֲ�����Ҫ��",numbers[i]); 
			return -1;
		} 
	}
	printf("\n------------------�ָ���-------------------------\n");
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
	printf("ѭ����������"); 
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
