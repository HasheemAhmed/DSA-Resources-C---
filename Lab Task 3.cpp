#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name,address;
	int rollNo;
	float CGPA;
	
	student *next;	
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
		student * newstd = new student;
		
		cout << "Enter the roll no : ";
		cin >> newstd->rollNo;
		/*cout << "Enter student name : ";
		cin.ignore();
		getline(cin,newstd->name);
		cout << "Enter student address : ";
		cin.ignore();
		getline(cin,newstd->address);
		cout <<"Enter satudent Gpa : ";
		cin >>newstd->CGPA;*/
		
		return newstd;
	}

	void displayStudent()
	{
		temp = head;
		while(temp != NULL)
		{
			//cout << "\nStudent " << i+1 << endl;
			//cout << "Name    : " << temp->name << endl;
			cout << "Rollno  : " << temp->rollNo << endl;
			//cout << "Address : " << temp->address << endl;
			//cout << "CGPA    : " << temp->CGPA << endl;
			temp = temp->next;
		}
	}

	int sizeOfLinkedList()
	{
		int count = 0;
		temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}

	int SearchStudent(string name)
	{
		int location = 0;
		temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			if (temp->name == name)
				break;
			location++;
		}
		return location;
	}

	void insertAtEnd()
	{
		for(int i = 0; i < 2 ; i++ )
		{
			student* newNode = input_student();
			if (head == NULL)
			{
				head = tail = newNode;
				newNode->next = NULL;
				count++;
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
				count++;

			}
		}
	}

	void insertAtStart()
	{
		for(int i = 0; i < 2; i++)
		{
			student* newNode = input_student();
			if (head == NULL)
			{
				head = tail = newNode;
				newNode->next = NULL;
				count++;
			}
			else
			{
				temp = head;
				head = newNode;
				newNode->next = temp;
				count++;

			}
		}
	}

	void insertAtgivenIndex(int index)
	{
		for(int i = 0; i < 2 ; i++)
		{
			student* newNode = input_student();

			if (index > 0 && index - 1 <= count)
			{
				temp = head;
				if (index == 1 && head == NULL)
				{
					head = tail = newNode;
					newNode->next = NULL;
					count++;
				}
				else if (index == 1 && head != NULL)
				{
					head = newNode;
					newNode->next = temp;
					count++;
				}
				else if (index > count)
				{
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = tail = newNode;
					newNode->next = NULL;
				}
				else
				{
					for (int i = 1; i < index - 1; i++)
					{
						temp = temp->next;
					}
					newNode->next = temp->next;
					temp->next = newNode;

				}
				count++;
			}
			else
			{
				cout << "Insertion At Given Index is not possible.\n";
			}
		}
	}

	void deleteAtEnd()
	{
		for (int i = 0; i < 2; i++)
		{
			temp = head;
			if (temp == NULL)
			{
				cout << "Array is already Empty.\n";
			}
			else if (temp->next == NULL)
			{
				delete head;
				head = tail = NULL;
				count--;
			}
			else
			{
				temp = head;
				while (temp->next->next != NULL)
				{
					temp = temp->next;
				}
				delete tail;
				temp->next = NULL;
				tail = temp;
				count--;
			}
		}
	}

	void deleteAtStart()
	{
		for (int i = 0; i < 2; i++)
		{
			if (head == NULL)
			{
				cout << "Array is already Empty.\n";
			}
			else if (head->next == NULL)
			{
				delete head;
				head = tail = NULL;
				count--;
			}
			else
			{
				temp = head;
				head = head->next;
				delete temp;
				count--;
			}
		}
	}

	void deleteAtGivenLocation(int index)
	{
		temp = head;
		if (temp == NULL)
		{
			cout << "Array is already Empty.\n";
		}
		else if (temp->next == NULL && index == 1)
		{
			delete head;
			head = tail = NULL;
			count--;
		}
		else if (temp->next != NULL && index == 1)
		{
			head = head->next;
			delete temp;
			count--;
		}
		else
		{
			for (int i = 1; i < index-1; i++)
			{
				temp = temp->next;
				if (temp == NULL)
				{
					break;
				}
			}

			if (temp == NULL || temp->next == NULL)
			{
				cout << "Deletion is not possible at given index.\n";
			}
			else if (temp->next == NULL)
			{
				delete tail;
				temp->next = NULL;
				tail = temp;
				count--;
			}
			else
			{
				student *del = temp->next;
				temp->next = temp->next->next;
				delete del;
				count--;
			}
		}
	}
};


int main()
{
	DSA obj;

	obj.insertAtEnd();
	obj.insertAtEnd();
	obj.deleteAtGivenLocation(4);
	obj.displayStudent();

	return 0;
}
