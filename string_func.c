#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

void display_menu () {

	printf("\n***String based programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to copy one string to another\n");		
	printf("Press -1 to quit\n");

}


int main (void) {

	int command;
	
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {
	
		case 0:
			display_menu();
			break;
		case 1:
			printf("Enter a string to copy:");
			scanf("%d", &num);			
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	printf("\n");
	printf("\n");
}
