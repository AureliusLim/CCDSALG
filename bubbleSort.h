/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


/*
	Sorts the array A using bubble sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/

void bubbleSort(int A[], int n, double *dCounter) {
	int counter, counter1, swap_var;
	
	for (counter= 0 ; counter < n - 1; counter++)
	{
		for (counter1 = 0 ; counter1 < n - counter - 1; counter1++)
		{
			if (A[counter1] > A[counter1+1]) /* For decreasing order use < */
			{
				swap_var = A[counter1];
				A[counter1] = A[counter1+1];
				A[counter1+1] = swap_var;
			}
		}
	}
	
}
