/*	UNIX word count (wc) program
	Word is defined here as sequence of characters not containing a
    blank, tab or newline.
	Running program:
	./a.out
	./a.out < text.txt	
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define IN 			1	/* inside the word */
#define OUT			0	/* outside the word */
#define NO_DIGITS	10  /* no. of digits in characters set (0...9) */

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

	int c, word_status, i;
	long nl,nc,nw;

	int nwhite, nother, ndigits[NO_DIGITS]={0}, digitcount, tdigitcount;
	
	/* assignments associate from right to left*/
	nl=nc=nw=0;
	word_status=OUT;

	nwhite=nother=0;
	digitcount=tdigitcount=0;

	/* keep reading until EOF is encountered */
	while ((c = getchar()) != EOF) {
		nc++; 						  /* count character immediately */

		if (c == '\n')
			nl++; 					  /* count lines as soon we encounter '\n'*/

		/* Expressions connected by && or ¦¦ are evaluated left to right, and is
		 * is guaranteed that evaluation will stop as soon as the truth or
		 * falsehood is known.
		 */
		if (c == ' ' || c == '\n' || c == 't')
			word_status=OUT;			
		else if (word_status == OUT) {
			word_status=IN;
			nw++;					 /*count no. of words */
		}

		if (c >= '0' && c <= '9') {	  /* check if char is a digit */
			++tdigitcount;

			/*digitcount=0;
			digitcount=ndigits[c-'0'];			
			ndigits[c-'0'] = ++digitcount;*/

			/* first increment the value stored in ndigits[i] and then store
			   the value back to ndigits[i]. The abvove three lines are replaced
			   with the next line.
			 */
			++ndigits[c - '0'];
			
		}
		else if (c == ' ' || c == '\n' || c == 't')	/* check if whitespace */
			++nwhite;
		else							/* else other type */		
			++nother;
	}

	printf("No. of characters:%ld\n", nc);
	printf("No. of lines:%ld\n", nl);
	printf("No. of words:%ld\n", nw);
	printf("Total digits:%d\n", tdigitcount);
	printf("Digits = ");
	for (i = 0; i < NO_DIGITS; i++)
		printf(" %d", ndigits[i]);
	printf(", White space = %d, Others = %d\n", nwhite, nother);
	return 0;
}
