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
	double dCounter;
	struct timespec begin;
	struct timespec end;
	double aveBubb = 0;
	double aveIns = 0;
	double aveSel = 0;
	double aveMer = 0;
	double aveQuick = 0;
	double aveHeap = 0;
	int n = 1024;
	for (i = 0; i < 100; i++){
		int A[n];
		int B[n];
		printf("\n n = %d", n);
		generateData(A,n);
	
		for(runs = 0; runs < 1; runs++){
			
			tempArray(A,B);
			dCounter = 0;
			
			begin = getTime(); 
			bubbleSort(B,n,&dCounter);
			end = getTime();
			aveBubb +=getElapsed(begin,end);
		
			/*
			
			tempArray(A,B); // insertion
			begin = getTime();
			insertionSort(B, n, &dCounter);
			end = getTime();
			
			aveIns += getElapsed(begin,end);
			
			tempArray(A,B); // selection
			begin = getTime();
			selectionSort(B, n, &dCounter);
			end = getTime();
			
			aveSel += getElapsed(begin,end);
			
			tempArray(A,B); // merge
			begin = getTime();
			mergeSort(B, n, &dCounter);
			end = getTime();
			
			aveMer += getElapsed(begin,end);
			
			tempArray(A,B); // quick
			begin = getTime();
			sort5(B, n, &dCounter); 
			end = getTime();
			
			aveQuick += getElapsed(begin,end);
			
			tempArray(A,B); // heap
			begin = getTime();
			sort6(B, n, &dCounter);
			end = getTime();
			
			aveHeap += getElapsed(begin,end);*/

		}
		aveBubb /= 10;
//		aveIns /= 10;
//		aveSel /= 10;
//		aveMer /= 10;
//		aveQuick /= 10;
//		aveHeap /= 10;
		printf("\nAve Bubble Sort Machine Execution Time: %lf", aveBubb);
//		printf("\nAve Insertion Sort Machine Execution Time: %lf", aveIns);
//		printf("\nAve Selection Sort Machine Execution Time: %lf", aveSel);
//		printf("\nAve Merge Sort Machine Execution Time: %lf", aveMer);
//		printf("\nAve Quick Sort Machine Execution Time: %lf", aveQuick);
//		printf("\nAve Heap Sort Machine Execution Time: %lf", aveHeap);
		n*=2;
	}
	
	return 0;
}
