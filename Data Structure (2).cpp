/* --- Singly Linked List --- */ 

#include <iostream>
using namespace std;

/* --- Structure For Creating New Node --- */

struct node
{
	int data;
	node* next;
};

/* --- Declaring Pointers --- */

node* head = NULL; // For Storig First Node Address
node* ptr = NULL;  // For Creating New Node dynamically
node* temp = NULL; // For storing the Head Address for Working

/* --- Insertion At The End Function --- */

void insertAtEnd(int data)
{
	ptr = new node;		// Creating new Node
	ptr->data = data;	// Putting Data in Node
	
	if (head == NULL)	// Inserting data if there is no node
	{
		head = ptr;
		ptr->next = NULL;
	}
	else			// Inserting node if there is already exist some node
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = NULL;
	}
}

/* --- Insertion At The Begin Function --- */

void insertAtBegin(int data)
{
	ptr = new node;		// Creating new Node
	ptr->data = data;	 // Putting Data in Node

	if (head == NULL)  // Inserting data if there is no node
	{
		head = ptr;
		ptr->next = NULL;
	}
	else               // Inserting node if there is already exist some node
	{
		ptr->next = head;
		head = ptr;
	}
}

/* --- Insertion At The Given Location Function --- */

void insertAtLocation(int data, int loc)
{
	int noOfNodes = 1;  // For Nodes Counting
	temp = head;
	while (temp != NULL)  // Run the Loop until the End Node is Reached  
	{
		temp = temp->next;
		noOfNodes++;       // Counting nodes
	}
	
	if (loc > 0 && loc <= noOfNodes)  // Checking the user enter correct location
	{
		ptr = new node;      // Creating new Node
		ptr->data = data;	 // Putting Data in Node

		if (loc == 1)        // Inserting data if the loacation is the starting node
		{
			ptr->next = head;
			head = ptr;
		}
		else                // Inserting data at given loacation
		{
			temp = head;
			for (int i = 1; i < loc-1; i++) // Going To Given Location
			{
				temp = temp->next;
			}

			ptr->next = temp->next; // Putting node at given Location
			temp->next = ptr;
		}

		
	}
	else  // Run Else if user enter False Location
	{
		cout << "Insertion at Given index is not Possible.\n";
	}

}

/* --- Deletion At End Function --- */

void deleteAtEnd()
{
	temp = head;
	if (temp == NULL)  //IF there are no elements
	{
		cout << "List has no elements in them.\n";
	}
	else if(temp->next == NULL) // If there is only one element
	{
		delete temp;
		head = NULL;
	}
	else        // If there are many elements in list
	{
		while ((temp->next)->next != NULL)
		{
			temp = temp->next;

		}

		node* del;           //Storing last node address
		del = temp->next;
		temp->next = NULL;  // Assigning Null to last node in list
		delete del;			// Deleting Last Node
	}
}

/* --- Deletion At Start Function --- */

void deleteAtStart()
{
	temp = head;
	if (temp == NULL)  // If list is already empty
	{
		cout << "List has no elements in them.\n";
	}
	else             // if list has elements in it
	{
		head = temp->next;
		delete temp;
	}
}

/* --- Deletion At Given Function --- */

void deleteAtGivenIndex(int index)
{
	int noOfNodes = 0;  // Variable for number of nodes
	temp = head;
	while (temp != NULL)   // Counting number of nodes
	{
		temp = temp->next;
		++noOfNodes;
	}

	if (index > 0 && index <= noOfNodes)  // Checking user enters correct index
	{
		temp = head;
		if (noOfNodes == 1)       // IF there will be only one node
		{
			delete head;
			head = NULL;
		}
		else if (index == 1)      // If deleting first node
		{
			head = temp->next;
			delete temp;
		}
		else                     // Deleting At given index
		{
			temp = head;
			for (int i = 2; i < index; i++)  // Traversing to the given node
			{
				temp = temp->next;
			}

			node* del;
			del = temp->next;
			temp->next = (temp->next)->next;  // Linking the list;
			delete del;                      // Deleting the Node
			

		}
	}
	else
	{
		cout << "Deletetion at given index is not possible.\n";
	}

}

/* --- Display Function --- */

void display()
{
	temp = head;             // Assign temp = head to start printing from start node
	while (temp != NULL )   // Run the Loop until the End Node is Reached 
	{
		cout << temp->data << endl; // Printing Data
		temp = temp->next;          // Incrementing the Node
	}
	
}

/* --- Main Function Function --- */

int main()
{
	
	
	insertAtEnd(10);		// 10
	insertAtBegin(5);		// 5 , 10	
	insertAtLocation(7, 1); // 7 , 5 , 10
	insertAtLocation(2, 3); // 7 , 5 , 2 , 10
	insertAtLocation(15, 5);// 7 , 5 , 2 , 10 , 15
	insertAtLocation(26, 1);// 26 , 7 , 5 , 2 , 10 , 15
	insertAtEnd(30);        // 26 , 7 , 5 , 2 , 10 , 15 , 30
	
	

	

	display(); // Display Function for Displaying


	return 0;
}