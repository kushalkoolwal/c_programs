#include<stdio.h>
#include "../custom_header/io.h"

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

/* pattern to search */
char search_pattern[] = "test";


/* returns the position/index in the string 's' where the string 'pattern'
   begins or -1 if s doesn’t contain pattern.
 */
int mystrstr (char *s, char *pattern) {


	int i, loc, index;

	/* get the first instance of match */
	i=0;
	while (s[i] != '\0') {
		if (s[i] == pattern[0]) {
			index= loc = i;
			break;
		}	
		i++;
	}

	/* keep looping until we get the *true* first match. 
	   e.g. string = "Mortttttestning"; pattern = "test"
	   we need to keep looping until we get to the 5th 't' in the string	
	 */
	while (s[loc+1] == pattern[0]) {
		loc++;
		index++;
	}

	for (i=0; pattern[i] != '\0' && s[loc] == pattern[i]; i++, loc++)
		;

	if (pattern[i] == '\0')
		return index;
	else
		return -1;
}

int main (void) {

	char line[MAXLEN];
	int found = 0;

	while (mygetline(line, MAXLEN) > 0) {
		if (mystrstr(line, search_pattern) >=0) {
			printf("%s", line);
			found++;
		}
		else {
			printf("Pattern not found!\n");
		}
	}
	return found;
}
