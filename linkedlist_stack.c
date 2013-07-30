/*
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

/* node structure */
typedef struct node {
	int data;
	struct node *next; /* next is a pointer to a structure of type node_t */
} node_t;

node_t *head, *new_node, *temp;

void pop () {

	temp = head;

	/* check if list is empty */
	if (temp == NULL)	
		printf("Queue is empty\n");
	else {
		head=head->next;
		temp->next=NULL;
		printf("Element %d deleted...\n", temp->data);
		free(temp);
	}
}

void display_stack () {

	temp = head;

	/* check if list is empty */
	if (temp == NULL)		
		printf("Stack is empty\n");
	else {
		printf("\n");
		while(temp != NULL) {
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void push () {

	/* create a node */	
	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	printf("\nEnter data:");
	scanf("%d", &new_node->data);
	new_node->next=head;
	head=new_node;

}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to push an element to stack\n");
	printf("Press 2 to display stack\n");
	printf("Press 3 to delete an element from stack\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command;
	head = NULL;
	display_menu();

	while(TRUE) {
		printf("Enter a command from above menu:");
		scanf("%d", &command);

		switch (command) {

		case 0:
			display_menu();
			break;
		case 1:
			push();
			break;
		case 2:
			display_stack();
			break;
		case 3:
			pop();
			break;
		case -1:
			return 0;

		default:		
			printf("Please enter a valid choice\n");
			display_menu();
			break;
		}
	}
	return 0;
}
