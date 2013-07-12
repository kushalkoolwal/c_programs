#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    
	/*printf("Inside readline\n");*/
    nlines = 0;
	/* Keep reading characters until ENTER is pressed */
    while((len = mygetline(line, MAXLEN)) > 0) {
       if(nlines >= maxlines || (p = malloc(len)) == NULL)
          return -1;
       else {
            //line[len-1] = '\0'; /* delete newline */
            string_copy(p, line);
            lineptr[nlines++] = p;
       }
	}
    return nlines;
}


int mygetline (char *l, int lim) {

	int c,i;
	
	/* keep reading until newline within max line and not end-of-file */
	for (i=0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
		l[i] = c;
	if (c == '\n')
		l[i++]=c;
	l[i] = '\0';
	return i;
}
