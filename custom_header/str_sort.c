#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

char *lineptr[MAXLINES];    /* pointers to text lines */

void string_copy (char *to, char *from){

	int i=0;	
	while ((to[i] = from[i]) != '\0')
		i++;
}

void swap(char *v[], int i, int j)
{
     char *temp;
     
     temp = v[i];
     v[i] = v[j];
     v[j] = temp;
}

void myqsort(char *v[], int left, int right) {
     
    int i, last;
    
	printf("Inside Q-SORT\n");
    if(left >= right)
       return;
       
    swap(v, left, (left+right)/2);
    last = left;
    
    for(i = left + 1; i <= right; i++)
      if(strcmp(v[i], v[left]) < 0)
         swap(v, ++last, i);
         
    swap(v, left, last);
    myqsort(v, left, last-1);
    myqsort(v, last+1, right);
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* sort input lines */
main()
{
    int nlines;     /* number of input lines read */

	/* Keep reading lines from input until EOF is encountered */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
