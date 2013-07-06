/* UNIX word count (wc) program */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*  EOF is defined as -1 on this platform.
	'int' instead of 'char' is used to detect end of input (EOF in this case).
    'char' can't be used because 'c' should be big enough to hold EOF (-1)
    in addition to any possible char values and hence 'int' is used.
	Note that input is buffered on "normal" linux terminal so you have to hit
	ENTER ('\n') key for getchar to fetch characters from the buffer.
	Pressing ENTER key == '\n'.
	Pressing Ctrl+D == EOF.
 */

int main (void) {

	int c;
	long nl,nc;
	
	nl=nc=0;

	while ((c=getchar()) != EOF) {
		if (c == '\n')
			nl++;
		nc++;
	}
	printf("No. of characters:%ld\n", nc);
	printf("No. of lines:%ld\n", nl);

	return 0;
}
