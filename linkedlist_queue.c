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

node_t *front, *new_node, *rear, *temp;

void dequeue () {

	temp = front;

	/* check if list is empty */
	if (temp == NULL)	
		printf("Queue is empty\n");
	else {
		front=front->next;
		temp->next=NULL;
		printf("Element %d deleted...\n", temp->data);
		free(temp);
	}
}

void display_queue () {

	temp = front;

	/* check if list is empty */
	if (temp == NULL)		
		printf("Queue is empty\n");
	else {
		printf("\n");
		while(temp != NULL) {
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void enqueue() {

	/* create a node */	
	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	printf("\nEnter data:");
	scanf("%d", &new_node->data);
	new_node->next = NULL;

	if (front == NULL) {
		/* first element in the queue */
		front = new_node;
		rear = new_node;
	}
	else {
		/* append node at the end of list */
		rear->next=new_node;
		rear=rear->next;
	}
}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to add (enqueue) an element to Q\n");
	printf("Press 2 to display Q\n");
	printf("Press 3 to delete (dequeue) an element from Q\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command;
	front = NULL;
	rear = NULL;
	display_menu();

	while(TRUE) {
		printf("Enter a command from above menu:");
		scanf("%d", &command);

		switch (command) {

		case 0:
			display_menu();
			break;
		case 1:
			add_queue();
			break;
		case 2:
			display_queue();
			break;
		case 3:
			delete_queue();
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
