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


int main() {
	
	//	your code here
	int i = 0, runs;
	double dCounter;
	struct timespec begin;
	struct timespec end;
	
	
	int n[10] = {1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	for (i = 0; i < sizeof(n) / 4; i++){
		int A[n[i]];
		printf("\n n = %d", n[i]);
		generateData(A,n[i]);
		
		for(runs = 0; runs < 1; runs++){
			begin = getTime();
			dCounter = 0;
			bubbleSort(A,n[i],&dCounter);
			end = getTime();
			double total = getElapsed(begin,end);
			printf("\nBubble time: %lf",total);
			
//			mergeSort
//			
//			selectionSort
//			
//			bubbleSort
//			
//			sort5
//			
//			sort6
		}
	}
	
	return 0;
}
