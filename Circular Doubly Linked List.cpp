#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* prev;
	Node* next;
};

class LinkedList
{
	Node* head, * tail, * temp, * newNode;
public:
	LinkedList()
	{
		head = tail = temp = newNode = NULL;
	}
	~LinkedList()
	{

	}

	void print()
	{
		temp = NULL;
		while (temp != head)
		{
			if (temp == NULL)
				temp = head;

			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	void insertAtStart(int data)
	{
		newNode = new Node();
		newNode->data = data;
		if (head == NULL)
		{
			head = tail = newNode;
			tail->next = head;
			head->prev = tail;
		}
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
			tail->next = head;
			head->prev = tail;
		}
	}

	void insertAtEnd(int data)
	{
		newNode = new Node();
		newNode->data = data;
		if (head == NULL)
		{
			head = tail = newNode;
			tail->next = head;
			head->prev = tail;
		}
		else
		{
			temp = tail;
			tail->next = newNode;
			tail = newNode;
			tail->next = head;
			tail->prev = temp;
		}
	}

	void insertAtLocation(int data, int index)
	{
		newNode = new Node();
		newNode->data = data;
		if (head == NULL && index == 1)
		{
			head = tail = newNode;
			tail->next = head;
			head->prev = tail;
		}
		else if (head != NULL && index == 1)
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
			tail->next = head;
			head->prev = tail;
		}
		else if (index > 1)
		{
			temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
				if (temp == head)
					break;
			}

			if (temp->next != head)
			{

				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
			}
			else if (temp->next == head)
			{
				newNode->prev = tail;
				temp->next = tail = newNode;
				tail->next = head;
			}
			else
			{
				cout << "Insertion At given Location is not Possible.\n";
			}

		}
		else
		{
			cout << "Insertion At given Location is not Possible.\n";
		}
	}

	void deleteAtStart()
	{
		if (head == NULL)
		{
			cout << "List is alrady Empty.\n";
		}
		else if (head->next == head)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			delete temp;
			tail->next = head;
			head->prev = tail;
		}
	}

	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is alrady Empty.\n";
		}
		else if (head->next == head)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			temp = head;
			while (temp->next->next != head)
			{
				temp = temp->next;
			}
			delete  temp->next;
			tail = temp;
			tail->next = head;
			head->prev = tail;
		}
	}

	void deleteAtLocation(int index)
	{
		if (head == NULL)
		{
			cout << "Link List is empty.\n";
		}
		else if (head->next == head && index == 1)
		{
			delete head;
			head = tail = NULL;
		}
		else if (head->next != head && index == 1)
		{
			temp = head;
			head = head->next;
			delete temp;
			tail->next = head;
			head->prev = tail;
		}
		else if (index > 1)
		{
			temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
			}

			if (temp->next != head)
			{
				Node* del;
				del = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete del;
			}
			else if (temp->next->next == head)
			{
				delete temp->next;
				temp->next = head;
			}
			else
			{
				cout << "Deletion at given index is not possible.\n";
			}
		}
		else
		{
			cout << "Deletion at given index is not possible.\n";
		}
	}
};

int main()
{
	LinkedList obj;

	obj.insertAtStart(3);
	obj.insertAtStart(2);
	obj.insertAtStart(1);
	obj.insertAtEnd(4);
	obj.insertAtEnd(5);
	obj.insertAtLocation(0, 1);
	obj.insertAtLocation(6, 7);
	obj.insertAtLocation(3, 3);

	obj.print();
	return 0;
}