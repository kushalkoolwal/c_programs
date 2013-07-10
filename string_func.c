#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

#define ARRAY_SIZE 15


/* interchange l[x] and l[y] */
void swap(char l[], int x, int y) {

	char temp;
	
	temp = l[x];
	l[x] = l[y];
	l[y]= temp;

}

/* reverse string in place */
void mystrrev (char *s) {

	int i, j;

	i=0;
	j = strlen(s)-1;
	while (i < j) {
		swap(s, i, j);	
		i++;
		j--;	
	}
}

/* string compare function */
int mystrcmp (char *s, char *d) {

	int i=0;
	
	while ((s[i] == d[i])) {
		if (s[i] == '\0')
			return 0;
		i++;
	}
	return s[i] - d[i];
}

/* string length function (non-pointer) */
int mystrlen (char *s) {

	int len=0;

	while(s[len] != '\0') {
		len++;
	}
	return len;
}

/* string copy function (pointer) */
void mystrcpy_v2 (char *d, char *s) {

	while (*s != '\0') {
		*d = *s;
		s++;
		d++;
	}
}

/* string copy function (non-pointer) */
void mystrcpy (char d[], char s[]) {

	int i=0;
	
	while (s[i] != '\0') {
		d[i] = s[i];
		i++;
	}
}

void display_menu () {

	printf("\n***String based programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to copy one string to another\n");
	printf("Press 2  to find string length\n");
	printf("Press 3  to compare strings\n");
	printf("Press 4  to reverse a string\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command;

	char buffer[ARRAY_SIZE];
	char output[ARRAY_SIZE];

	display_menu ();
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {		
		case 0:
			display_menu();
			break;
		case 1:
			printf("Enter a string to copy:");
			/* scanf adds '\0' character automatically */
			scanf("%s", buffer);
			mystrcpy_v2(output, buffer);
			printf("Source: %s, Dest: %s\n", buffer, output);
			break;
		case 2:
			printf("Enter a string to find its length:");
			scanf("%s", buffer);
			printf("String length for %s: %d\n", buffer, mystrlen(buffer));
			break;
		case 3:
			printf("Enter 1st string:");
			scanf("%s", buffer);
			printf("String length for %s: %d\n", buffer, strlen(buffer));
			printf("Enter 2nd string:");
			scanf("%s", output);
			printf("String length for %s: %d\n", output, strlen(output));
			mystrcmp(buffer, output) == 0 ? printf("Strings are equal!\n") : \
			printf("Strings are  not equal by %d!\n", mystrcmp(buffer, output));
			break;
		case 4:
			printf("Enter a string to reverse:");
			scanf("%s", buffer);
			/* fgets adds '\n' at the end of the string automatically
			fgets(buffer, ARRAY_SIZE, stdin);*/
			mystrrev(buffer);
			printf("Reversed string %s\n", buffer);
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	return 0;
}
