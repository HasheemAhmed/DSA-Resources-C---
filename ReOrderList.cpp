#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head, * tail, * newNode, * temp;
public:
	LinkedList()
	{
		head = tail = newNode = temp = NULL;
	}
	~LinkedList()
	{

	}

	void addNode(int data)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	void reOrderList()
	{
		bool sort = true;
		while (sort)
		{
			sort = false;

			temp = head;
			while (temp->next != NULL)
			{
				if (temp->data % 2 == 0 && temp->next->data % 2 != 0)
				{
					int swap = temp->data;
					temp->data = temp->next->data;
					temp->next->data = swap;
					sort = true;
				}
				temp = temp->next;
			}
		}
	}

	void display()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

};

int main()
{
	LinkedList obj;

	obj.addNode(1);
	obj.addNode(2);
	obj.addNode(3);
	obj.addNode(4);
	obj.addNode(5);
	obj.addNode(6);
	obj.addNode(7);
	obj.addNode(8);

	obj.display();
	obj.reOrderList();
	obj.display();

	return 0;
}