#include<iostream>
#include<stack>
using namespace std;
bool isPopOrder(int *push,int *pop,int length)
{
	bool isPopOrder=false;
	

	if(push!=NULL && pop!=NULL && length>0)
	{
		const int* pNextPush=push;
		const int* pNextPop=pop;
		stack<int> stack;
		
		while(pNextPop-pop<length)
		{
			
			while(stack.empty() || stack.top()!=*pNextPop)
			{
				if(pNextPush-push==length)
				break;
				stack.push(*pNextPush);
				pNextPush++;
			}
			
			if(stack.top()!=*pNextPop)
			break;
			stack.pop();
			pNextPop++;
			
		}
			if(stack.empty() && pNextPop-pop==length)
			isPopOrder=true;
			
	}
	
	return isPopOrder;
	
}
int main()
{
	int push[]={1,2,3,4,5};
	int pop[]={4,5,2,3,1};
	cout <<isPopOrder(push,pop,5)<<endl;
}
