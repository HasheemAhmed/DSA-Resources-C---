#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Queue
{
	Node* front, * rear;
public:
	Queue()
	{
		front = rear = NULL;
	}

	void enQueue(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (front == NULL)
			rear = front = newNode;
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	void deQueue()
	{

		int data;
		if (front == NULL)
			cout << "Queue is empty.\n";
		else
		{
			data = front->data;
			front = front->next;
		}
	}

	void displayQueue()
	{
		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
	}

};

int main()
{
	Queue obj;

	obj.enQueue(1);
	obj.enQueue(2);
	obj.deQueue();
	obj.enQueue(3);
	obj.enQueue(4);
	obj.enQueue(5);
	obj.deQueue();
	obj.displayQueue();
	return 0;
}
