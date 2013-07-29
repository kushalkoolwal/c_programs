/* Linear Linked List Program */
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

/* check if list is empty */
boolean check_empty_list (node_t *node) {

	if (node == NULL) {
		printf("List is empty\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

/* function to sort list using bubble sort
   here we are pushing the larger data towards the end unlike the default
   bubble sort implementation where smaller data is pushed (bubbled) towards
   the beginning.	
 */
void sort_list(node_t *head) {

	int tmp_data, done=1;

	if (!check_empty_list(head))
		return;

	node_t *temp;
	/* keep looing until no swap occurs */
	while (done) {
		done = 0;
		temp = head;		
		while (temp->next != NULL) {
			if (temp->data > temp->next->data) {
				/* swap the data */
				tmp_data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tmp_data;
				done = 1;		/* rest the done flag */
			}
			temp = temp->next;
		}
	}
}

void reverse_list(node_t *head) {
	
	if (!check_empty_list(head))
		return;

	node_t *temp, *temp2, *temp3;
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

void remove_duplicates(node_t *head) {

	if (!check_empty_list(head))
		return;

	node_t *temp, *temp2, *dup;

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

void delete_node (node_t *head, int val, boolean only_one_ptr) {

	int found=FALSE;

	node_t *temp, *temp2;

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

void display_list(node_t *head) {

	if (!check_empty_list(head))
		return;

	node_t *temp = head;
	while(temp != NULL) {
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

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

node_t *add_to_list(node_t *head, int val, boolean append) {	

	node_t *new_node, *temp;

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
	return head;
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
	printf("Press 8 to sort the list\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command, num;
	node_t *head = NULL;

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
			head = add_to_list(head, num, TRUE);
			break;
		case 2:
			printf("\nEnter data:");
			scanf("%d", &num);
			head = add_to_list(head, num, FALSE);
			break;
		case 3:
			printf("\n");	
			display_list(head);
			printf("\n");
			break;
		case 4:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			delete_node(head, num, FALSE);
			break;
		case 5:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			delete_node(head, num, TRUE);
			break;
		case 6:
			remove_duplicates(head);
			break;
		case 7:
			reverse_list(head);
			break;
		case 8:
			sort_list(head);
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
