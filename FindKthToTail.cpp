#include<iostream>
#define N  7
#include <E:\fan\createlink.h>
using namespace std;

elemsn* FindKthToTail(elemsn *head,int k)
{
	if(head==NULL || k<=0)
	return NULL;
	elemsn *pAhead=head,*pBehind;
	for(int i=0;i<k-1;++i)
	{
		if(pAhead->next)
		{
			pAhead=pAhead->next;
		}else{
			return NULL;
		}
	}
	pBehind=head;
	while(pAhead->next)
	{
		pAhead=pAhead->next;
		pBehind=pBehind->next;
	}
	return pBehind;
}
int main()
{
	int a[]={1,2,3,4,5,6};
	elemsn *head=createlink(a) ;
	printlink(head);
	cout<<FindKthToTail(head,3)->data<<endl;
}
