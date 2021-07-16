/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
void quicksort_method(int element_list[], int low, int high)
{
	int pivot, value1, value2, temp;
	
	if (low < high)
	{
		pivot = low;
		value1 = low;
		value2 = high;
		while (value1 < value2)
		{
			while (element_list[value1] <= element_list[pivot] && value1 <= high)
			{
				value1++;
			}
			
			while (element_list[value2] > element_list[pivot] && value2 >= low)
			{
				value2--;
			}
			
			if (value1 < value2)
			{
				temp = element_list[value1];
				element_list[value1] = element_list[value2];
				element_list[value2] = temp;
			}
		}
	
		temp = element_list[value2];
		element_list[value2] = element_list[pivot];
		element_list[pivot] = temp;
		quicksort_method(element_list, low, value2 - 1);
		quicksort_method(element_list, value2 + 1, high);
	}
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
void sort5(int A[], int n, double *dCounter) {
	
	int element_list[50],count, counter;
	
	quicksort_method(A, 0, n - 1);
}


