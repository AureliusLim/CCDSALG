/****************************************************
REFERENCE

Author:
Link:
****************************************************/

/* 
	You may declare additional functions here
*/

void perfrom_merge(int val[],int counter11,int counter12,int counter22,int counter21)
{
	int temp_val[50];
	int c1,c2,c3;
	c1=counter11;
	c2=counter22;
	c3=0;
	while(c1<=counter12 && c2<=counter21)
	{
		if(val[c1]<val[c2])
			temp_val[c3++]=val[c1++];
		else
			temp_val[c3++]=val[c2++];
	}
	while(c1<=counter12)
		temp_val[c3++]=val[c1++];
		
	while(c2<=counter21)
		temp_val[c3++]=val[c2++];
		
	for(c1=counter11,c2=0;c1<=counter21;c1++,c2++)
		val[c1]=temp_val[c2];
}

void algo_merge_sort(int val[],int counter1,int counter2)
{
	int mid;
	if(counter1<counter2)
	{
		mid=(counter1+counter2)/2;
		algo_merge_sort(val,counter1,mid);
		algo_merge_sort(val,mid+1,counter2);
		perfrom_merge(val,counter1,mid,mid+1,counter2);
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

	algo_merge_sort(A,0,n-1);
	
}
