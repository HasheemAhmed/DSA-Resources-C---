#include <iostream>
using namespace std;
#include <list>

class student
{
	int rollno;
	string name;
public:
	student() {};
	student(string n, int r) :name(n), rollno(r) {};

	int getrollno()
	{
		return this->rollno;
	}

	string getname()
	{
		return this->name;
	}
};

class HashTable
{
private:
	int sizeOfList;
	list<student>* table;
public:
	HashTable(int size)
	{
		this->sizeOfList = size;
		table = new list<student>[this->sizeOfList];
	}

	int HashFunction(int data)
	{
		return data % this->sizeOfList;
	}

	void InsertData(string name, int rollno)
	{
		student obj(name, rollno);
		table[HashFunction(rollno)].push_back(obj);
	}

	void DeleteData(int rollno)
	{
		int index = HashFunction(rollno);
		student obj;
		list<student> ::iterator i;
		for (i = this->table[index].begin(); i != this->table[index].end(); i++)
		{
			obj = *i;
			if (obj.getrollno() == rollno)
				break;
		}

		if (i != table[index].end())
			table[index].erase(i);
	}

	void DisplayHash()
	{
		for (int i = 0; i < sizeOfList; i++)
		{
			cout << "table[" << i << "]";

			for (auto x : table[i])
				cout << " --> " <<x.getname() << "  " << x.getrollno();
			cout << endl;
		}
	}

};

int main()
{
	HashTable ht(5);

	ht.InsertData("Hasheem",10);
	ht.InsertData("Rehan",5);
	ht.InsertData( "Atif",7);
	ht.InsertData("Usman",9);
	ht.InsertData("Ahmed",12);

 ht.DeleteData(10);
	ht.DisplayHash();

	return 0;
}