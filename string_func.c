#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0
typedef int boolean;
/* if the value is less than or equal to zero
 * then its considered as FALSE and TRUE if greater than 0
 */

/* define exit code */
#define CODE 0

#define ARRAY_SIZE 15

/* function prototypes */
int mystrlen (char *);
void mystrcpy (char *, char *);
void mystrrev (char *);
int mystrcmp (char *, char *);
char *sortstr (char *);

/* interchange l[x] and l[y] */
void swap(char *l, int x, int y) {

	char temp;
	
	temp = l[x];
	l[x] = l[y];
	l[y]= temp;

}

/* print permutations of string of given length 'n'
   there are n! permutations
   start = starting index of string
   end = ending index of string
 */
int permute_string (char s[], int start, int end) {

	int i;
	static int n=0;

	if (start == end) {
		printf("%s\n", s);
		n++;
	}
	else {
		for (i=start; i<=end; i++) {		
			swap(s, start, i);
			permute_string(s, start+1, end);
			swap(s, start, i); /* backtracking */
		}
	}
	return n;
}

/* converts string to integer (atoi) with sign extension */
int myatoiv2 (char s[]) {

	int i=0, n, sign;

	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return (sign*n);
}

/* converts string to integer (atoi) */
int myatoi (char s[]) {

    int i, n;
    n = 0;

	/* s[i] >= '0' && s[i] <= '9' <==> isspace(s[i]) */
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}


/* function to check for anagrams
 * a great way to check sortstr, swap, mystrlen, and mystrcmp functions
 *
*/
boolean check_anagrams (char *s, char *t) {

	sortstr(s);
    sortstr(t);

	if (mystrcmp(s, t) == 0)
		return TRUE;
	else
		return FALSE;
}

boolean check_anagrams_v2 (char *s, char *t) {

	int num1[26]={0}, num2[26]={0};
	int i;

	i=0;
	while (s[i] != '\0') {
		num1[s[i] - 'a']++;
		i++;
	}

	i=0;
	while (t[i] != '\0') {
		num2[t[i] - 'a']++;
		i++;
	}

	for (i=0; i<26; i++) {
		if(num1[i] != num2[i])
			return FALSE;
		//printf("num1[%d]=%d & num2[%d]=%d\n", i, num1[i], i, num2[i]);
	}
	return TRUE;
}

/*  check for palindrome.
 *  a great way to check four string function that we have developed so far:
 *	mystrlen, mystrcpy, mystrrev, swap	
 */
int check_palindrome (char *s) {

	int len;
	char *d;

	len = mystrlen(s);
	//printf("len: %d, sizeof: %d\n", len, sizeof(s));
	/* note we are using len+1 for the null ('\0') character.
       Also we are not using sizeof operator in malloc.
	   Size of char on the host is always 8.
     */
	d=(char *)malloc(len+1);
	mystrcpy (d, s);
	mystrrev (d);
	//printf("len: %d, sizeof: %d\n", mystrlen(reverse), sizeof(reverse));
	if (mystrcmp (d, s) == 0)
		return 1;
	else
		return 0;
}


/* string sort function using bubble sort */
char *sortstr (char *s) {

	int i, j, n;

	n = mystrlen(s);
	//printf("string length = %d\n", n);	
	for (i=0; i<n; i++) {
		printf("i=%d",i);
		for (j=0; j<(n-i-1); j++) {
			printf(" j=%d\n", j);
			if (s[j] > s[j+1])
				swap (s, j, j+1);
		}
	}
	return s;
}

/* check whether 't' is a substring of 's' or not */
boolean mysubstr (char *s, char *t) {

	int i, j, k;

	for (i = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++);
       		if (k > 0 && !t[k])
               	return TRUE;         
	}
    return FALSE;
}

boolean mysubstr_v2 (char *s, char *t) {

	int i=0;

	while (t[i] != '\0') {
		if (t[i] == s[i]) {
			i++;
			continue;
		}
		else
			return FALSE;
	}
	return TRUE;
}


/* concatenate string */
char *mystrcat (char *d, char *s) {

	int i, j;

	/* Two Methods */
	/* Method #1	
	i=0;
	while(s[i] != '\0')
		i++;
	*/

	/* Method #2 */
	i = mystrlen(s);

	j=0;
	while(d[j] != '\0') {
		s[i] = d[j];
		j++;
		i++;
	}
	/* need to append null character to mark end of string; otherwise it will
	   be called array of characters instead of an actual string.
     */
	s[i]='\0';

	/*Question: Why do we need to return the array?*/
	return s;
}

/* reverse string in place */
void mystrrev (char *s) {

	int i, j;

	i=0;
	/* strlen function will return a value of 4 for 'john'
       i.e. it does not take into account for '\0'
       we substract one from strlen because array indexs from 0
	 */
	j = strlen(s)-1;
	//printf("j=%d\n", j);
	while (i < j) {
		swap(s, i, j);
		i++;
		j--;
	}
}

/* string compare function */
int mystrcmp (char *d, char *s) {

	int i=0;
	
	while ((d[i] == s[i])) {
		if (s[i] == '\0')
			return 0;
		i++;
	}
	return (s[i] - d[i]);
}

/* string length function (non-pointer version) */
int mystrlen (char *s) {

	int len=0;

	while(s[len] != '\0') {
		len++;
	}
	return len;
}

/* string copy function (pointer version) */
void mystrcpy_v2 (char *d, char *s) {

	while (*s != '\0') {
		*d = *s;
		s++;
		d++;
	}
}

/* string copy function (non-pointer version)-Method 1*/
void mystrcpy (char *d, char *s) {

	int i=0;
	
	while (s[i] != '\0') {
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

/* string copy function (non-pointer version)-Method 2
 * another way to pass character arrays
 */
/*void mystrcpy (char d[], char s[]) {

	int i=0;
	
	while (s[i] != '\0') {
		d[i] = s[i];
		i++;
	}
}*/

/* Ways to pass arrays to functions:
 * http://www.tutorialspoint.com/cprogramming/c_passing_arrays_to_functions.htm
*/

void display_menu () {

	printf("\n***String based programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to find string length\n");
	printf("Press 2  to copy one string to another\n");
	printf("Press 3  to compare strings\n");
	printf("Press 4  to reverse a string\n");
	printf("Press 5  to concatenate strings\n");
	printf("Press 6  to check for substring\n");
	printf("Press 7  to sort a string\n");
	printf("Press 8  to check for plaindrome strings\n");
	printf("Press 9  to check for anagrams\n");
	printf("Press 10 for atoi function\n");
	printf("Press 11 for permutations of strings\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command, len;

	char buffer[ARRAY_SIZE];
	char buffer1[ARRAY_SIZE];

	display_menu ();
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {		
		case 0:
			display_menu();
			break;
		case 1:
			printf("Enter a string to find its length:");
			scanf("%s", buffer);
			printf("String length for %s: %d\n", buffer, mystrlen(buffer));
			break;
		case 2:
			printf("Enter a string to copy:");
			/* scanf adds '\0' character automatically */
			scanf("%s", buffer);
			/* non-pointer version */
			mystrcpy(buffer1, buffer); 
			/* pointer version */			
			//mystrcpy_v2(buffer1, buffer); 
			printf("Source: %s, Dest: %s\n", buffer, buffer1);
			break;
		case 3:
			printf("Enter 1st string:");
			scanf("%s", buffer);
			/*printf("String length for %s: %d\n", buffer, strlen(buffer));*/
			printf("Enter 2nd string:");
			scanf("%s", buffer1);
			/*printf("String length for %s: %d\n", output, strlen(output));*/
			mystrcmp(buffer1, buffer) == 0 ? printf("Strings are equal!\n") : \
			printf("Strings are  not equal by %d!\n", mystrcmp(buffer1, buffer));
			break;
		case 4:
			printf("Enter a string to reverse:");
			scanf("%s", buffer);
			/* fgets adds '\n' at the end of the string automatically
			fgets(buffer, ARRAY_SIZE, stdin);*/
			mystrrev(buffer);
			printf("Reversed string %s\n", buffer);
			break;
		case 5:
			printf("Enter 1st string:");
			scanf("%s", buffer);
			/*printf("String length for %s: %d\n", buffer, strlen(buffer));*/
			printf("Enter 2nd string:");
			scanf("%s", buffer1);
			printf("Concatenate string:%s\n", mystrcat(buffer1, buffer));
			break;
		case 6:
			printf("Enter base string:");
			scanf("%s", buffer);
			printf("Enter substring:");
			scanf("%s", buffer1);
			//printf("Function return value is %d\n", mystrstr (buffer, buffer1));
			//if (mysubstr (buffer, buffer1))
			if (mysubstr_v2 (buffer, buffer1))
				printf("Is a substring\n");
			else
				printf("Not a substring\n");
			break;		
		case 7:
			printf("Enter a string (all small) to sort:");
			scanf("%s", buffer);			
			printf("Sorted string: %s\n", sortstr(buffer));
			break;
		case 8:
			printf("Enter a string to check for Palindrome:");
			scanf("%s", buffer);
			if (check_palindrome(buffer))
				printf("String is Palindrome\n");
			else
				printf("String is not Palindrome\n");			
			break;
		case 9:
			printf("Enter 1st string:");
			scanf("%s", buffer);
			printf("Enter 2nd string:");
			scanf("%s", buffer1);
			//if (check_anagrams (buffer, buffer1))
			if (check_anagrams_v2 (buffer, buffer1))
				printf("Strings are anagrams\n");
			else
				printf("Strings are not anagrams\n");
			break;
		case 10:
			printf("Enter a string of digits:");
			scanf("%s", buffer);
			/*fgets(buffer, ARRAY_SIZE, stdin);*/
			printf("String->Interger: %d\n", myatoiv2(buffer));
			break;
		case 11:
			printf("Enter a string:");
			scanf("%s", buffer);
			/*fgets(buffer, ARRAY_SIZE, stdin);*/
			len=(strlen(buffer)-1);
			printf("Total number of permutation printed: %d\n", permute_string(buffer, 0, len));
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	return 0;
}
