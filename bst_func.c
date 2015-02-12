/* Binary Search Tree Operations */
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
	struct node *left;  
	struct node *right;
} node_t;

node_t *root, *new_node, *current, *parent, *temp;

/* function to allocate a new node */
node_t *createNode (int val) {

	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	node->left = NULL;
	node->right = NULL;
	node->data = val;
	return node;	
}


node_t *createBSTFromSortedArray (int array[], int start, int end) {

	if (start > end)
		return NULL;

	int mid = (start + end) / 2;

	node_t *root = createNode(array[mid]);
	printf("DEBUG: creating node %d\n", array[mid]);
	root->left = createBSTFromSortedArray(array, start, mid-1);
	root->right = createBSTFromSortedArray(array, mid+1, end);
	return root;
}

node_t * find_min_bst(node_t *current) {

	if (current == NULL) {	
		printf("Tree does not exists\n");
		return NULL;
	}
	else {
		if(current->left)
			return find_min_bst((current->left));
		else
			return current;
	}
}

node_t * find_max_bst(node_t *current) {

	if (current == NULL) {	
		printf("Tree does not exists\n");
		return NULL;
	}
	else {
		if(current->right)
			return find_max_bst((current->right));
		else
			return current;
	}
}

node_t *search_bst (node_t *current, int key) {

	/* check if list is empty */
	if (current == NULL) {	
		printf("Tree does not exists\n");
		return NULL;
	}
	else {	
		while ((current!=NULL)) {
			if (current->data == key) {
				return current;
			}
			if (current->data > key)
				current=current->left;
			if (current->data < key)
				current=current->right;
		}
	}	
}


void mirror_bst(node_t *current) {

	if (current==NULL)
		return;
	else {	
		mirror_bst(current->left);
		mirror_bst(current->right);

		/*swap the operation */
		temp = current->left;
		current->left=current->right;
		current->right=temp;
	}
}

/* Count the number of nodes in the tree.*/
int size_bst(node_t *current) {

	if (current == NULL)
		return 0;
	else
		return(size_bst(current->left) + 1 + size_bst(current->right));	
}

/*  the number of nodes along the longest path from the root node down to the farthest leaf node.*/
int max_depth_bst(node_t *current) {

	int ldepth, rdepth;

	if (current == NULL)
    	return 0;
   	else {
		/* compute the depth of each subtree */
       	int ldepth = max_depth_bst(current->left);
       	int rdepth = max_depth_bst(current->right);
 
       	/* use the max. of left-subtree & right-subtree */
       	if (ldepth > rdepth)
        	return(ldepth+1);
       	else
			return(rdepth+1);
   	}
}

void delete_bst(node_t *current) {

	if (current != NULL) {
		delete_bst(current->left);
		delete_bst(current->right);		
		free(current);
	}
}

node_t *delete_node(node_t *current, int key) {

	enum position {LEFT=1, RIGHT=2, ROOT=3};
	enum position pos;
	int found=FALSE;

	if (current == NULL)
		printf("Tree does not exists\n");
	else if (key < current->data)
		current->left=delete_node(current->left, key);
	else if (key > current->data)
		current->right=delete_node(current->right, key);
	else {
		if (current->left && current->right) {
		 /* a) find a minimum value in the right subtree;
			b) replace value of the node to be removed with found minimum. Now, 			   right subtree contains a duplicate!
			c) apply remove to the right subtree to remove a duplicate.
		  */
			temp=find_min_bst(current->right);
			current->data = temp->data;
			current->right = delete_node(current->right, temp->data);	
		}
		/* 	If there is only one or zero children;
			remove it and connect its parent to its child
		 */
		else {
			temp = current;
			if(current->left == NULL)
				current = current->right;
			else if(current->right ==NULL)
				current = current->left;
			free(temp);
		}
	}
	return current;
}

void print_given_level(node_t *root, int level) {

	if (root == NULL) {
		return;
	}
	else if (level == 1) {
		printf("%d\t", root->data);
	}
	else if (level > 1) {
		print_given_level(root->left, level -1);
		print_given_level(root->right, level -1);
	}
}

void bfs_traversal (node_t *root) {

	int height, i;

	height = max_depth_bst (root);

	for (i=1; i<=height; i++)
		print_given_level(root, i);
}

void postorder (node_t *current) {
	
	if (current != NULL) {
		postorder(current->left);
		postorder(current->right);
		printf("%d\t", current->data);
	}
}

void preorder (node_t *current) {
	
	if (current != NULL) {
		printf("%d\t", current->data);		
		preorder(current->left);
		preorder(current->right);
	}
}

void inorder (node_t *current) {
	
	if (current != NULL) {
		inorder(current->left);
		printf("%d\t", current->data);
		inorder(current->right);
	}
}

/*
 *http://www.c4learn.com/c-programs/c-program-to-implement-binary-search-tree-traversal.html
 */
void display_bst () {
	
	int t;

	printf("Enter 1 (inorder), 2 (preorder, 3 (postorder))\n");
	scanf("%d", &t);

	/* check if list is empty */
	if (root == NULL)
		printf("Tree does not exists\n");
	else {	
		if (t == 1)
			inorder(root);
		if (t == 2)
			preorder(root);
		if (t == 3)
			postorder(root);			
	}
	printf("\n\n");
}

void insert (node_t *root, node_t *new_node) {
	
	/* check if new node's data > root node */
	if((root->right==NULL) && (new_node->data > root->data))
		root->right=new_node;
	else {
		if ((root->right != NULL) && (new_node->data > root->data))
			insert (root->right, new_node);
	}

	/* check if new node's data < root node */
	if((root->left==NULL) && (new_node->data < root->data))
		root->left=new_node;
	else {
		if ((root->left != NULL) && (new_node->data < root->data))
			insert (root->left, new_node);
	}
}

void create_bst () {

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		printf("Error creating a new node.\n");
		exit (CODE);
	}
	printf("\nEnter data:");
	scanf("%d", &new_node->data);
	new_node->left=NULL;
	new_node->right=NULL;

	/* check if tree is empty */
	if (root == NULL)
		root = new_node;
	else
		insert(root, new_node);
}

void display_menu () {

	printf("Linked List Implementation\n");
	printf("Press 0  to display this menu\n");	
	printf("Press 1  to create BST\n");
	printf("Press 2  to traverse the tree\n");
	printf("Press 3  to search for an element\n");
	printf("Press 4  to delete an element from BST\n");
	printf("Press 5  to BFS traversal\n");		
	printf("Press 6  to find height (max depth) of BST\n");
	printf("Press 7  to find size of BST\n");
	printf("Press 8  to mirror a BST\n");
	printf("Press 9  to find min. node in BST\n");
	printf("Press 10 to find max. node in BST\n");
	printf("Press 11  to delete entire BST\n");
	printf("Press 12  to create BST from sorted array\n");
	printf("Press -1 to quit\n");

}

int main (void) {

	int command, node_val;
	int array[]={0,1,2,3,4,5,6,7,8,9};
	int n = sizeof(array)/sizeof(array[0]);


	root = NULL;
	display_menu();

	while(TRUE) {
		printf("Enter a command from above menu:");
		scanf("%d", &command);

		switch (command) {

		case 0:
			display_menu();
			break;
		case 1:
			create_bst();
			break;
		case 2:
			display_bst();
			break;
		case 3:
			printf("Enter the node to be searched:");
			scanf("%d", &node_val);
			temp=search_bst(root, node_val);
			if(temp)
				printf("\nNode %d found!\n", temp->data);
			else
				printf("\nNode not found!\n");
			break;
		case 4:
			printf("Enter the node to be deleted:");
			scanf("%d", &node_val);
			delete_node(root, node_val);
			break;
		case 5:
			bfs_traversal(root);
			break;
		case 6:
			printf("Height of tree is %d\n", max_depth_bst(root));
			break;
		case 7:
			printf("Size of tree is %d\n", size_bst(root));
			break;
		case 8:
			mirror_bst(root);
			break;
		case 9:
			temp=find_min_bst(root);
			printf("Min. node is %d\n", temp->data);
			break;
		case 10:
			temp=find_max_bst(root);
			printf("Max. node is %d\n", temp->data);
			break;
		case 11:
			delete_bst(root);
			break;
		case 12:
			root = createBSTFromSortedArray (array, 0, n-1);
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
