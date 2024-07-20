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
	student *head , *tail,*temp;	
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

	void insertAtEnd()
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

	void insertAtStart()
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

	void insertAtgivenIndex(int index)
	{
		student* newNode = input_student();

		if(index > 0 && index-1 <= count)
		{
			temp = head;
			if (index == 1 &&  head == NULL)
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
				for (int i = 1; i < index-1; i++)
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
};


int main()
{
	DSA obj;

	obj.insertAtEnd();
	obj.insertAtStart();
	obj.insertAtgivenIndex(1);
	obj.insertAtgivenIndex(4);
	obj.insertAtgivenIndex(3);
	obj.displayStudent();

	return 0;
}
