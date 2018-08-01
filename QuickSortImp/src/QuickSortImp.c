/*
 ============================================================================
 Name        : QuickSortImp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



void quicksort(int array[], int length)
{
	my_quicksort(array, 0, length - 1);
}

void my_quicksort(int array[], int min, int max)
{
	int posOfPivot = pivot(array, max);
	my_quicksort(array, min, posOfPivot - 1);
	my_quicksort(array, posOfPivot, max);
}


int pivot(int array[], int pivot)
{
	int posOfPivot = pivot;
	int i, j;

	for(i = 0; i < pivot; i++)
	{
		for(j = 0; j < pivot; j++)
		{

		}
	}


	return posOfPivot;
}


int main(void)
{
	int array[] = {4, 2, 1, 7, 21};

	quicksort(array, 5);


	return EXIT_SUCCESS;
}


