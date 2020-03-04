#include <stdio.h>
void replace(char string[],int length)
{
	int count=0,i;
	if(string==NULL || length<0)
	{
		printf("×Ö·û´®Îª¿Õ£¡£¡");
		return ;
	}
	for(i=0;i<length;++i)
	{
		if(string[i]==' ')
		++count;
	}
	printf("%d\n",count);
	while(count!=0)
	{
		if(string[i]==' ')
		{
			string[2*count+i]='0';
			string[2*count+i-1]='2';
			string[2*count+i-2]='%';
			--count;
			
		}
		else{
			string[2*count+i]=string[i];
		}
		--i;	
	}
	for(i=0;string[i];++i)
	printf("%c",string[i]);
}
int main()
{
	char string[]=" We are happy.  ";
	int i;
	for(i=0;string[i];++i);
	printf("%d\n",i);
	replace(string,i);
} 
