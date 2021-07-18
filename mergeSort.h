/****************************************************
REFERENCE

Author:
Link:
****************************************************/

/* 
	You may declare additional functions here
*/

void merge(int A[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortAlgo(int A[], int left, int right,double *dCounter)
{
	if (left < right) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int mid = left + (right - left) / 2;

		// Sort first and second halves
		mergeSortAlgo(A, left, mid,dCounter);
		mergeSortAlgo(A, mid + 1, right,dCounter);

		merge(A, left, mid, right);
	}
	(*dCounter)++;
}
/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/

/*
	Sorts the array A using merge sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void mergeSort(int A[],int n,double *dCounter)
{
	mergeSortAlgo(A,0,n-1,dCounter);
}
