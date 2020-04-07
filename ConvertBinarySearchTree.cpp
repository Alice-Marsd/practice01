#include<iostream>
#include<E:\fan\BITree.h>
using namespace std;
void ConvertNode(ptree pNode,ptree* pLastNode)
{
	if(!pNode)
	return;
	ptree pCurrent=pNode;
	if(pCurrent->left)
		ConvertNode(pNode->left,pLastNode);
	pNode->left=*pLastNode;
	if(*pLastNode)
		(*pLastNode)->right=pCurrent;
	*pLastNode=pCurrent;
	if(pCurrent->right)
	ConvertNode(pNode->right,pLastNode);
} 
ptree Convert(ptree root)
{
	ptree pLastNode=NULL;
	ConvertNode(root,&pLastNode);
	ptree pHead=pLastNode;
	while(pHead->left&& pHead->left)
	pHead=pHead->left;
	return pHead;
}
void Display(ptree root)
{
	if(root)
	{
		printf("%c",root->data);
		Display(root->right);
	}
}
int main()
{
	ptree root;
	string str="A(6(4,8),E(C,G))";
	root=Create_BiTree(str.c_str());
	root=Convert(root);
	Display(root);
}
