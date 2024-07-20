#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* prev;
	Node* next;
};

class Doubly
{
	Node* head, * tail, * temp, * newNode;
public:
	Doubly()
	{
		head = tail = temp = newNode = NULL;
	}
	~Doubly()
	{

	}

	void insertAtStart(int data)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = newNode->prev = NULL;

		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int data)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = newNode->prev = NULL;

		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}

	}

	void insertAtLocation(int data, int index)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = newNode->prev = NULL;

		if (index == 1)
		{
			if (head == NULL)
				tail = newNode;
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else if (index > 1)
		{
			temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
					break;
			}

			if (temp == NULL)
			{
				cout << "Insertion At given index is not posiible.\n";
			}
			else if (temp->next == NULL)
			{
				newNode->prev = tail;
				temp->next = tail =  newNode;
			}
			else
			{
				newNode->next = temp->next;
				temp->next = newNode;
				newNode->prev = temp;
				newNode->next->prev = newNode;
			}
		}
		else
		{
			cout << "Insertion At given index is not possible.\n";
		}
	}

	void deleteAtStart()
	{
		if (head == NULL)
		{
			cout << "Linked List is empty.\n";
		}
		else if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			temp = NULL;
		}
	}

	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "Linked List is empty.\n";
		}
		else if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = NULL;
		}
	}

	void deleteAtLocation(int index)
	{
		if (head == NULL)
		{
			cout << "Linked List is empty.\n";
		}
		else if (index == 1)
		{
			if (head->next == NULL)
				tail = NULL;
			temp = head;
			head = head->next;
			if(head != NULL)
			head->prev = NULL;
			delete temp;
			temp = NULL;
		}
		else if (index > 1)
		{
			temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
				if (temp->next == NULL)
					break;
			}

			if (temp->next == NULL)
			{
				cout << "Deletion At given index is not posiible.\n";
			}
			else if (temp->next->next == NULL)
			{
				delete temp->next;
				temp->next = NULL;
				tail = temp;
			}
			else
			{
				Node* del = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete del;
				del = NULL;
			}
		}
		else
		{
			cout << "Deletion At given index is not posiible.\n";
		}
	}

	void print()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	Doubly obj;

	obj.insertAtStart(3);
	obj.insertAtStart(1);

	obj.insertAtEnd(4);
	obj.insertAtEnd(5);

	obj.insertAtLocation(0, 1);
	obj.insertAtLocation(6, 6);
	obj.insertAtLocation(2, 3);

	obj.deleteAtEnd();
	obj.deleteAtStart();
	obj.deleteAtLocation(1);
	obj.deleteAtLocation(3);
	obj.print();
	return 0;
}