#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
#include<E:\fan\BITree.h>
using namespace std;
void PrintInline(ptree root)
{
	if(!root)
	return ;
	std::deque<ptree> dequeTreeNode;
	dequeTreeNode.push_back(root);
	while(dequeTreeNode.size())
	{
		ptree pNode=dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%5c",pNode->data);
		if(pNode->left)
		dequeTreeNode.push_back(pNode->left);
		if(pNode->right)
		dequeTreeNode.push_back(pNode->right);
	}
	
	
}
int main()
{
	string str="8(6(5,7),A(9,B)";
	ptree root=Create_BiTree(str.data());
	PrintInline(root);
	
}
