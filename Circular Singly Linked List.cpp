#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class Singly
{
	Node* head, * tail, * temp, * newNode;
public:
	Singly()
	{
		head = tail = temp = newNode = NULL;
	}
	~Singly()
	{

	}

	void insertAtStart(int data)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		tail->next = head;
	}

	void insertAtEnd(int data)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		tail->next = head;
	}

	void insertAtLocation(int data, int index)
	{
		newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if (index == 1)
		{
			if (head == NULL)
				tail = newNode;
			newNode->next = head;
			head = newNode;
			tail->next = head;
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

			if (temp == head)
			{
				cout << "Insertion At given index is not posiible.\n";
			}
			else if (temp->next == head)
			{
				temp->next = tail = newNode;
				tail->next = head;
			}
			else
			{
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		else
		{
			cout << "Insertion At given index is not posiible.\n";
		}
	}

	void deleteAtStart()
	{
		if (head == NULL)
		{
			cout << "Linked List is empty.\n";
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
			temp = NULL;
			tail->next = head;
		}
	}

	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "Linked List is empty.\n";
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
			delete tail;
			tail = temp;
			tail->next = head;
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
			if (head->next == head)
				tail = NULL;
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
			if(tail != NULL)
				tail->next = head;
		}
		else if (index > 1)
		{
			temp = head;
			for (int i = 1; i < index - 1; i++)
			{
				temp = temp->next;
				if (temp->next == head)
					break;
			}

			if (temp->next == head)
			{
				cout << "Deletion At given index is not posiible.\n";
			}
			else if (temp->next->next == head)
			{
				delete temp->next;
				temp->next = head;
				tail = temp;
			}
			else
			{
				Node* del = temp->next;
				temp->next = temp->next->next;
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
			if (temp == head)
				break;
		}
		cout << endl;
	}
};

int main()
{
	Singly obj;

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