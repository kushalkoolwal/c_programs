/* Linear Linked List Program
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

node_t *head, *new_node, *temp, *temp2, *temp3, *dup, *node;

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

void reverse_list() {
	
	if (!check_empty_list(head))
		return;

	temp = head;
	temp2 = temp->next;
	temp3 = temp2->next;
	temp->next = NULL;
	
	do {
		temp2->next = temp;
		temp = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	} while (temp3 != NULL);

	temp2->next=temp;
	head = temp2;
}

void remove_duplicates() {

	if (!check_empty_list(head))
		return;

	temp = head;
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

void delete_node (int val, boolean only_one_ptr) {

	int found=FALSE;

	temp = head;	
	/*keep tranversing until number is found */
	while (found==FALSE && temp!=NULL) {
		if (temp->data == val)
			found=TRUE;			
		else
			temp=temp->next;		
	}
		
	if (found) {
		/* if node is head node itself */		
		if (temp == head) {			
			/* perform deletion */
			head=head->next;
			temp->next=NULL;
			free(temp);
		}
		else if (!only_one_ptr) {
			/* node can be anywhere including the end of list */
			temp2 = head;

			while(temp2->next != temp)
				temp2=temp2->next;

			/* perform deletion */
			temp2->next=temp->next;
			temp->next=NULL;
			free(temp);		
		}
		/* delete node with only one pointer, cannot use for last node */
		else {
			temp->data = temp->next->data;
			temp->next = temp->next->next;			
		}
	}
	else {
	 printf("Not not found\n");
	}
}

void display_list() {

	if (!check_empty_list(head))
		return;

	temp = head;		
	while(temp != NULL) {
		printf("%d\t",temp->data);
		temp=temp->next;
	}
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

void add_to_list(int val, boolean append) {	

	/* allocate a node */
	new_node = create_node(val);
	
	/* first node in the list */
	if (head == NULL) {	
		head = new_node;
	}
	/* append node at the end of list */
	else if(append) {		
		temp = head;
		/* temp->next locates the last node */
		while(temp->next != NULL)
			temp=temp->next;
		temp->next=new_node;
	}
	/* prepend node at the beginning of list */
	else {
		new_node->next=head;
		head=new_node;
	}
}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");	
	printf("Press 1 to append elements\n");
	printf("Press 2 to prepend elements\n");
	printf("Press 3 to display list\n");
	printf("Press 4 to delete node\n");
	printf("Press 5 to delete node (only one ptr)\n");
	printf("Press 6 to remove duplicate nodes\n");
	printf("Press 7 to reverse the list\n");
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
			add_to_list(num, TRUE);
			break;
		case 2:
			printf("\nEnter data:");
			scanf("%d", &num);
			add_to_list(num, FALSE);
			break;
		case 3:
			printf("\n");	
			display_list();
			printf("\n");
			break;
		case 4:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			delete_node(num, FALSE);
			break;
		case 5:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			delete_node(num, TRUE);
			break;
		case 6:
			remove_duplicates();
			break;
		case 7:
			reverse_list();
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
