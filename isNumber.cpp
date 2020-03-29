#include<iostream>
using namespace std;

bool scanUnsignedInteger(const char **str)
{
	const char *before=*str;
	while(**str!='\0' && **str<='9')
	++(*str);
	return *str>before;
}
bool scanInteger(const char **str)
{
	if(**str=='+' || **str=='-')
	++(*str);
	return scanUnsignedInteger(str);
}
bool isNumber(const char* str)
{
	if(str==NULL)
	return false;
	bool numberic=scanInteger(&str);
	if(*str == '.')
	{
		++str;
		numberic=scanUnsignedInteger(&str) || numberic;
	}
	if(*str=='e' || *str=='E')
	{
		++str;
		numberic=numberic&&scanInteger(&str); 
	}
	return numberic&&*str=='\0';
}
int main()
{
	char str[100];
	cin >> str;
	cout <<isNumber(str);
}
