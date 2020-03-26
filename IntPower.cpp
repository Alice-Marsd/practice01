#include<iostream>
using namespace std;
double PowerWithUnsignedExponent(double base,unsigned int exp)
{
	if(exp==0)
	return 1;
	if(exp==1)
	return base;
	double result=PowerWithUnsignedExponent(base,exp>>1);
	result*=result;
	if(exp&0x1 ==1)//ÆæÊıÎ» 
		result *=base;
	return result;
}
//{
//	double result=1.0;
//	for(int i=0;i<exp;++i)
//	{
//		result*=base;
//	}
//	return result;
//	
//}
bool g_InvalidInput = false;
double Power(double base,int exp)
{
	g_InvalidInput = false;
	if(base==0 && exp<=0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exp);
	if(exp<0)
		absExponent=(unsigned int)(-exp);
	double result=PowerWithUnsignedExponent(base,absExponent);
	if(exp<0)
	 result=1.0/result;
	 return result;
}

int main()
{
	double base;
	int exp;
	cin >> base >>exp;
	cout << Power(base,exp) << endl;
}
