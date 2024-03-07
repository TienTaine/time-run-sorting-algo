#include "function.h"
#include "algorithms.h"

void creatRandomArray(int* a, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		a[i] = rand() % (size + 1);
	}
}
void creatSortedArray(int* a, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		a[i] = rand() % (size + 1);
	}
	sort(a, a + size);
}

void creatReversedArray(int* a, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) 
	{
		a[i] = rand() % (size + 1);
	}
	sort(a, a+size, greater<int>());
}

void writeFileTXT(int* a, int size,string sortAlgo, string state)
{

	string fileName = sortAlgo + "_" + state + "_" + to_string(size) + ".txt";

	ofstream file(fileName);

	for (int i = 0; i < size; i++) 
	{
		file << a[i] << " ";
	}

	file.close();

}

void creatFileCSV(ofstream& file)
{
	file.open("runtime.csv", ios::out);

	if (!file.is_open())
	{
		file.clear();
		return;
	}

	file << "State,Size,Interchange,Selection,Bubble,Heap,Merge,Quick,Radix" << endl;
	file.close();
}

