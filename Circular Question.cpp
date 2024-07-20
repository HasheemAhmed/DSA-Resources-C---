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

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		newNode->next = head;
		tail = newNode;
	}

	void LeaderSelector(int num)
	{
		temp = head;
		while(temp->next!= head)
		{
			temp = head;
			int random = rand() % num;
			cout << random << " ";
			for (int i = 1; i < random-1; i++)
			{
				temp = temp->next;
				if (temp == head)
					break;
			}
			Node* del;

			if (temp == head)
			{
				del = temp;
				head = head->next;
				delete del;
			}
			else if (temp->next->next == head)
			{
				del = temp->next;
				temp->next = head;
				delete del;
			}
	        else
			{
				del = temp->next;
				temp->next = temp->next->next;
				delete del;
			}

			temp = head;
		}
		cout << endl;
	}


	void display()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
			if (temp == head)
				break;
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
	obj.LeaderSelector(8);
	obj.display();

	return 0;
}