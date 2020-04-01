#include<iostream>
#include<string>
#include<E:\fan\BITree.h>
using namespace std;

bool DoesTree1haveTree2(ptree head1,ptree head2)
{
	if(!head2)
	return true;
	if(!head1)
	return false;
	if(head1->data!=head2->data)
	return false;
	return DoesTree1haveTree2(head1->left,head2->left) && DoesTree1haveTree2(head1->right,head2->right);
}
bool HasSubtree(ptree head1,ptree head2)
{
	if(!head1 || !head2)
	return false;
	bool result=false;
	if(head1->data==head2->data)
	{
		result=DoesTree1haveTree2(head1,head2);
	}
	if(!result)
	{
		result=HasSubtree(head1->left,head2);
	}
	if(!result)
	{
		result=HasSubtree(head1->right,head2);
	}
	return result;
}
int main()
{
	string str1="8(8(9,2(4,7)),7)";
	string str2="8(9,2)";
	ptree head1=Create_BiTree(str1.data());
	PrintLink1(head1);
	cout<<endl;
	ptree head2=Create_BiTree(str2.data());
	PrintLink1(head2);  
	cout<<endl;
	cout << HasSubtree(head1,head2) << endl;
}
