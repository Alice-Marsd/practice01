#include<iostream>
using namespace std;
void Permutation(char* pstr,char* pBegin)
{
	if(*pBegin=='\0')
	printf("%s\t",pstr);
	else
	{
		for(char* pCH=pBegin;*pCH!='\0';++pCH)
		{
			char temp=*pCH;
			*pCH=*pBegin;
			*pBegin=temp;
			Permutation(pstr,pBegin+1);
			temp=*pCH;
			*pCH=*pBegin;
			*pBegin=temp;
		}	
	}
}
void Permutation(char* str)
{
	if(str==NULL)
	return ;
	Permutation(str,str);
}
int main()
{
	char str[]={'a','b','c'};
	//cin>> str;
	Permutation(str);
}
