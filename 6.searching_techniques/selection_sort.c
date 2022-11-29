// C program for implementation of Selection Sort
#include <stdio.h>

void selectionSort(int arr[], int n)
{
	int i, j, pos;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		pos = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[pos])
			pos = j;

		// Swap the found minimum element with the first element
		if(pos != i)
			swap(&arr[pos], &arr[i]);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {5,6,4,7,9,8,9,3,1,2};
	int length = sizeof(arr)/sizeof(arr[0]);
    printf("original array: \n");
	printArray(arr, length);
	selectionSort(arr, length);
	printf("Sorted array: \n");
	printArray(arr, length);
	return 0;
}
