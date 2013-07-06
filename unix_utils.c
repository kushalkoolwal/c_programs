#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*  copies input to output */
/*  EOF is defined as -1 on this platform.
	'int' instead of 'char' is used to detect end of input.
    'char' can't be used because 'c' should be big enough to hold EOF
    in addition to any possible char values and hence 'int' is used.
	Note that input is buffered so you have to hit ENTER key for getchar to
	fetch characters from the buffer.	
	Pressing ENTER key == '\n'
	Pressing Ctrl+D == EOF
 */
void copy () {

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
}

void display_menu () {

	printf("\n***Simulate UNIX utilities in C***\n");
	printf("Press 0  to display this menu\n");	
	printf("Press 1  for 'echo' program\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command;

	display_menu ();
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {	
		case 0:
			display_menu ();
			break;
		case 1:
			copy ();
			display_menu ();
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
