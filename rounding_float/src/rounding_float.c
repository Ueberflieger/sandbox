#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <fenv.h>

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int findxy(char *c) {
    const char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int i, j;
    char bufw[4];
    char bufd[3];

    /* check if c is at least 5 chars long */
    if (strlen(c) < 5)
        return -1;

    for (i = 0; i <= (int)strlen(c)-5; i++) {
        memcpy(bufw, c+i, 3);
        bufw[3]='\0';
        /* check all 7 weekdays */
        for (j = 0; j < 7; j++) {
            /* find weekday matches */
            if (!strcmp(bufw, days[j])) {
                /* check if both chars following weekday are numerical */
                if (isdigit(c[i+3]) && isdigit(c[i+4])) {
                    memcpy(bufd, c+i+3, 2);
                    bufd[2]='\0';
                    /* check if number after weekday is a valid day */
                    if (atoi(bufd) >= 1 && atoi(bufd) <= 31) {
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    printf("%d", strlen("ö"));

    return 0;
}
