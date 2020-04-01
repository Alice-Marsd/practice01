#include<iostream>
#include<string>
#include<E:\fan\BITree.h>
using namespace std;
void MirrorRecursively(ptree head)
{
	if(!head)
	return ;
	if(!head->left && !head->right)
	return ;
	ptree temp=head->left;
	head->left=head->right;
	head->right=temp;
	if(!head->left)
	MirrorRecursively(head->left);
	if(!head->right)
	MirrorRecursively(head->right);
}
int main()
{
	string str1="8(6(5,7),A(9,B))";
	
	ptree head=Create_BiTree(str1.c_str());
	PrintLink1(head);
	cout<<endl;
	MirrorRecursively(head);
	PrintLink1(head);
	
}
