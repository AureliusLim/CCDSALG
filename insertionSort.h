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
	Sorts the array A using insertion sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void insertionSort(int A[], int n, double *dCounter) {

	int counter1,counter2,temp_val;
	
	for(counter1 = 1; counter1 < n ;(counter1)++)
	{(*dCounter)++;
	
		temp_val=A[counter1];
		counter2=(counter1)-1;
		while((temp_val<A[counter2])&&(counter2>=0))
		{(*dCounter)++;
			A[counter2+1]=A[counter2];
			counter2=counter2-1;
		}
		A[counter2+1]=temp_val;
	}
	
}
