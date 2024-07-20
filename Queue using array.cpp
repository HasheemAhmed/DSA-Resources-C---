#include <iostream>
using namespace std;

class Queue
{
private:
	int *array, front, rear, size;
public:
	Queue(int size)
	{
		this->size = size;
		front = rear = -1;
		array = new int[size];
	}

	bool isEmpty()
	{
		if (this->front == -1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if ( rear == size - 1)
			return true;
		else
			return false;
	}

	void enqueue(int data)
	{
		if (isFull())
			cout << "Queue is Full." << endl;
		else
		{
			rear++;
			this->array[rear] = data;
			if (front == -1)
				front = 0;
		}
	}

	int dequeue()
	{
		int element;
		if (isEmpty())
		{
			cout << "Queue is Empty. \n";
			return 0;
		}
		else
		{
			element = this->array[front];
			
			if (this->front >= this->rear)
			{
				this->front = this->rear = -1;
			}
			else
				this->front++;
			return element;
		}
	}

	void displayQueue()
	{
		while (!isEmpty())
		{
			cout << this->dequeue() << " -> ";
		}
	}
};

int main()
{
	Queue obj(5);

	obj.enqueue(1);
	obj.enqueue(2);
	obj.dequeue();
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(5);
	obj.dequeue();
	obj.displayQueue();
	return 0;
}