// insert two students at start,end,given
//delete two studets from start,end,give locaction
//Return the size of class
//display
//search
//destructor

#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name, address;
	int rollNo;
	float CGPA;

	student* next;
};

class DSA
{
private:
	student* head, * tail, * temp;
	int count;
public:
	DSA()
	{
		head = tail = temp = NULL;
		count = 0;
	}
	~DSA()
	{
		//Destructor to delete dynamicaly allocated memory
	}
	student* input_student()
	{
		student* newstd = new student;

		cout << "Enter the roll no : ";
		cin >> newstd->rollNo;
		cout << "Enter student name : ";
		getline(cin, newstd->name);
		cout << "Enter student address : ";
		getline(cin, newstd->address);
		cout << "Enter satudent Gpa : ";
		cin >> newstd->CGPA;

		return newstd;
	}

	void insertAtEnd()
	{
		for(int i = 0; i < 2 ; i++)
		{
			student* newNode = input_student();
			if (head == NULL)
			{
				head = tail = newNode;
				newNode->next = NULL;
				++count;
			}
			else
			{
				temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}

				temp->next = tail = newNode;
				newNode->next = NULL;
				++count;
			}
		}
	}

	void insertAtStart()
	{
		for (int i = 0; i < 2; i++)
		{
			student* newNode = input_student();
			if (head == NULL)
			{
				head = tail = newNode;
				newNode->next = NULL;
				++count;
			}
			else
			{
				temp = head;
				head = newNode;
				newNode->next = temp;
				++count;
			}
		}
	}

	void insertAtLocation()
	{
		for (int i = 0; i < 2; i++)
		{

			student* newNode = input_student();

			if (head == NULL)
			{
				head = tail = newNode;
				newNode->next = NULL;
			}
			else if (tail->rollNo < newNode->rollNo)
			{
				tail->next = newNode;
				newNode->next = NULL;
				tail = newNode;
			}
			else if (head->rollNo > newNode->rollNo)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				temp = head;
				while ((temp->next)->rollNo > newNode->rollNo)
				{
					temp = temp->next;
				}

				newNode->next = temp->next;
				temp->next = newNode;
			}
			++count;
		}
	}

	void deleteAtStart()
	{
		if (head == NULL)
		{
			cout << "List is already Empty.\n";
		}
		else
		{
			temp = head;
			head = head->next;
			delete temp;
			if (head == NULL)
			{
				tail = NULL;
			}
			--count;
		}

	}

	void deleteAtEnd()
	{
		if (head == NULL)
		{
			cout << "List is already Empty.\n";
		}
		else
		{
			if (head->next == NULL)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				temp = head;
				while ((temp->next)->next != NULL)
				{
					temp = temp->next;
				}

				temp->next = NULL;
				delete tail;
				tail = temp;
			}

			--count;
		}

	}

	int findStudentByRollno(int rollno)
	{
		int loc = -1;

		if (head != NULL)
		{
			temp = head;
			int i = 1;
			while (temp->rollNo != rollno && temp->next != NULL)
			{
				temp = temp->next;
				i++;
			}
			if (temp->rollNo == rollno)
			{
				loc = i;
			}
		}
		return loc;
	}

	void deleteAtLocation(int rollno)
	{
		if (findStudentByRollno(rollno) != -1)
		{

		}
	}
};


int main()
{
	return 0;
}








