#include<iostream>
using namespace std;
void CombinationCore(char* begin,char* end)
{
	if(begin==end)
	{
		return ;
	}
	else{
		for(char* p=begin;p<=end;++p)
		{			
			CombinationCore(p+1,end);
			printf("%c",*p);	
		}
		cout<<endl;
	}
}
void Combination(char* str)
{
	if(str==NULL)
	return ;
	for(char* p=str;(*p)!='\0';++p)
	{
		CombinationCore(str,p);
	}
}
int main()
{
	char str[]={'a','b','c'};
	Combination(str);
}
