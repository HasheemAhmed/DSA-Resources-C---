#include <iostream>
using namespace std;

void merge(int* array, int start,int mid, int end)
{
	int *L = new int[mid];
	int en = end - mid+1;
	int* M = new int[en];

	for (int i = 0; i < mid; i++)
		L[i] = array[i];
	for (int i = mid+1 ; i < end; i++)
		M[i] = array[i];

	int i, j;
	i = j = 0;

	while (i < mid && j < end)
	{
		int k = 0;
		if (L[i] < M[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = M[j];
			j++;
		}
		k++;
	}


}

void mergeSort(int* array, int start, int end)
{
	if (start < end)
	{
		int mid = end / 2;

		mergeSort(array, start,mid);
		mergeSort(array, mid + 1, end);

		merge(array, start,mid, end);
	}

}


/* --- Swap Function for Swapping values --- */

void swap(int* array, int x, int y)
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

/* --- Partition Function For Quick Sorting --- */

int partition(int *array , int low , int high)
{
	int element = low;

	for (int i = low; i < high; i++)
	{
		if (array[i] < array[high])
		{
			swap(array, i,element);
			element++;
		}
	}

	swap(array, element, high);

	return (element);
}

/* --- Quick Sorting --- */

void quickSort(int* array, int start, int end)
{
	if (start < end)
	{
		int part = partition(array, start, end-1);

		quickSort(array, start, part);
		quickSort(array, part + 1, end);
	}
}

/* --- Selection Sorting --- */

void selectionSort(int* array, int size)
{
	int i = 0;
	int minValueIndex;
	while (i < size)
	{
		minValueIndex = i;
		for (int j = i + 1; j < size ; j++)
		{
			if (array[j] < array[minValueIndex])
			{
				minValueIndex = j;
			}
		}
		swap(array, i, minValueIndex);
		i++;
	}
}

/* --- Bubble Sort --- */

void bubbleSort(int* array, int size)
{
	bool sort = false;
	while (!sort)
	{
		sort = true;
		for (int i = 0,j = 1; i <size && j < size; j++,i++)
		{
			if (array[j] < array[i])
			{
				swap(array, i, j);
				sort = false;
			}
		}
	}
}

/* --- Insertion Sorting --- */

void insertionSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int j = i - 1;

		while(j >= 0 && key < array[j])
		{
			array[j+1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

/* --- Inputing Values in Array --- */

void input(int *array,int size)
{
	cout << "Enter the elements in array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

/* --- Displaying Values --- */

void display(int* array,int size)
{
	cout << "Elements in array are : \n";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] <<endl;
	}
}

/* --- Main Functoin --- */

int main()
{
	int size;
	cout << "Enter the size if array : \n";
	cin >> size;

	int *array = new int[size](); // Dynamic Array

	input(array,size);

	/* --- Sorting Functions --- */

	//quickSort(array, 0, size);
	//insertionSort(array, size);
	//selectionSort(array, size);
	//bubbleSort(array, size);

	/* --- Display Function --- */

	display(array,size);

	return 0;
}