#include <stdio.h>

// Function to swap two integers using arithmetic operations
void	fswap(int *a, int *b)
{
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}

// Function to partition the array around the pivot element
int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	pi;
	int	i;

	pi = start;
	i = start;
	pivot = arr[end]; // Pivot is always the last element in the array
	while (i < end)
	{
		if (arr[i] <= pivot)
		{
			fswap(&arr[i], &arr[pi]);
			// Swap elements if they are less than or equal to the pivot
			pi = pi + 1; // Move the partition index
		}
		i++;
	}
	// Swap the pivot element with the element at the partition index
	fswap(&arr[pi], &arr[end]);
	return (pi); // Return the partition index
}

// Recursive function to perform Quick Sort
void	quick_sort(int *array, int start, int end)
{
	int	pindex;

	if (start >= end)
		return ; // Base case: if the array has one or zero elements,
				// it's already sorted
	// Get the partitioning index
	pindex = partition(array, start, end);
	// Recursively sort the left and right subarrays
	quick_sort(array, start, pindex - 1);
	quick_sort(array, pindex + 1, end);
}

// Wrapper function to initiate Quick Sort
void	Qsort_array(int *array, int size)
{
	quick_sort(array, 0, size - 1);
}

// Function to print an array
void	print_array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int	main(void)
{
	int array[] = {10, 7, 8, 9, 1, 5};
	int size = sizeof(array) / sizeof(array[0]);

	printf("Original array: ");
	print_array(array, size);

	Qsort_array(array, size);

	printf("Sorted array: ");
	print_array(array, size);

	return (0);
}