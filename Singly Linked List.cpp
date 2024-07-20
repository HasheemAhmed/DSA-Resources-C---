#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class Data
{
private:
	node* head, * tail, * temp, *newNode;
public:
	Data()
	{
		head = tail = temp = newNode = NULL;
	}
	~Data()
	{
		// Destructor to delete dynamically created memory
	}

	void insertAtStart(int data)
	{
		newNode = new node();
		newNode->data = data;

		if (head == NULL) 
		{
			head = tail =  newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtEnd(int data)
	{
		newNode = new node();
		newNode->data = data;

		if (head == NULL)
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else 
		{
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			tail = temp->next = newNode;
			newNode->next = NULL;
		}
	}

	void insertAtLocation(int data , int loc)
	{
		newNode = new node();
		newNode->data = data;

		if (head == NULL && loc != 1)
		{
			cout << "Insertion at given index is not possible.\n";
		}

		else if (head == NULL && loc == 1)
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else if(head != NULL && loc == 1)
		{
			newNode->next = head;
			head = newNode;
		}
		else if(loc  > 1)
		{
			temp = head;
			for (int i = 1; i < loc - 1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
					break;
			}

			if (temp == NULL)
			{
				cout << "Insertion at given index is not possible.\n";
			}
			else if (temp->next == NULL)
			{
				tail = temp->next = newNode;
				newNode->next = NULL;
			}
			else
			{
				newNode->next = temp->next;
				temp->next = newNode;
			}

		}
		else
		{
			cout << "Insertion at given index is not possible.\n";
		}

	}

	void deleteAtStart()
	{
		if (head == NULL)
		{
			cout << "List is already empty.\n";
		}
		else if(head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			temp = head;
			head = temp->next;
			delete temp;
		}
	}

	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is already empty.\n";
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
			temp->next = NULL;
		}
	}

	void deleteAtGivenLocation(int loc)
	{
		if (head == NULL)
		{
			cout << "List is already empty.\n";
		}
		else if (head->next == NULL && loc == 1)
		{
			delete head;
			head = tail = NULL;
		}
		else if (head->next != NULL && loc == 1)
		{
			temp = head;
			head = temp->next;
			delete temp;
		}
		else if (loc > 1)
		{
			temp = head;
			for (int i = 1; i < loc - 1; i++)
			{
				temp = temp->next;
			}

			if (temp == NULL || temp->next == NULL)
			{
				cout << "Deletion at given idex is not possible.\n";
			}
			else if (temp->next->next == NULL)
			{
				delete temp->next;
				temp->next = NULL;
				tail = temp;
			}
			else
			{
				node* del;
				del = temp->next;
				temp->next = temp->next->next;
				delete del;
			}
		}
		else
		{
			cout << "Deletion at given inndex is not possible.\n";
		}
	}

	void display()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	Data obj;
	obj.insertAtStart(2);    // 2
	obj.insertAtStart(1);	// 1 , 2	
	obj.insertAtEnd(3);		// 1 , ,2 ,3
	obj.insertAtEnd(4);		// 1 ,2 , 3 ,4
	obj.insertAtLocation(0, 1);	// 0 , 1 , 2 , 3 , 4
	obj.insertAtLocation(5,6);	// 0 , 1 , 2 , 3 , 4 , 5
	obj.insertAtLocation(2,3);	// 0 , 1 , 2 , 2 , 3 , 4 , 5
	obj.insertAtLocation(0,0);
	obj.insertAtLocation(0,10);
	obj.deleteAtStart(); //  1 , 2 , 2 , 3 , 4 , 5
	obj.deleteAtEnd();  //  1 , 2 , 2 , 3 , 4
	obj.deleteAtGivenLocation(2); //  1 , 2 , 3 , 4
	obj.deleteAtGivenLocation(5);
	obj.display();
	return 0;
}