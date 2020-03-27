#include<iostream>
#define N  6
#include <E:\fan\createlink.h>
using namespace std;
void deleteNode(elemsn** head,elemsn* pDel)
{
	if(!head||!pDel)
	return;
	if(pDel->next!=NULL)
	{
		elemsn *p=pDel->next;
		pDel->data=p->data;
		pDel->next=p->next;
		delete p;
		p=NULL;
	}
	else if(*head==pDel)
	{
		delete pDel;
		pDel=NULL;
		*head=NULL;	
	}else{
		elemsn* pNode=*head;
		while(pNode->next!=pDel)
		{
			pNode=pNode->next;
		}
		pNode->next=NULL;
		delete pDel;
		pDel=NULL;
	}
}
int main()
{
	int a[]={1,2,3,4,5,6};
	elemsn *head;
	head=createlink(a);
	printlink(head);
	elemsn *pDel=head;
	
	deleteNode(&head,pDel);
	printlink(head);
	
} 
