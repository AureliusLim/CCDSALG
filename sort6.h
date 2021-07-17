/****************************************************
REFERENCE

Author:
Link:
****************************************************/


/* 
	You may declare additional functions here
*/
	
void set_down(int val[],int counter)
{
	int counter2,temp_val,chk,flag=1;
	chk=val[0];
	
	while(2*counter<=chk && flag==1)
	{//(*dCounter++);
		counter2=2*counter;
		
		if(counter2+1<=chk && val[counter2+1] > val[counter2])
			counter2=counter2+1;
		
		if(val[counter] > val[counter2])
			flag=0;
		
		else
		{
			temp_val=val[counter];
			val[counter]=val[counter2];
			val[counter2]=temp_val;
			counter=counter2;
		}
	}
}
void form(int val[])
{
	int counter,chk;
	chk=val[0];
	for(counter=chk/2;counter>=1;counter--)
		//(*dCounter)++;
		set_down(val,counter);
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
void sort6(int A[], int n, double *dCounter) {
	
	int val[100],chk,counter,end,temp_val, count;
	//double holder = *dCounter;
	A[0]=n;
	form(A);
	while(A[0] > 1)
	{ //(holder)++;
		end=A[0];
		temp_val=A[1];
		A[1]=A[end];
		A[end]=temp_val;
		A[0]--;
		set_down(A,1);
	}
	//*dCounter = holder;
}
	
	
