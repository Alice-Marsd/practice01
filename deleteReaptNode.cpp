#include<iostream>
#define N  6
#include <E:\fan\createlink.h>
using namespace std;
void DeleteDuplication(elemsn** head)
{
	if(head==NULL||*head==NULL)
	return;
	elemsn *pPreNode=NULL;
	elemsn *pNode=*head;
	while(pNode!=NULL)
	{
		elemsn *pNext=pNode->next;
		bool needDelete =false;
		if(pNext!=NULL &&pNode->data==pNext->data)
		needDelete =true;
		if(!needDelete)
		{
			pPreNode=pNode;
			pNode=pNode->next;
		}else{
			int value=pNode->data;
			elemsn *pDel=pNode;
			while(pDel!=NULL && pDel->data==value)
			{
				pNext=pDel->next;
				delete pDel;
				pDel=NULL;
				pDel=pNext;
			}
			if(pPreNode==NULL)
			{
				*head=pNext;
			}else{
				pPreNode->next=pNext;
			}
			pNode=pNext;
		
		}
	}	
}

int main()
{
	int a[]={1,2,2,3,4,5};
	elemsn* head=createlink(a);
	printlink(head);
	DeleteDuplication(&head);
	printlink(head);
}
