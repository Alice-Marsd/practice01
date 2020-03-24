#include<stdio.h>
#include<stack>
typedef struct stack
{
	int *top;
	int maxsize;
}Stack;
int compare(char* origin,char *result)
{
	if(origin==NULL||result==NULL)
	return 0;
	int i=0;
	int *p;
	Stack temp;
	while(origin[i]||result[i])
	{
		if(origin[i]==result[i])
			++i;
		else{
			if(temp.top!=origin[i])
			{	
				temp.
				count++;
			}else{
				temp.push(i);
			}
			
		}
	}
	return count;
}
int main()
{
	char origin[1000000],result[1000000];
	int count=0;
	scanf("%s",&origin);
	scanf("%s",&result);
	count=compare(origin,result);
}
