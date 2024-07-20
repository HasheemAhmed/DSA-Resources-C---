#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class stack
{
	Node *top;
public:
	stack() 
	{
		top = NULL;
	}

	void push(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->next = this->top;
		this->top = newNode;
	}

	void pop()
	{
		Node* del = top;
		top = top->next;

		delete del;
	}

	int peek()
	{
		return top->data;
	}

	void displayStack()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	stack obj;

	obj.push(1);
	obj.push(2);
	obj.pop();
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.pop();
	obj.push(4);

	obj.displayStack();
	return 0;
}