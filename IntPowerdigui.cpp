#include<iostream>
using namespace std;
double Power(double base,int exp)
{
	if(base==0 && exp<0)
	return 0.0;
	if(base==1||exp==0)
	return 1.0;

	unsigned int absExponent = (unsigned int)(exp);
	if(exp<0)
	absExponent = (unsigned int)(-exp);
	double result=base*Power(base,absExponent>>1);
	return exp>0?result:(1/result);
}
int main()
{
	double base;
	int exp;
	cin>>base>>exp;
	cout<<Power(base,exp)<<endl;
}
