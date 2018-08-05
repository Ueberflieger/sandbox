/*
 ============================================================================
 Name        : TidyNumbers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TestCase_s
{
    char *inputNbr;
    char *outputNbr;
} TestCase_t;

int getNumberOfTestCases(FILE *fp);
size_t getLine(char lineptr[], size_t n, FILE *stream);
void printOutput(TestCase_t testCases[], int entries);
void getTestCases(FILE *fp, TestCase_t testCases[]);
void resultToFile(TestCase_t testCases[], int entries, char *outputFile);
int tidyNumbers(int *low, int *high);

int main(void)
{
    FILE *fp;
    int nbrTestCases = 0;

    //char input[] = "input.txt";
    //char input[] = "B-small-practice.in";
    char input[] = "B-large-practice.in";
    char output[] = "output.txt";

    puts("start");

    fp = fopen(input,"r"); // read mode

    if( fp == NULL )
    {
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }

    nbrTestCases = getNumberOfTestCases(fp);
    printf("number of test cases = %d\n", nbrTestCases);

    TestCase_t *testCases = calloc(nbrTestCases, sizeof(TestCase_t));

    getTestCases(fp, testCases);

    int currentCase = 0;
    while (currentCase < nbrTestCases )
    {
        TestCase_t *currentTestCase = &testCases[currentCase];

        int digits = strlen(currentTestCase->inputNbr);
        if (digits > 1)
        {

            int i;
            for (i = 0; i < (digits - 1); i++)
            {
                int low = currentTestCase->outputNbr[i] - 48;
                int high = currentTestCase->outputNbr[i+1] - 48;

                if (tidyNumbers(&low, &high) == 1)
                {
                    currentTestCase->outputNbr[i] = low + 48;
                    currentTestCase->outputNbr[i + 1] = high + 48;

                    memset(&currentTestCase->outputNbr[i+1], '9', digits - (i + 1));
                    i = -1;
                }
            }
        }

        currentCase++;
    }

    printOutput(testCases, nbrTestCases);
    resultToFile(testCases, nbrTestCases, output);

    fclose(fp);

    return 0;
}

int tidyNumbers(int *low, int *high)
{
    int ret = 0;

    if (*low > *high)
    {
        (*low)--;
        *high = 9;
        ret = 1;
    }

    return ret;
}

void getTestCases(FILE *fp, TestCase_t testCases[])
{
    const int LENGTH = 19;
    size_t n = LENGTH;
    char *line = malloc(LENGTH);
    int i = 0;

    while(getLine(line, n, fp) != -1)
    {
        testCases[i].inputNbr = line;
        testCases[i].outputNbr = calloc(LENGTH, 1);
        memcpy(testCases[i].outputNbr, line, LENGTH);
        i++;
        line = malloc(LENGTH);
    }
    free(line);
}

void printOutput(TestCase_t testCases[], int entries)
{
    int i;

    for (i = 0; i < entries; i++)
    {
        printf("Case #%d: \t %s \t %d\n", i + 1, testCases[i].inputNbr, atoi(testCases[i].outputNbr));
        //printf("Case #%d: \t %s \t %I64d\n", i + 1, testCases[i].inputNbr, atoll(testCases[i].outputNbr));
    }
}

void resultToFile(TestCase_t testCases[], int entries, char *outputFile)
{
    FILE *fp;
    fp = fopen(outputFile,"wb"); // read mode

    if( fp == NULL )
    {
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < entries; i++)
    {
        fprintf(fp, "Case #%d: %I64d\n", i + 1, atoll(testCases[i].outputNbr));
    }

    fclose(fp);
}

int getNumberOfTestCases(FILE *fp)
{
    size_t n = 4;
    char *line = malloc(4);

    getLine(line, n, fp);
    return atoi(line);
}

size_t getLine(char lineptr[], size_t n, FILE *stream)
{
    int i = 0;
    char c = getc(stream);

    while(c != EOF && c != '\n')
    {
       lineptr[i++] = c;
       c = getc(stream);
    }

    lineptr[i] = '\0';

    if (c == EOF)
    {
        return -1;
    }

    return 0;
}
