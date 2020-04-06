#include<iostream>
#include<vector>
#include<string>
#include<E:\fan\BITree.h>
using namespace std;
void FindPath(ptree root,int exceptedSum,std::vector<char>& path,int currentSum)
{
	int num;
	switch(root->data)
	{
		case 'A':num=10;break;
		case 'B':num=11;break;
		case 'C':num=12;break;
		case 'D':num=13;break;
		case 'E':num=14;break;
		case 'F':num=15;break;
		default:
			num=root->data-'0';
	}
	currentSum+=num;
	path.push_back(root->data);
	bool isleaf=root->left==NULL && root->right==NULL;
	if(isleaf  &&  currentSum==exceptedSum)
	{
		printf("Find Path:");
		std::vector<char>::iterator iter=path.begin();
		for(;iter!=path.end();++iter)
		printf("%c\t",*iter);
		printf("\n");
	}
	if(root->left)
	FindPath(root->left,exceptedSum,path,currentSum);
	if(root->right)
	FindPath(root->right,exceptedSum,path,currentSum);		
	
	path.pop_back();
	
}
void FindPath(ptree root,int expectedSum)
{
	if(!root)
	return ;
	std::vector<char> path;
	int currentSum=0;
	FindPath(root,expectedSum,path,currentSum);	
}
int main()
{
	int expectedSum;
	cin>>expectedSum;
	string str="A(5(4,7),C)";
	ptree root=Create_BiTree(str.data());
	FindPath(root,expectedSum);
	
}
