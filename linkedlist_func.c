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

enum type_of_ll {LINEAR=0, CIRCULAR=1};
enum insert_loc {PREPEND=0, APPEND=1};

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

int list_length (node_t *head) {

	int len=0;

	node_t *current;
	current = head;

	while (current != NULL){
		len++;
		current = current->next;
	}
	return len;
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
	/* keep looping until no swap occurs */
	while (done) {
		done = 0;
		temp = head;		
		while (temp->next != NULL) {
			if (temp->data > temp->next->data) {
				/* swap the data */
				tmp_data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tmp_data;
				done = 1;		/* reset the done flag */
			}
			temp = temp->next;
		}
	}
}

//http://www.dailyfreecode.com/code/sort-linked-list-swapping-data-2818.aspx
void sort_list_v2 (node_t *head) {

	int i,j,n,tmp_data;

	if (!check_empty_list(head))
		return;

	n = list_length(head);
	printf("Length of list=%d\n", n);
	
	node_t *p, *q;
	/* bubble sort */
	for (i=0; i < n; i++){
		p = head;
		q = p->next;
		for (j=0; j < (n-i-1); j++) {
			if (p->data > q->data) {
				tmp_data = p->data;
				p->data = q->data;
				q->data = tmp_data;	
			}
			q=q->next;
			p=p->next;
		}
	}
}

node_t *reverse_list(node_t *head) {
	
	if (!check_empty_list(head))
		return NULL;

	node_t *current;
	node_t *prev = NULL;
	
	while (head != NULL) {
		current = head->next;
		head->next = prev;
		prev = head;
		head = current;
	}
	return prev;	/*otherwise we will lose the head */
}

void remove_duplicates(node_t *head) {

	if (!check_empty_list(head))
		return;

	node_t *p, *q, *temp;

	p = head;
	while (p != NULL && p->next != NULL) {
		q = p;
		while (q->next != NULL) {
			if (p->data == q->next->data) {
				temp = q->next;
				q->next=q->next->next;
				temp->next = NULL;
				free (temp);
			}
			else {
				q=q->next; /* pay attention, we only increment if matched */
			}
		}
		p=p->next;
	}
}

/* returns node's data from last based on the position specified */
int data_by_node_pos (node_t *head, int pos) {

	int i;

	if (!check_empty_list(head))
		return -1;

	node_t *current, *follow;
	current = head;
	follow = head;

	for (i=0; i < pos; i++)
		if (current->next != NULL)
			current=current->next;
	
	while (current != NULL ) {
		current = current->next;
		follow = follow->next;
	}
	return follow->data;
}

void delete_last_node (node_t *head) {

	/* set up two pointers, prev is one step behind current */
	node_t *current, *prev;
	current = head;
	prev = NULL;
	
	/* loop will exit when current is pointing to last node */
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	prev->next = NULL;	
	free(current);
} 

/* See:http://tinyurl.com/lz4you6 for approaches to modify head pointer */
node_t *delete_node (node_t *head, int val, boolean only_one_ptr) {

	if (!check_empty_list(head))
		return NULL;

	/* set up two pointers, prev is one step behind current */
	node_t *current, *prev;
	current = head;
	prev = NULL;
	
	while (current != NULL) {	
		if (current->data == val) {
			/* if node is head node itself */		
			if (current == head) {
				head = current->next;
				current->next = NULL;
				free(current);
			}
			/* node can be anywhere */
			else if (!only_one_ptr) {
				prev->next = current->next;
				current->next = NULL;
				free(current);
			}
			/* single pointer version */
			else {
				node_t *temp = current->next;
				current->data = temp->data;
				current->next = temp->next;				
				free(temp);				
			}
		}
		prev=current;
		current=current->next;
	}
	return head; 	/*otherwise we will lose the head */
}

/* returns '1' if circular else returns '0' */
boolean check_circular (node_t *head) {

	node_t *slow, *fast;
	slow = head;
	fast = head->next;

	while (slow != NULL && fast != NULL) {

		/* loop is detected */
		if (slow == fast)
			return TRUE;
		slow=slow->next;
		
		if (fast->next != NULL)
			fast=fast->next->next;
		else
			fast=fast->next;
	}
	return FALSE;
}

boolean check_circular_v2 (node_t *head) {

	node_t *current;
	current = head;

	while (current != NULL) {
		if (current->next == head)
			return TRUE;
		current=current->next;
	}
	return FALSE;
}

void display_list(node_t *head, enum type_of_ll type) {

	if (!check_empty_list(head))
		return;

	node_t *current = head;

	if (type == LINEAR) {
		while(current != NULL) {
			/* current != NULL will traverse the whole list */
			printf("%d--->",current->data);
			current=current->next;
		}
		printf("NULL\n");
	}

	if (type == CIRCULAR) {
		do {		
			printf("%d--->",current->data);
			current=current->next;
		} while(current != head);
		printf("%d", head->data);
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

node_t *add_to_list (node_t *head, int val, enum insert_loc loc, enum type_of_ll type) {

	node_t *new_node, *temp;

	/* allocate a node */
	new_node = create_node(val);
	
	/* first node in the list */
	if (head == NULL) {	
		head = new_node;
	}
	/* append node at the end of list */
	else if(loc == APPEND) {
		temp = head;
		/* go to the last node i.e. temp->next != NULL locates the last node */
		if (type == LINEAR) {
			while(temp->next != NULL)
				temp=temp->next;
		}
		else if (type == CIRCULAR) {
			while(temp->next != head)
				temp=temp->next;
		}
		temp->next=new_node;
	}
	/* prepend node at the beginning of list */
	else {
		new_node->next=head;
		head=new_node;
	}

	if (type == CIRCULAR)
		new_node->next=head;

	return head;
}

void push(node_t **head, int val) {

	node_t *new_node;

	/* allocate a node */
	new_node = create_node(val);

	new_node->next = *head;
	*head = new_node;

}

/* adds two list and creates a new list */
node_t *add_two_lists (node_t *first, node_t *second, node_t *result) {

	int carry=0, total;
	node_t *new_node, *temp;

	new_node=temp=NULL;

	while (first != NULL || second != NULL) {

		/* add data of first node with data of second node and then add carry */	
		total = carry + (first ? first->data : 0) + (second ? second->data: 0);
		
		/* if carry, store 1 else store 0
		   e.g. first->data=8 and second->data=5
           8+5 > 10, therefore 1=carry and 3=sum
         */
		carry = total >= 10 ? 1 : 0;
		
		/* update the total
		   based on above example, we need just '3' in our total and not 13
           because we will carry the '1' in 13 to our next calculation
		   13 % 10 = 3	 	
         */
		total = total % 10;
		
		/* create a new node for the resulting value (3) */
		new_node = create_node(total);

		/* first node in the list */
		if (result == NULL)
			result = new_node;
		else
			temp->next=new_node;

		/* move pointer to the newly created node for the next update */
		temp = new_node;

		/* increment to next node of the two lists */
		if (first != NULL)
			first=first->next;

		if (second != NULL)
			second=second->next;			
	}

	/* we need to take care of the last carry and create a new node for it */
	if (carry>0)
		new_node->next=create_node(carry);

	return result;	
}

/* Good sample reference program:
 * http://www.dailyfreecode.com/code/sort-linked-list-swapping-data-2818.aspx
 */

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0 to display this menu\n");
	printf("Press 1 to append elements\n");
	printf("Press 2 to prepend elements\n");
	printf("Press 3 to display list\n");
	printf("Press 4 to count no. of nodes\n");
	printf("Press 5 to delete node\n");
	printf("Press 6 to delete node (only one ptr)\n");
	printf("Press 7 to delete last node\n");
	printf("Press 8 to retrieve data by position\n");
	printf("Press 9 to remove duplicate nodes\n");
	printf("Press 10 to reverse the list\n");
	printf("Press 11 to sort the list\n");
	printf("Press 12 to add two lists\n");
	printf("Press 13 to create circular linked list\n");
	printf("Press 14 to display circular linked list\n");
	printf("Press 15 to detect if list is circular or not\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command, num;
	node_t *head = NULL;

	node_t *first, *second, *result;
	first=second=result=NULL;

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
			head = add_to_list(head, num, APPEND, LINEAR);
			break;
		case 2:
			printf("\nEnter data:");
			scanf("%d", &num);
			head = add_to_list(head, num, PREPEND, LINEAR);
			break;
		case 3:
			printf("\n");	
			display_list(head, LINEAR);
			printf("\n");
			break;
		case 4:
			printf("\n");	
			printf("The number of nodes is %d", list_length(head));
			printf("\n");
			break;		
		case 5:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			head = delete_node(head, num, FALSE);
			break;
		case 6:
			printf("Enter data to be deleted:");
			scanf("%d", &num);
			head =  delete_node(head, num, TRUE);
			break;
		case 7:
			delete_last_node(head);
			break;
		case 8:
			printf("Enter node number from last to retrieve data from:");
			scanf("%d", &num);
			printf("Data=%d\n", data_by_node_pos(head, num));
			break;
		case 9:
			remove_duplicates(head);
			break;
		case 10:
			head=reverse_list(head);
			break;
		case 11:
			//sort_list(head);
			sort_list_v2(head);
			break;
		case 12:
			/* create list 5->6->3 = 365*/
			push(&first, 3);
			push(&first, 6);
			push(&first, 5);
			display_list(first, LINEAR);
			/* create list 8->4->2 = 248*/
			push(&second, 2);
			push(&second, 4);
			push(&second, 8);
			display_list(second, LINEAR);
			result=add_two_lists(first, second, result);
			printf("Resultant List is:");
			display_list(result, LINEAR);
			break;	
		case 13:
			printf("\nEnter data:");
			scanf("%d", &num);			
			head = add_to_list(head, num, APPEND, CIRCULAR);
			break;
		case 14:
			printf("\n");	
			display_list(head, CIRCULAR);
			printf("\n");
			break;
		case 15:
			//if (check_circular(head))
			if (check_circular_v2(head))
				printf("List is Circular\n");
			else
				printf("List is not Circular\n");
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
