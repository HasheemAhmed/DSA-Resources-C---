#include<iostream>
#include<conio.h>
#include <string>
using namespace std;
class node {
public:
	string name;
	int roll_no;
	int marks;
	float per;
	node* next;
};

class student_management {
	int count;
	node* head;
public:
	student_management()
	{
		head = NULL;
	}
	void input_student()
	{
		node* newStudent = new node;

		cout << "enter your roll_no: ";
		cin >> newStudent->roll_no;
		cout << "enter your name: ";
		cin.ignore();
		getline(cin, newStudent->name);
		cout << "enter your marks: ";
		cin >> newStudent->marks;
		//percentage of student
	//	cout<<"the percentage of student is: ";
		newStudent->per = (newStudent->marks * 100) / 100;

		//	newStudent->next = NULL;

		if (head == NULL)
		{
			head = newStudent;
			newStudent->next = NULL;
		}
		else
		{
			node* temp;
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newStudent;
		}
		cout << "\nnew student inserted sucessfully" << endl;
	}

	void search()
	{
		if (head == NULL)
		{
			cout << "link list is empty no student exits." << endl;
		}
		else
		{
			int r, found = 0;
			cout << "enter the roll number you want to search: ";
			cin >> r;

			node* temp = head;
			while (temp != NULL)
			{
				if (r == temp->roll_no)
				{
					cout << "the roll number " << temp->roll_no << " is found." << endl;
					cout << "the name of student is: " << temp->name << endl;
					cout << "the marks of student are: " << temp->marks << endl;
					cout << "the percentage of student is: " << temp->per << endl;
					found++;
				}
				temp = temp->next;
			}
			if (found == 0)
			{
				cout << "no student of " << r << "is present in record to search." << endl;
			}
		}
	}

	void count_student()
	{
		if (head == NULL)
		{
			cout << "link list is empty no student exits." << endl;
		}
		else
		{
			int c = 0;
			node* temp = head;
			while (temp != NULL)
			{
				c++;
				temp = temp->next;
			}
			cout << "total number of students are: " << c << endl;
		}
	}

	void update()
	{
		if (head == NULL)
		{
			cout << "link list is empty no student exits." << endl;
		}
		else
		{
			int r, found = 0;
			cout << "enter the roll number you want to update: ";
			cin >> r;

			node* temp = head;
			while (temp != NULL)
			{
				if (r == temp->roll_no)
				{
					cout << "enter new roll_no: ";
					cin >> temp->roll_no;
					cout << "enter new name: ";
					cin.ignore();
					getline(cin, temp->name);
					cout << "enter new marks: ";
					cin >> temp->marks;

					//	percentage of student
					//	cout<<"the percentage of student is: ";
					temp->per = (temp->marks * 100) / 100;

					cout << "record updated sucessfully." << endl;
					found++;
				}
				temp = temp->next;
			}
			if (found == 0)
			{
				cout << "no student of " << r << "is present in record to update." << endl;
			}
		}
	}

	void delete_func()
	{
		if (head == NULL)
		{
			cout << "link list is empty no student exits." << endl;
		}
		else
		{
			int r, found = 0;
			cout << "enter the roll number you want to delete: ";
			cin >> r;

			if (r == head->roll_no)
			{
				node* temp = head->next;
				node* temp2 = head;
				head = temp;
				delete temp2;

				cout << "record deleted sucessfully." << endl;
				found++;   // how many nodes have been deleted	
			}

			else
			{

				node* temp = head;
				node* temp2 = head->next;
				while (temp2 != NULL)
				{
					if (r == temp2->roll_no)
					{
						temp->next = temp2->next;
						delete temp2;

						cout << "record deleted sucessfully." << endl;
						found++;
						break;
					}

					temp = temp2;
					temp2 = temp2->next;
				}
			}
			if (found == 0)
			{
				cout << "no student of " << r << "is present in record to delete." << endl;
			}
		}
	}

	void show()
	{
		if (head == NULL)
		{
			cout << "link list is empty no student exits." << endl;
		}
		else
		{
			node* temp = head;
			while (temp != NULL)
			{
				cout << "the roll number " << temp->roll_no << " is found." << endl;
				cout << "the name of student is: " << temp->name << endl;
				cout << "the marks of student are: " << temp->marks << endl;
				cout << "the percentage of student is: " << temp->per << endl;
				temp = temp->next;
			}
		}
	}
};

student_management obj;
int main()
{

	do
	{
		system("cls");
		cout << endl;
		cout << "\t\t\t\t Student Management System by zeee" << endl;



		int choice;

		cout << endl;
		cout << endl;
		cout << " press 1 to insert the record: " << endl;
		cout << " press 2 to search the record: " << endl;
		cout << " press 3 to check number of students: " << endl;
		cout << " press 4 to update the record: " << endl;
		cout << " press 5 to delete the record: " << endl;
		cout << " press 6 to show all the record: " << endl;
		cout << " press 7 to exit: " << endl;;

		cout << "enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			obj.input_student();
			break;
		case 2:
			system("cls");
			obj.search();
			break;
		case 3:
			system("cls");
			obj.count_student();
			break;
		case 4:
			system("cls");
			obj.update();
		case 5:
			system("cls");
			obj.delete_func();
		case 6:
			obj.show();
			system("cls");
		case 7:
			exit(0);   //built in function 
		default:
			cout << "invalid choice.";
		}

		char ch = _getch();
	} while (true);
	return 0;
}