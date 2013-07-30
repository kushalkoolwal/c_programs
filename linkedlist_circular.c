/* Circular  Linked List Program
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

typedef int boolean;

/* node structure */
typedef struct node {
	int data;
	struct node *next; /* next is a pointer to a structure of type node_t */
} node_t;

node_t *head, *new_node, *temp, *temp2, *dup, *node;

/* check if list is empty */
boolean check_empty_list (node_t *temp) {

	if (temp == NULL) {
		printf("List is empty\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void display_list() {

	if (!check_empty_list(head))
		return;

	temp = head;

	do {		
		printf("%d\t",temp->data);
		temp=temp->next;
	} while(temp != head);

}

/* function to allocate a new node */
node_t *create_node (int val) {

	node = (node_t *)malloc(sizeof(node_t));
	if (node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	node->data = val;
	node->next = NULL;
	return node;	
}

void add_to_list(int val) {	

	/* allocate a node */
	new_node = create_node(val);
	
	/* first node in the list */
	if (head == NULL) {	
		head = new_node;
		/* making it circular */
		new_node->next=head;
	}
	/* append node at the end of list */
	else {		
		temp = head;
		/* temp->next locates the last node */
		while(temp->next != head)
			temp=temp->next;
		temp->next=new_node;
		/* making it circular */
		new_node->next=head;		
	}
}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to append elements\n");
	printf("Press 2 to display list\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command, num;
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
			printf("\nEnter data:");
			scanf("%d", &num);
			add_to_list(num);
			break;
		case 2:
			printf("\n");
			display_list();
			printf("\n");
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
