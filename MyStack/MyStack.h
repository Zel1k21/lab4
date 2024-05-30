#define MyStack_h

#include <iostream>

template <class mainInformation, class FRIEND>

class ListNode
{
private:
	mainInformation inf;
	ListNode* next;					
	ListNode() { next = nullptr; }
	ListNode(mainInformation info) : inf(info), next(nullptr) {};
	friend FRIEND;
};

template<class INF>
class MyStack
{
	typedef class ListNode<INF, MyStack<INF>> Node;
	Node* top;
public:
	MyStack();
	MyStack(Node*);
	MyStack(const MyStack&);
	~MyStack() { this->clear(); }
	bool empty();
	void push(INF);
	void pop();
	INF top_inf() const { return this->top->mainInformation; }
	void print();
	void printReverse();

	void operator=(const MyStack<INF>& stack);
	void clear() { while (!this->empty()) { this->pop(); } }
};

template<class INF>
inline void MyStack<INF>::operator=(const MyStack<INF>& stack)
{
	if (this->top == stack.top)
		return;
	this->clear();
	if (stack.empty())
		return;
	this->top = new Node;
	Node* thisNode = this->top;
	Node* otherNode = stack.top;
	thisNode->mainInformation = otherNode->mainInformation;
	while (otherNode->next != nullptr) {
		otherNode = otherNode->next;
		thisNode->next = new Node;
		thisNode = thisNode->next;
		thisNode->mainInformation =otherNode->mainInformation;
	}
}



template<class INF>
inline MyStack<INF>::MyStack()
{
	top = nullptr;
}


template<class INF>
inline MyStack<INF>::MyStack(Node* top) {
	top = top;
}

template<class INF>
inline MyStack<INF>::MyStack(const MyStack& other)
{
	
	if (!other.top)
	{
		top = nullptr;
		return;
	}
	top = new Node(*other.top);
	Node* current = top;
	
	for (Node *t = other.top->next; t != nullptr; t = t->next)
	{
		current->next = new Node(*t);
		current = current->next;
	}
	current->next = nullptr;

}

template<class INF>
inline bool MyStack<INF>::empty()
{
	return top == nullptr;
}

template<class INF>
inline void MyStack<INF>::push(INF n)
{
	Node* elem = new Node(n);
	if (empty())
	{
		top = elem;
		return;
	}
	elem->next = top;
	top = elem;
}

template<class INF>
inline void MyStack<INF>::pop()
{
	if (empty()) return;
	Node* elem = top;
	top = elem->next;
	delete elem;
}

template<class INF>
inline void MyStack<INF>::print()
{
	if (empty())
		return;
	INF sum = 1;
	Node* elem = top;
	while (elem) {
		std::cout << elem->inf;
		sum *= elem->inf;
		if (elem->next != nullptr)
			std::cout << " * ";
		elem = elem->next;
	}
	std::cout << " = " << sum << std::endl;
}

template<class INF>
inline void MyStack<INF>::printReverse()
{
	MyStack<INF> stack;
	Node* node = this->top;
	while (node != nullptr) {
		stack.push(node->inf);
		node = node->next;
	}
	stack.print();
}

