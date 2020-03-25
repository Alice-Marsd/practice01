#include<iostream>
using namespace std;
int main(){
    string ori,tar;
    cin>>ori;
    cin>>tar;
    int N=ori.length();
    int num1=0,num2=0;
    for(int i=0;i<N;i++){
        if(ori[i]=='A' && tar[i]=='T'){
            num1++;
        }
        if(ori[i]=='T' && tar[i]=='A'){
            num2++;
        }
    }
    int result=num1>num2?num1:num2;
    cout<<result<<endl;
    return 0;
}
