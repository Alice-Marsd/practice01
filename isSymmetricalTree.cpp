#include<iostream>
#include<string>
#include<E:\fan\BITree.h>
using namespace std;
bool isSymmetrical(ptree root1,ptree root2)
{
	if(!root1 && !root2) 
	return true;
	if(!root1 || !root2)  //È¡·´£¡£¡£¡ 
	return false;
	if(root1->data!=root2->data)
	return false;
	return isSymmetrical(root1->left,root2->right) && isSymmetrical(root1->right,root2->left);
} 
bool isSymmetrical(ptree root)
{
	return isSymmetrical(root,root);
}
int main()
{
	string str1="7(7(7,7),7(7,7))";
	
	ptree root=Create_BiTree(str1.data());
	PrintLink1(root);
	cout<<endl;
	cout << isSymmetrical(root) <<endl;
	
}
