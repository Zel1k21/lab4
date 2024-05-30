#include "MyStack/MyStack.h"

void Multipliers(int, MyStack<int>&);

int main() 
{
	int num;
	std::cin >> num;
	MyStack<int> example;
	Multipliers(num, example);
	MyStack<int> s2(example);
	example.print();
	s2.printReverse();
	return 0;
}

void Multipliers(int n, MyStack<int>& stack)
{
	int div = 2;
	if (n < 0)
	{
		stack.push(-1);
		n *= -1;
	}
	while (n > 1)
	{
		while (n % div == 0)
		{
			stack.push(div);
			n /= div;
		}
		if (div == 2) div++;
		else div += 2;
	}

}
