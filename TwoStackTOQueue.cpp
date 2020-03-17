#include<iostream>
#include<stack>
#include <stdexcept>
#include<cstdio>
using namespace std;
template<typename T> class CQueue
{
	public:
		CQueue(void);
		~CQueue(void);
		
		void appendTail(const T & node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};
template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}
template<typename T>T CQueue<T>::deleteHead()
{
	if(stack2.size<=0)
	{
		while(stack1.size>0)
		{
			T& data=stack1.top;
			stack1.pop;
			stack2.push(data);
		}
	}
	if(stack2.size==0)
	throw std::logic_error("queue empty");
	T head=stack2.top();
	stack2.pop();
	return head;
}
int main()
{
	int n;
	CQueue <T>queue=new <T>CQueue();
	while(scanf("%d",&n)=='EOP')
	{
		queue.appendTail(n);
	}
	queue.deleteHead();
	
}
