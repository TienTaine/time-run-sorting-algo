	#include "algorithms.h"
#include "function.h"

int main()
{
	ofstream fileCSV;
	creatFileCSV(fileCSV);
	int sizes[] = { 1000, 3000, 10000, 30000, 100000 };
	for (int i : sizes)
	{
		int* a = new int[i];
		int* a1 = new int[i];
		int* a2 = new int[i];
		int* a3 = new int[i];
		int* a4 = new int[i];
		int* a5 = new int[i];
		int* a6 = new int[i];

		creatRandomArray(a, i);	
		copy(a, a + i, a1);
		copy(a, a + i, a2);
		copy(a, a + i, a3);
		copy(a, a + i, a4);
		copy(a, a + i, a5);
		copy(a, a + i, a6);

		clock_t begin = clock();
		bubblesort(a, i);
		clock_t end = clock();
		writeFileTXT(a, i, "BubbleSort", "Random");
		double timeRun_BubbleSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		selectionsort(a1, i);
		end = clock();
		writeFileTXT(a1, i, "SelectionSort", "Random");
		double timeRun_SelectionSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		interchangesort(a2, i);
		end = clock();
		writeFileTXT(a2, i, "InterchangeSort", "Random");
		double timeRun_InterchangeSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		heapsort(a3, i);
		end = clock();
		writeFileTXT(a3, i, "HeapSort", "Random");
		double timeRun_HeapSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		mergesort(a4,0,i-1);
		end = clock();
		writeFileTXT(a4, i, "MergeSort", "Random");
		double timeRun_MergeSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		quicksort(a5,0,i-1);
		end = clock();
		writeFileTXT(a5, i, "QuickSort", "Random");
		double timeRun_QuickSort = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		radixsort(a6, i);
		end = clock();
		writeFileTXT(a6, i, "RadixSort", "Random");
		double timeRun_RadixSort = double(end - begin) / CLOCKS_PER_SEC;

		fileCSV.open("runtime.csv", ios::app);
		fileCSV << "Random," << i << "," << timeRun_InterchangeSort << "," << timeRun_SelectionSort << "," << timeRun_BubbleSort << "," << timeRun_HeapSort << "," << timeRun_MergeSort << "," << timeRun_QuickSort << "," <<  timeRun_RadixSort << endl;
		fileCSV.close();

		delete[] a;
		a = NULL;
		delete[] a1;
		a1 = NULL;
		delete[] a2;
		a2 = NULL;
		delete[] a3;
		a3 = NULL;
		delete[] a4;
		a4 = NULL;
		delete[] a5;
		a5 = NULL;
		delete[] a6;
		a6 = NULL;
	}

	for (int j : sizes)
	{
		int* a = new int[j];
		int* a1 = new int[j];
		int* a2 = new int[j];
		int* a3 = new int[j];
		int* a4 = new int[j];
		int* a5 = new int[j];
		int* a6 = new int[j];

		creatSortedArray(a, j);
		copy(a, a + j, a1);
		copy(a, a + j, a2);
		copy(a, a + j, a3);
		copy(a, a + j, a4);
		copy(a, a + j, a5);
		copy(a, a + j, a6);

		clock_t begin = clock();
		bubblesort(a, j);
		clock_t end = clock();
		writeFileTXT(a, j, "BubbleSort", "Sorted");
		double timeRun_BubbleSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		selectionsort(a1, j);
		end = clock();
		writeFileTXT(a1, j, "SelectionSort", "Sorted");
		double timeRun_SelectionSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		interchangesort(a2, j);
		end = clock();
		writeFileTXT(a2, j, "InterchangeSort", "Sorted");
		double timeRun_InterchangeSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		heapsort(a3, j);
		end = clock();
		writeFileTXT(a3, j, "HeapSort", "Sorted");
		double timeRun_HeapSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		mergesort(a4, 0, j - 1);
		end = clock();
		writeFileTXT(a4, j, "MergeSort", "Sorted");
		double timeRun_MergeSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		quicksort(a5, 0, j - 1);
		end = clock();
		writeFileTXT(a5, j, "QuickSort", "Sorted");
		double timeRun_QuickSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		radixsort(a6, j);
		end = clock();
		writeFileTXT(a6, j, "RadixSort", "Sorted");
		double timeRun_RadixSort_Sorted = double(end - begin) / CLOCKS_PER_SEC;

		fileCSV.open("runtime.csv", ios::app);
		fileCSV << "Sorted," << j << "," << timeRun_InterchangeSort_Sorted << "," << timeRun_SelectionSort_Sorted << "," << timeRun_BubbleSort_Sorted << "," << timeRun_HeapSort_Sorted << "," << timeRun_MergeSort_Sorted << "," << timeRun_QuickSort_Sorted << "," << timeRun_RadixSort_Sorted << endl;
		fileCSV.close();

		delete[] a;
		a = NULL;
		delete[] a1;
		a1 = NULL;
		delete[] a2;
		a2 = NULL;
		delete[] a3;
		a3 = NULL;
		delete[] a4;
		a4 = NULL;
		delete[] a5;
		a5 = NULL;
		delete[] a6;
		a6 = NULL;

	}

	for (int k : sizes)
	{
		int* a = new int[k];
		int* a1 = new int[k];
		int* a2 = new int[k];
		int* a3 = new int[k];
		int* a4 = new int[k];
		int* a5 = new int[k];
		int* a6 = new int[k];

		creatReversedArray(a, k);
		copy(a, a + k, a1);
		copy(a, a + k, a2);
		copy(a, a + k, a3);
		copy(a, a + k, a4);
		copy(a, a + k, a5);
		copy(a, a + k, a6);

		clock_t begin = clock();
		bubblesort(a, k);
		clock_t end = clock();
		writeFileTXT(a, k, "BubbleSort", "Reversed");
		double timeRun_BubbleSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		selectionsort(a1, k);
		end = clock();
		writeFileTXT(a1, k, "SelectionSort", "Reversed");
		double timeRun_SelectionSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		interchangesort(a2, k);
		end = clock();
		writeFileTXT(a2, k, "InterchangeSort", "Reversed");
		double timeRun_InterchangeSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		heapsort(a3, k);
		end = clock();
		writeFileTXT(a3, k, "HeapSort", "Reversed");
		double timeRun_HeapSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		mergesort(a4, 0, k - 1);
		end = clock();
		writeFileTXT(a4, k, "MergeSort", "Reversed");
		double timeRun_MergeSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		quicksort(a5, 0, k - 1);
		end = clock();
		writeFileTXT(a5, k, "QuickSort", "Reversed");
		double timeRun_QuickSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		radixsort(a6, k);
		end = clock();
		writeFileTXT(a6, k, "RadixSort", "Reversed");
		double timeRun_RadixSort_Reversed = double(end - begin) / CLOCKS_PER_SEC;

		fileCSV.open("runtime.csv", ios::app);
		fileCSV << "Reversed," << k << "," << timeRun_InterchangeSort_Reversed << "," << timeRun_SelectionSort_Reversed << "," << timeRun_BubbleSort_Reversed << "," << timeRun_HeapSort_Reversed << "," << timeRun_MergeSort_Reversed << "," << timeRun_QuickSort_Reversed << "," << timeRun_RadixSort_Reversed << endl;
		fileCSV.close();

		delete[] a;
		a = NULL;
		delete[] a1;
		a1 = NULL;
		delete[] a2;
		a2 = NULL;
		delete[] a3;
		a3 = NULL;
		delete[] a4;
		a4 = NULL;
		delete[] a5;
		a5 = NULL;
		delete[] a6;
		a6 = NULL;
	}
	return 0;
}