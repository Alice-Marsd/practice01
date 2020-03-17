#include<iostream>
#include <stdexcept>
using namespace std;
struct BinaryTreeNode{
	int 	data;
	BinaryTreeNode* 	left;
	BinaryTreeNode*		right;
}; 

BinaryTreeNode* ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder)
{
	int rootValue=startPreorder[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->data=rootValue;
	root->left=root->right=NULL;
	if(startPreorder==endPreorder)
	{
		if(startInorder == endInorder && *startPreorder == *startInorder)
		return root;
		else
		throw std::logic_error("Invalid input.");
	}
	int *rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder!=rootValue)
	++rootInorder;
	if(rootInorder == endInorder && *rootInorder!=rootValue)
	throw std::logic_error("Invalid input");
	int leftLength=rootInorder-startInorder;
	int *leftPreorderEnd=startPreorder+leftLength;
	if(leftLength>0)
	{
		root->left=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
	}
	if(leftLength < endPreorder-startPreorder)
	{
		root->right=ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
	}
	return root;
}
BinaryTreeNode* Construct(int * preorder,int *inorder,int length)
{
	if(preorder==NULL || inorder==NULL ||length<=0)
	{
		return NULL;
	}
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
void order(BinaryTreeNode* root)
{
	if(root)
	{
		order(root->left);
		order(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
	BinaryTreeNode* head;
	int preorder[10]={1,2,4,7,3,5,6,8};
	int inorder[10]={4,7,2,1,5,3,8,6};
	head=Construct(preorder,inorder,8);
	order(head);
}
