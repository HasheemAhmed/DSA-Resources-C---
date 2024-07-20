#include <iostream>
using namespace std;


class stack
{

	int *data, top,size;
public:
	stack(int size)
	{
		this->top = -1;
		this->size = size;
		data = new int(size);
	}

	bool isFull()
	{
		if (this->top == this->size)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		if (this->top == -1)
			return true;
		else
			return false;
	}

	void push(int data)
	{
		if (!isFull())
		{
			top++;
			this->data[this->top] = data;
		}
		else
		{
			cout << "Stack is Full.\n";
		}
	}


};

int main()
{
	stack s1(10);

	return 0;
}