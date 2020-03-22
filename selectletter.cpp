#include<iostream>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int flag=0,count=0;
    for(int i=0;str[i];++i)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            if(flag)
            {
            	count++;
            	flag=0;
			}
            
        }else{
           if(!flag)
           {
           	count++;
           	flag=1;
		   }
        }
    }
    if(count==4)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;  
}
