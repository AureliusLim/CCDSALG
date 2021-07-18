/****************************************************
REFERENCE

/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void quicksort_method(int A[], int low, int high, double *dCounter)
{
	int pivot, value1, value2, temp;
	
	if (low < high)
	{
		pivot = low;
		value1 = low;
		value2 = high;
		while (value1 < value2)
		{ 
			while (A[value1] <= A[pivot] && value1 <= high)
				value1++;
		
			while (A[value2] > A[pivot] && value2 >= low)
				value2--;
			
			if (value1 < value2)
			{
				temp = A[value1];
				A[value1] = A[value2];
				A[value2] = temp;
			}
		}
	
		temp = A[value2];
		A[value2] = A[pivot];
		A[pivot] = temp;
		quicksort_method(A, low, value2 - 1,dCounter);
		quicksort_method(A, value2 + 1, high,dCounter);
	}
	
	(*dCounter)++;
}

/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using <fill this> sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void quickSort(int A[], int n, double *dCounter) {
	
	quicksort_method(A, 0, n - 1,dCounter);
}




