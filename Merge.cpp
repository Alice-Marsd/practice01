#include<iostream>
#define N  4
#include <E:\fan\createlink.h>
using namespace std;
elemsn* combine(elemsn *head1,elemsn *head2)
{
	if(head1==NULL)
	return head2;
	else if(head2==NULL)
	return head1;
	elemsn* pHead=NULL;
	if(head1->data  > head2->data)
	{
		pHead=head2;
		pHead->next=combine(head1,head2->next);
	}else
	{
		pHead=head1;
		pHead->next=combine(head1->next,head2);
	}
	return pHead;
	
}
int main()
{
	int a[]={1,3,5,7};
	int b[]={2,4,6,8};
	elemsn* head1=createlink(a);
	printlink(head1);
	elemsn* head2=createlink(b);
	printlink(head2);
	
	head1=combine(head1,head2);
	printlink(head1);
	
}
