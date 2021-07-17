/****************************************************
REFERENCE

Author:
Link:
****************************************************/

/* 
	You may declare additional functions here
*/

void perfrom_merge(int A[],int counter11,int counter12,int counter22,int counter21,double *dCounter)
{
	int temp_val[50];
	int c1,c2,c3;
	c1=counter11;
	c2=counter22;
	c3=0;
	while(c1<=counter12 && c2<=counter21)
	{(*dCounter)++;
		if(A[c1]<A[c2])
			temp_val[c3++]=A[c1++];
		else
			temp_val[c3++]=A[c2++];
	}
	while(c1<=counter12)
		temp_val[c3++]=A[c1++];(*dCounter)++;
		
	while(c2<=counter21)(*dCounter)++;
		temp_val[c3++]=A[c2++];
		
	for(c1=counter11,c2=0;c1<=counter21;c1++,c2++)(*dCounter)++;
		A[c1]=temp_val[c2];
}

void algo_merge_sort(int A[],int low,int high,double *dCounter)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		algo_merge_sort(A,low,mid,dCounter);
		algo_merge_sort(A,mid+1,high,dCounter);
		perfrom_merge(A,low,mid,mid+1,high,dCounter);
		(*dCounter)++;
	}
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
void mergeSort(int A[], int n, double *dCounter) {

	int counter1;

	algo_merge_sort(A,0,n-1,dCounter);
	
}
