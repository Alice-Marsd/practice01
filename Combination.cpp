#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
void combinationCore(char* string,int number,vector<char>& result); 
void Combination(char* string) 
{
	if(string == NULL)
	return;
	vector<char> result;
	int length = strlen(string);
	for(int i = 1 ; i <= length; i++)
	{
		combinationCore(string,i,result);
	}
}
void combinationCore(char* string,int number,vector<char>& result)
{
	if(string == NULL)
	return;
	if(number == 0)
	{
		for(int i = 0; i < result.size();i++)
		{
			cout<<result[i];
		 } 
		 cout<<" ";
		 return;
	}
	if(*string == '\0')
	return;
	result.push_back(*string);
	combinationCore(string+1,number-1,result);
	result.pop_back();
	combinationCore(string+1,number,result);
	
}
int main()
{
	char str[]={'a','b','c'};
	Combination(str);
}
