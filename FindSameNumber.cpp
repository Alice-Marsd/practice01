#include<stdio.h>
//�ҳ��ظ������� 
bool duplicate(int numbers[],int length,int *p)
{
	if(numbers==NULL||length<0)
	{
		printf("����Ϊ�գ���") ;
		return false;
	}
	for(int i=0;i<length;i++)
	{
		printf("%d\t",numbers[i]);
		if(numbers[i]<0||numbers[i]>length-1)
		{ 
			printf("%d�������ֲ���ȷ",numbers[i]); 
			return false;
		} 
	}
	printf("\n");
	for(int i=0;i<length;i++)
	{
		while(numbers[i]!=i)
		{
			if(numbers[i]==numbers[numbers[i]])
			{
				printf("Find it!!");
				*p=numbers[i];
				printf("Find out!!");
				return true;
			}
			int temp=numbers[i];
			numbers[i]=numbers[temp];
			numbers[temp]=temp;
			for(int c=0;c<length;c++)
			{
				printf("%d\t",numbers[c]);
			}
			printf("\n");
		}
		
	}
}
int main()
{
    int numbers[]={2,3,5,4,3,2,6,7};
    int n;
    int *p;
    for(n=0;numbers[n];++n)
	printf("%d\t",n);
	printf("\n");
     
   	duplicate(numbers,n-1,p) ;
   	
	return 0;
}
 
