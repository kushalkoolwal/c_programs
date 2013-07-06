#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


void display_menu () {

	printf("\n***Simulate UNIX utilties in C***\n");
	printf("Press 0  to display this menu\n");	
	printf("Press 1  for 'wc' program\n");
	printf("Press 2  to display BST in-order\n");
	printf("Press 3  to search for an element\n");
	printf("Press 4  to delete an element from BST\n");
	printf("Press 5  to delete entire BST\n");
	printf("Press 6  to find height (max depth) of BST\n");
	printf("Press 7  to find size of BST\n");
	printf("Press 8  to mirror a BST\n");
	printf("Press 9  to find min. node in BST\n");
	printf("Press 10 to find max. node in BST\n");
	printf("Press -1 to quit\n");

}


int main (void) {

	int command;
	
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {
	
		case 1:
			display_menu();
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
