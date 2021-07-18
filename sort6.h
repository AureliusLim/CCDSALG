/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
	
void set_down(int A[],int counter)
{
	int counter2,temp,chk,flag=1;
	chk=A[0];
	
	while(2*counter<=chk && flag==1)
	{
		counter2=2*counter;
		
		if(counter2+1<=chk && A[counter2+1] > A[counter2])
			counter2=counter2+1;
		
		if(A[counter] > A[counter2])
			flag=0;
		
		else
		{
			temp=A[counter];
			A[counter]=A[counter2];
			A[counter2]=temp;
			counter=counter2;
		}
	}
}

void form(int A[])
{
	int counter,chk;
	chk=A[0];
	for(counter=chk/2;counter>=1;counter--)
		set_down(A,counter);
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
void heapSort(int A[], int n, double *dCounter) {
	
	int end,temp_val;
		
	A[0]=n;
	form(A);
	while(A[0] > 1)
	{
		(*dCounter)++;
		end=A[0];
		temp_val=A[1];
		A[1]=A[end];
		A[end]=temp_val;
		A[0]--;
		set_down(A,1);		
	}
	(*dCounter)++;
}
	
	
