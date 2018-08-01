/*
 ============================================================================
 Name        : longestContSubarray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0

typedef int bool;

bool fit(int arr[], int len, int startIdx, int endIdx)
{
	bool ret = false;

	if ((startIdx < len) || (endIdx < len))
	{
		if ((arr[endIdx] - arr[startIdx]) < (endIdx - startIdx))
		{
			ret = true;
		}
	}

	return ret;
}

int findLength(int arr[], int len)
{
	int foundLength = 1;
	int remLen = len;
	int startIdx = 0;
	int endIdx = 1;
	int min, max;

	do
	{

		if (fit() == false)
		{
			startIdx++;
		}

		if (fit() == true)
		{
			foundLength = endIdx - startIdx + 1;
			endIdx++;
		}


		foundLength = endIdx - startIdx + 1;
		if ((arr[endIdx] - arr[startIdx]) > remLen)
		{
			remLen = remLen - startIdx;
			startIdx = endIdx;
			endIdx++;
		}
	}while (foundLength <= remLen);

	return foundLength;
}

int main(void)
{
    int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",findLength(arr, n));

    return 0;
}
