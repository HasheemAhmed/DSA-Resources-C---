#include <iostream>
using namespace std;
#include <list>

class HashTable
{
private:
	int sizeOfList;
	list<int> *table;
public:
	HashTable(int size)
	{
		this->sizeOfList = size;
		table = new list<int>[this->sizeOfList];
	}

	int HashFunction(int data)
	{
		return data % this->sizeOfList;
	}

	void InsertData(int data)
	{
		table[HashFunction(data)].push_back(data);
	}

	void DeleteData(int data)
	{
		int index = HashFunction(data);
		
		list<int> ::iterator i;
		for (i = this->table[index].begin(); i != this->table[index].end(); i++)
		{
			if (*i == data)
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
				cout << " --> " << x;
			cout << endl;
		}
	}

};

int main()
{
	HashTable ht(5);

	ht.InsertData(10);
	ht.InsertData(5);
	ht.InsertData(7);
	ht.InsertData(9);
	ht.InsertData(12);

	ht.DeleteData(10);
	ht.DisplayHash();

	return 0;
}