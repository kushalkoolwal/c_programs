#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* copies input to output */
void copy () {

	int c;

	c=getchar();
	while (c!=EOF) {	
		putchar(c);
		c=getchar();
	}
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
