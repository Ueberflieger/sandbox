/*
 ============================================================================
 Name        : FlipPancakes.c
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
    char *pancakes;
    int numberOfPancakes;
    int panSize;
    int output;
} TestCase_t;

int* createOutputArray(int size);
int getNumberOfTestCases(FILE *fp);
size_t getLine(char lineptr[], size_t n, FILE *stream);
void printOutput(TestCase_t testCases[], int entries);
void getTestCases(FILE *fp, TestCase_t testCases[]);
int getPanSize(char *line);
char* getPancakes(char *line);
int flip(TestCase_t *testcase, int start);
void resultToFile(TestCase_t testCases[], int entries, char *output);

int main(void)
{
    FILE *fp;
    int nbrTestCases = 0;

    //char input[] = "input.txt";
    //char input[] = "A-small-practice.in";
    char input[] = "A-large-practice.in";
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
        int start = 0;
        TestCase_t *currentTestCase = &testCases[currentCase];
        printf("#%d \t %s %d\n", currentCase + 1, currentTestCase->pancakes, currentTestCase->panSize);

        while ((start + currentTestCase->panSize - 1) < currentTestCase->numberOfPancakes)
        {
            if (currentTestCase->pancakes[start] == '-')
            {
                flip(currentTestCase, start);
            }
            start++;
        }

        while (start < currentTestCase->numberOfPancakes)
        {
            if (currentTestCase->pancakes[start] == '-')
            {
                currentTestCase->output = -1;
                break;
            }
            start++;
        }

        currentCase++;
        //printf("%d \n\n", currentTestCase->output);
    }

    //printOutput(testCases, nbrTestCases);

    resultToFile(testCases, nbrTestCases, output);

    fclose(fp);

    return 0;
}

void getTestCases(FILE *fp, TestCase_t testCases[])
{
    size_t n = 1005;
    char *line = malloc(1005);
    int i = 0;

    while(getLine(line, n, fp) != -1)
    {

        testCases[i].panSize = getPanSize(line);
        testCases[i].pancakes = getPancakes(line);
        testCases[i].numberOfPancakes = strlen(testCases[i].pancakes);
//
  //      printf("%s, %d, %d \n", testCases[i].pancakes, testCases[i].numberOfPancakes, testCases[i].panSize);
        printf("%d, %d \n", testCases[i].numberOfPancakes, testCases[i].panSize);
        i++;
        line = malloc(1005);
    }
}

int getPanSize(char line[])
{
    int i = 0;
    while(line[i] != ' ')
    {
        i++;
    }

    return atoi(&line[i+1]);
}

/*
 * replaces ' ' with '\0'
 */
char* getPancakes(char *line)
{
    int i = 0;
    while(line[i] != ' ')
    {
        i++;
    }

    line[i] = '\0';

    return line;
}

/*
 * Flip
 */
int flip(TestCase_t *testcase, int start)
{
    if ((start + testcase->panSize - 1) > testcase->numberOfPancakes)
    {
        return -1;
    }

    int i = 0;
    while (i < testcase->panSize)
    {
        if (testcase->pancakes[start + i] == '-')
        {
            testcase->pancakes[start + i] = '+';
        }
        else
        {
            testcase->pancakes[start + i] = '-';
        }
        i++;
    }

    testcase->output++;
    printf("%d \t %s\n",testcase->output, testcase->pancakes);

    return 0;
}

void printOutput(TestCase_t testCases[], int entries)
{
    int i;
    for (i = 0; i < entries; i++)
    {
        if (testCases[i].output == -1)
        {
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
        }
        else
        {
            printf("Case #%d: %d\n", i + 1, testCases[i].output);
        }

    }
}

void resultToFile(TestCase_t testCases[], int entries, char *output)
{
    FILE *fp;
    fp = fopen(output,"ab+"); // read mode

    if( fp == NULL )
    {
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < entries; i++)
    {
        if (testCases[i].output == -1)
        {
            fprintf(fp, "Case #%d: IMPOSSIBLE\n", i + 1);
        }
        else
        {
            fprintf(fp, "Case #%d: %d\n", i + 1, testCases[i].output);
        }

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
