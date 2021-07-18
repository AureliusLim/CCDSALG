/****************************************************
REFERENCE

Author:
Link:https://www.geeksforgeeks.org/generating-random-number-range-c/
****************************************************/


/****************************************************
YOU ARE NOT ALLOWED TO MODIFY THE FUNCTION PROTOTYPES
****************************************************/


#include <stdlib.h> 
#include <time.h> 

void generateData (int A[], int n) {   
    //	your code here
    int i,num;
    srand(time(0));
	for (i = 0; i < n; i++){
    	A[i]= rand();
	}
}
