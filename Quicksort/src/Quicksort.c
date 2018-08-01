#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct myType
{
	signed long long value;
	int someOtherValue;
}myType;

void quick_sort(myType[], int, int);
int partition(myType[], int, int);



#define ARR_LEN 10
myType myArray[ARR_LEN];

void printArray()
{
	int i;
    for(i = 0; i < ARR_LEN; i++)
    {
    	printf("%lld \t\t %d\n", myArray[i].value, myArray[i].someOtherValue);
    }
    printf("\n\n");
}

void addToArray()
{
	int i = 0;

	for (i = 0; i < ARR_LEN; i++)
	{
		if (myArray[i].value == 0)
		{
			myArray[i].value = rand() - RAND_MAX/2;
			myArray[i].someOtherValue = rand();

		    quick_sort(myArray, 0, ARR_LEN - 1);

			printArray();
		}
	}
}

int main()
{
	int i = 0;
	memset(myArray, 0, sizeof(myArray));
	srand (time(NULL));

	for (i = 0; i < ARR_LEN + 1; i++)
	{
		addToArray();
	}

    return 0;
}

void quick_sort(myType a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(myType a[], int l, int u)
{
    int i, j;
    myType v, temp;
    v = a[l];
    i=l;
    j=u+1;

    do
    {
        do{
        	  i++;
        }
        while(a[i].value < v.value && i <= u);

        do
        {
        	j--;
        }
        while(v.value < a[j].value);

        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);

    a[l] = a[j];
    a[j] = v;

    return j;
}
