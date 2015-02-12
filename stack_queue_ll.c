/* Linked List as Stack and Queue
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

node_t *new_node, *temp;
node_t *top;			  	// for stack
node_t *front, *rear; 	// for Q

/* function to allocate a new node */
node_t *create_node (int val) {

	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	node->data = val;
	node->next = NULL;
	return node;	
}

void display_stack () {

	temp = top;

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

void pop () {

	temp = top;

	/* check if list is empty */
	if (temp == NULL)	
		printf("Stack is empty\n");
	else {
		top=top->next;
		temp->next=NULL;
		printf("Element %d deleted...\n", temp->data);
		free(temp);
	}
}

void push () {

	int val;
	printf("\nEnter data:");
	scanf("%d", &val);

	/* create a node */	
	new_node = create_node(val);

	new_node->next=top;
	top=new_node;

}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to push an element to stack\n");
	printf("Press 2 to display stack\n");
	printf("Press 3 to pop an element from stack\n");
	printf("Press 4 to add (enqueue) an element to Q\n");
	printf("Press 5 to display Q\n");
	printf("Press 6 to remove (dequeue) an element from Q\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command;
	top = NULL;
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
		case 4:
			enqueue();
			break;
		case 5:
			display_queue();
			break;
		case 6:
			dequeue();
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
