#include<iostream>
#define N  7
#include <E:\fan\createlink.h>
using namespace std;
elemsn* ReserveList(elemsn *head)
{
	elemsn* phead=NULL;
	elemsn* pPreNode=NULL;
	elemsn* pNode=head;
	
	while(pNode)
	{
		elemsn* pNext=pNode->next;
		if(!pNext)
		phead=pNode;
		pNode->next=pPreNode;
		pPreNode=pNode;
		pNode=pNext;
	}
	return phead;
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	elemsn *head=createlink(a);
	printlink(head);
	head=ReserveList(head);
	printlink(head);
}
