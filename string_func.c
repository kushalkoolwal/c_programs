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
			scanf("%s", buffer);
			mystrcpy_v2(output, buffer);
			printf("Source: %s, Dest: %s\n", buffer, output);
			break;
		case 2:
			printf("Enter a string to find its length:");
			scanf("%s", buffer);
			mystrlen(buffer);
			printf("String length for %s: %d\n", buffer, mystrlen(buffer));
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	printf("\n");
	printf("\n");
	return 0;
}
