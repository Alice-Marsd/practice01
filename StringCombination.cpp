#include<iostream>
using namespace std;
void Combination(char* pstr,char* pBegin,int len)
{
	if(*pBegin=='\0')
	printf("%s\n",pstr);
	else{
		
		for(int i=0;i<len;++i)
		{
			printf("%s\n",pBegin+i);
			Combination(pstr,pBegin+1,len+1);
		}
	
		
	}
}
void Combination(char* str)
{
	if(str==NULL)
	return ;
	Combination(str,str,1);
}
int main()
{
	char str[]={'a','b','c'};
	Combination(str);
}
