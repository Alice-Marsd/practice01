#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void Combination(char* pstr,int length,vector<char>& result)
{
	if(pstr==NULL)
	return ;
	if(length==0)
	{
		for(int i=0;i<result.size();++i)
		printf("%c",result[i]);
		cout<<endl;
		return ;
	}
	if(*pstr=='\0')
	return ;
	result.push_back(*pstr);
	Combination(pstr+1,length-1,result);
	result.pop_back();
	Combination(pstr+1,length,result);
}
void Combination(char* str)
{
	if(str==NULL)
	return ;
	vector<char> result;
	int len=strlen(str);
	for(int i=1;i<=len;++i)
	Combination(str,i,result);
}
int main()
{
	char str[]={'a','b','c'};
	Combination(str);
}
