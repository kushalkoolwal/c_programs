#include<stdio.h>
#include "../custom_header/io.h"

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

/* pattern to search */
char search_pattern[] = "test";


int strindex (char s[], char pattern[]) {

	return 0;

}

int main (void) {

	char line[MAXLEN];
	int found = 0;

	while (mygetline(line, MAXLEN) > 0)
		if (strindex(line, search_pattern) >=0) {
			printf("%s", line);
			found++;
		}

	return found;
}
