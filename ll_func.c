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

node_t *head, *new_node, *temp, *temp2, *dup;

void remove_duplicates() {

	temp = head;

	if (temp == NULL) {
		printf("List is empty\n");
		return;
	}

	while (temp != NULL) {
		temp2 = temp;
		while (temp2 != NULL && temp2->next != NULL) {
			if (temp->data == temp2->next->data) {
				dup = temp2->next;
				temp2->next=temp2->next->next;
				free (dup);
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
}

void delete_node () {

	int num, found=FALSE;
	temp = head;

	/* check if list is empty */
	if (temp == NULL)	
		printf("List is empty\n");
	else {	
		printf("Enter the node to be deleted:");
		scanf("%d", &num);

		/*keep tranversing until number is found */
		while ((found==FALSE) && (temp!=NULL)) {
			if (temp->data == num)
				found=TRUE;
			else
				temp=temp->next;		
		}
		
		if (found) {			
			if (temp == head) {
				/* if node is head node itself */		
				head=head->next;
				temp->next=NULL;
				free(temp);
			}
			else {
				/* node can be anywhere including the end of list */
				temp2 = head;
				while(temp2->next != temp)
					temp2=temp2->next;
				temp2->next=temp->next;
				temp->next=NULL;
				free(temp);		
			}
		}
		else
			printf("\nNot not found");	
	}	
}

void display_list() {

	temp = head;

	/* check if list is empty */
	if (temp == NULL)		
		printf("List is empty\n");
	else {
		printf("\n");
		while(temp != NULL) {
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void create_list() {

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	printf("\nEnter data:");
	scanf("%d", &new_node->data);
	new_node->next = NULL;

	if (head == NULL)
		/* first node in the list */
		head = new_node;
	else {
		/* append node at the end of list */
		temp = head;
		/* temp->next locates the last node */
		while(temp->next != NULL)
			temp=temp->next;
		temp->next=new_node;
	}
}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to create list\n");
	printf("Press 2 to display list\n");
	printf("Press 3 to delete node\n");
	printf("Press 4 to remove duplicate nodes\n");
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
			create_list();
			break;
		case 2:
			display_list();
			break;
		case 3:
			delete_node();
			break;
		case 4:
			remove_duplicates();
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
