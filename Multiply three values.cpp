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
	node* head, * tail, * temp, * newNode;
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
			head = tail = newNode;
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

	void insertAtLocation(int data, int loc)
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
		else if (head != NULL && loc == 1)
		{
			newNode->next = head;
			head = newNode;
		}
		else if (loc > 1)
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
		else if (head->next == NULL)
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

	void multiplyThreeSmallestNode()
	{
		temp = head;
		int small1, small2,small3;

		small1 = temp->data;
		temp = temp->next;
		small2 = temp->data;
		temp = temp->next;
		small3 = temp->data;

		while (temp != NULL)
		{
			if (temp->data <= small1)
			{
				small3 = small2;
				small2 = small1;
				small1 = temp->data;
			}

			if (temp->data < small2 && temp->data > small1)
			{
				small3 = small2;
				small2 = temp->data;
			}

			if (temp->data < small3 && temp->data > small2)
			{
				small3 = temp->data;
			}

			temp = temp->next;
		}

		cout << "Multiplication of smallest Node are : " << small1 * small2*small3 << endl;
	}

	void multiplyThreeLargestNode()
	{
		temp = head;
		int Large1, Large2, Large3;

		Large1 = temp->data;
		temp = temp->next;
		Large2 = temp->data;
		temp = temp->next;
		Large3 = temp->data;

		while (temp != NULL)
		{
			if (temp->data >= Large1)
			{
				Large3 = Large2;
				Large2 = Large1;
				Large1 = temp->data;
			}

			if (temp->data > Large2 && temp->data < Large1)
			{
				Large3 = Large2;
				Large2 = temp->data;
			}

			if (temp->data > Large3 && temp->data < Large2)
			{
				Large3 = temp->data;
			}

			temp = temp->next;
		}

		cout << "Multiplication of Largeest Node are : " << Large1 * Large2 * Large3 << endl;
	}
};

int main()
{
	Data obj;

	obj.insertAtEnd(5);
	obj.insertAtEnd(6);
	obj.insertAtEnd(8);
	obj.insertAtEnd(3);
	obj.insertAtEnd(4);
	obj.insertAtEnd(2);

	obj.multiplyThreeSmallestNode();
	obj.multiplyThreeLargestNode();

	return 0;
}