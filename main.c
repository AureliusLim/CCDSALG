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

void tempArray(int A[], int B[], int n){		////setup temporary array copy
	int i;
	for (i = 0; i < n; i++){
		B[i] = A[i];
	}
}

int main() 
{
	//	your code here
	int i = 0, runs = 0;
	double dBubb, dIns,dSel, dMer, dQ, dH;
	struct timespec begin;
	struct timespec end;
	double aveBubb, aveIns, aveSe, aveMer, aveQ, aveH;
	int n = 1024;
	for (i = 0; i < 10; i++)
	{
		double dBubb = 0, dIns = 0,dSel = 0, dMer = 0, dQ = 0, dH=0;
		double aveBubb = 0, aveIns = 0, aveSel = 0, aveMer = 0, aveQ = 0, aveH = 0;
		
//		int A[n];
//		int B[n];
		int * A= malloc(n * sizeof(int));
		int * B = malloc(n * sizeof(int));
		printf("\n\n--  N:  %d  -- ", n);
		generateData(A,n);						//generate random array of numbers
	
		for(runs = 0; runs < 10; runs++)		//deviation/average time checker
		{
			
			tempArray(A,B,n);					//setup temporary array copy
			
			 // bubble
			begin = getTime(); 
			bubbleSort(B,n,&dBubb);
			end = getTime();
			aveBubb +=getElapsed(begin,end);
	
			tempArray(A,B,n);
			
			//insertion
			begin = getTime();
			insertionSort(B, n, &dIns);
			end = getTime();
			aveIns += getElapsed(begin,end);
			
			
			// selection
			tempArray(A,B,n); 
			
			begin = getTime();
			selectionSort(B, n, &dSel);
			end = getTime();
			aveSel += getElapsed(begin,end);
			
			// merge
			tempArray(A,B,n); 
			
			begin = getTime();
			mergeSort(B, n, &dMer);
			end = getTime();
			aveMer += getElapsed(begin,end);
			
			// quick
			tempArray(A,B,n); 
			
			begin = getTime();
			quickSort(B, n, &dQ); 
			end = getTime();
			aveQ += getElapsed(begin,end);
			
			//heap
			tempArray(A,B,n); 
			
			begin = getTime();
			heapSort(B, n, &dH);
			end = getTime();		
			aveH += getElapsed(begin,end);

		}
		printf("\n\nBubble Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveBubb / 10) * 1000);
		printf("\nAverage counter value: %lf", dBubb/10);
		
		printf("\n\nInsertion Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveIns / 10) * 1000);
		printf("\nAverage counter value: %lf", dIns /10);
		
		printf("\n\nSelection Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveSel / 10) * 1000);
		printf("\nAverage counter value: %lf", dSel/10);
		
		printf("\n\nMerge Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveMer / 10) * 1000);
		printf("\nAverage counter value: %lf", dMer/10);
		
		printf("\n\nQuick Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveQ / 10) * 1000);
		printf("\nAverage counter value: %lf", dQ /10);
		
		printf("\n\nHeap Sort:");
		printf("\nAverage MET: %lf milliseconds", (aveH / 10) * 1000);
		printf("\nAverage counter value: %lf", dH/10);

		n*=2;
		free(A);
		free(B);
	}
	
	return 0;
}
