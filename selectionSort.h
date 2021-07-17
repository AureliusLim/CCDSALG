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
	Sorts the array A using selection sorting algorithm.

	@param int A[] 			array to be sorted
	@param int n			size of the array to be sorted
	@param double *dCounter	counter variable for critical parts of the code
*/
void selectionSort(int A[], int n, double *dCounter) {

	int total_count,counter1,counter2,minimum,temp_value;
	
	for(counter1=0;counter1<n-1;counter1++)
	{ (*dCounter)++;
		minimum=counter1;
		for(counter2=counter1+1;counter2<n;counter2++)
		{(*dCounter)++;
			if(A[minimum]>A[counter2])
			minimum=counter2;
		}
		
		if(minimum!=counter1)
		{
			temp_value=A[counter1];
			A[counter1]=A[minimum];
			A[minimum]=temp_value;
		}
	}

}
