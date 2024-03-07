#include "algorithms.h"
#include "function.h"

// bubble sort
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// interchange sort
void interchangesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
               swap(a[i], a[j]);
            }
        }
    }
}

// selection sort
void selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (a[min] > a[j]) 
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

// heap sort
void heapify(int a[], int size, int node)
{
    int max = node;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    if (left_node < size && a[max] < a[left_node]) max = left_node;
    if (right_node < size && a[max] < a[right_node]) max = right_node;
    if (max != node)
    {
        swap(a[max], a[node]);
        heapify(a, size, max);
    }
}

void buildheap(int a[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(a, size, i);
    }
}

void heapsort(int a[], int size)
{
    buildheap(a, size);
    for (int i = size - 1; i > 0; i--) 
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// quick sort
void quicksort(int a[], int left, int right)
{
    int mid = a[(left + right) / 2];
    int i = left, j = right;
    while (i < j)
    {
        while (a[i] < mid) 
        {
            i++;
        }
        while (a[j] > mid) 
        {
            j--;
        }
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right) 
    {
        quicksort(a, i, right); 
    }
    if (left < j) 
    {
        quicksort(a, left, j);
    }
}
// merge sort
void merge(int a[], int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] < R[j]) 
        {
            a[k++] = L[i++];
        }
        else 
        {
            a[k++] = R[j++];
        }
    }
    while (i < n1) 
    {
        a[k++] = L[i++];
    }
    while (j < n2) 
    {
        a[k++] = R[j++];
    }
    delete[] L;
    delete[] R;
}

void mergesort(int a[], int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    merge(a, left, right, mid);
}

// radix sort
int getMax(int a[], int size) {
    int mx = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    return mx;
}
void countsort(int a[],int size, int exp)
{
    int* output = new int[size];
    int bucket[10] = { 0 };
    for (int i = 0; i < size; i++) 
    {
        bucket[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) 
    {
        bucket[i] += bucket[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) 
    {
        output[bucket[(a[i] / exp) % 10] - 1] = a[i];
        bucket[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++) 
    {
        a[i] = output[i];
    }
    delete[] output;
}
void radixsort(int a[], int size)
{
    int m = getMax(a, size);
    for (int exp = 1; m / exp > 0; exp *= 10) 
    {
        countsort(a, size, exp);
    }
}