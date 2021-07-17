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
	B[i]='\0';
}
int main() {
	
	//	your code here
	int i = 0, runs = 0;
	double dBubb = 0, dIns = 0,dSel = 0, dMer = 0, dQ = 0;
	struct timespec begin;
	struct timespec end;
	double aveBubb = 0, aveIns = 0, aveSel = 0, aveMer = 0, aveQ = 0, aveHeap = 0;
	int n = 1024;
	for (i = 0; i < 10; i++){
		int A[n];
		int B[n];
		printf("\n\n n = %d", n);
		generateData(A,n);
	
		for(runs = 0; runs < 10; runs++){
			
			tempArray(A,B);
			
			begin = getTime(); 
			bubbleSort(B,n,&dBubb);
			end = getTime();
			aveBubb +=getElapsed(begin,end);	
			
			tempArray(A,B); // insertion
			begin = getTime();
			insertionSort(B, n, &dIns);
			end = getTime();
			
			aveIns += getElapsed(begin,end);
			
			tempArray(A,B); // selection
			begin = getTime();
			selectionSort(B, n, &dSel);
			end = getTime();
			
			aveSel += getElapsed(begin,end);
			
			/*
			tempArray(A,B); // merge
			begin = getTime();
			mergeSort(B, n, &dMer);
			end = getTime();
			
			aveMer += getElapsed(begin,end);*/
			
			tempArray(A,B); // quick
			begin = getTime();
			sort5(B, n, &dQ); 
			end = getTime();
			
			aveQ += getElapsed(begin,end);
			/*
			tempArray(A,B); // quick
			begin = getTime();
			sort6(B, n, &dQ);
			end = getTime();
			
			aveQ += getElapsed(begin,end);*/

		}

		printf("\nAve Bubble Sort Machine Execution Time: %lf", aveBubb / 10);
		
		printf("\nAve Insertion Sort Machine Execution Time: %lf", aveIns / 10);
	
		printf("\nAve Selection Sort Machine Execution Time: %lf", aveSel / 10);
		//		printf("\nAve Merge Sort Machine Execution Time: %lf", aveMer);
		printf("\nAve Merge Sort Machine Execution Time: %lf", aveMer / 10);
		printf("\nAve Quick Sort Machine Execution Time: %lf", aveQ / 10);
		
		printf("\n\nAve dCounter of Bubble Sort: %lf", dBubb) / 10;
		printf("\nAve dCounter of Insertion Sort: %lf", dIns / 10);
		printf("\nAve dCounter of Selection Sort: %lf", dSel / 10);
		printf("\nAve dCounter of Merge Sort: %lf", dMer/ 10);
		printf("\nAve dCounter of Quick Sort: %lf", dQ / 10);

//		printf("\nAve Quick Sort Machine Execution Time: %lf", aveQuick);
//		printf("\nAve Heap Sort Machine Execution Time: %lf", aveHeap);
		n*=2;
	}
	
	return 0;
}
