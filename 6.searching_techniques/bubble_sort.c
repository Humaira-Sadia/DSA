// C program for implementation of Bubble Sort
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 5, 1, 4, 2, 8 };
	int length = sizeof(arr);

    printf("Original Array: \n");
	printArray(arr, length);

	bubbleSort(arr, length);
	printf("Sorted Array: \n");
	printArray(arr, length);

	return 0;
}
