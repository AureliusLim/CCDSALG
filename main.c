/****************************************************
Group: 		
Section:	
Members:	
****************************************************/

#include <stdio.h>
#include <time.h>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "sort5.h"
#include "sort6.h"
#include "generateData.h"
#include "timer.h"

void tempArray(int A[], int B[]){
	int i;
	for (i = 0; i < sizeof(A) / 4; i++){
		B[i] = A[i];
	}
	B[i]='\n';
}
int main() {
	
	//	your code here
	int i = 0, runs;
	double dCounter;
	struct timespec begin;
	struct timespec end;
	double aveBubb;
	int n = 1024;
	for (i = 0; i < 100; i++){
		int A[n];
		int B[n];
		printf("\n n = %d", n);
		generateData(A,n);
	
		for(runs = 0; runs < 10; runs++){
			tempArray(A,B);
			dCounter = 0;
			
			begin = getTime();
			bubbleSort(B,n,&dCounter);
			end = getTime();
			//printf("\nBubble time: %lf", getElapsed(begin,end));
			aveBubb +=getElapsed(begin,end);
//			mergeSort
//			
//			selectionSort
//			
//			InsertionSort
//			
//			sort5
//			
//			sort6
		}
		aveBubb /= 10;
		printf("\nAverage Bubble Machine Execution Time: %lf", aveBubb);
		n*=2;
	}
	
	return 0;
}
