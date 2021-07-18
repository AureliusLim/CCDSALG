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
		
		int A[n];
		int B[n];
		printf("\n\n n = %d", n);
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

		printf("\nAve Bubble Sort Machine Execution Time: %lf", aveBubb / 10);
		
		printf("\nAve Insertion Sort Machine Execution Time: %lf", aveIns / 10);
	
		printf("\nAve Selection Sort Machine Execution Time: %lf", aveSel / 10);
		printf("\nAve Merge Sort Machine Execution Time: %lf", aveMer / 10);
		printf("\nAve Quick Sort Machine Execution Time: %lf", aveQ / 10);
		printf("\nAve Heap Sort Machine Execution Time: %lf", aveH / 10);
		
		
		printf("\n\nAve dCounter of Bubble Sort: %lf", dBubb/10);
		printf("\nAve dCounter of Insertion Sort: %lf", dIns / 10);
		printf("\nAve dCounter of Selection Sort: %lf", dSel / 10);
		printf("\nAve dCounter of Merge Sort: %lf", dMer/ 10);
		printf("\nAve dCounter of Quick Sort: %lf", dQ / 10);
		printf("\nAve dCounter of Heap Sort: %lf", dH / 10);

		n*=2;
		
	}
	
	return 0;
}
