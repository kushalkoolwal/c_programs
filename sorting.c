#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 8
#define TRUE 1
#define FALSE 0

void display_list(int l[], int size) {

	int i;

	for (i=0; i<SIZE; i++)
		printf("%d ", l[i]);
	printf("\n\n");
}


/* interchange l[x] and l[y] */
void swap(int l[], int x, int y) {

	int temp;
	
	temp = l[x];
	l[x] = l[y];
	l[y]= temp;

}
void quick_sort (int l[], int left, int right) {

	int i, pivot;

	/* do nothing if array contains fewer than two elements */
	if(left >= right)
		return;
	/* partition and move pivot element to v[0] */
	swap(l, left, (left+right)/2);
	display_list(l, SIZE);
	pivot = left;
	printf("Pivot: %d\n", l[pivot]);
	/*scan all items from pivot+1 */
	for (i=left+1; i<=right; i++)
		if (l[i] < l[left]) {
			printf("Compared for Swap: %d %d\n", l[i], l[left]);	
			swap (l, ++pivot, i);
			display_list(l, SIZE);
		}
	swap(l, left, pivot);
	display_list(l, SIZE);
	printf("Recursion Starts\n");
	quick_sort (l, left, pivot-1);
	quick_sort (l, pivot+1, right);
}

void bubble_sort(int l[], int size) {

	int i, j;
	
	for (i=0; i<(size-1); i++) {		
		for (j=0; j<(size-(i+1)); j++) {
			printf("i=%d, j=%d\n", i, j);
			if (l[j] > l[j+1]) {				
				swap(l, j, j+1);
				/*display_list(l, SIZE);*/
			}
		}
		printf("List after pass: ");
		display_list(l, SIZE);
	}
}

void selection_sort(int l[], int size) {

	int i, j, min;

	for (i=0; i<size-1; i++) {
		min = i;
		for (j=i+1; j<size; j++)
			if (l[j] < l[min])
				min = j;
		
		swap(l, i, min);
		printf("List after pass: ");
		display_list(l, SIZE);
	}			
}

void insertion_sort (int l[], int size) {

	int i, index;
	for (i=1; i<size; i++) {
		index = i;
		printf("index=%d  ", index);
		
		/* Keep pushing the index element to the left */
		while (index > 0 && (l[index] < l[index-1])) {
			swap(l, index, index-1);
			display_list(l, SIZE);
			index--;
		}
		printf("List after pass: ");
		display_list(l, SIZE);
	}
}

/* Shell sort is an extension of insertion sort. Instead of exchanging adjacent
   elements, the Shell sort arranges elements that are far apart.
 */
void shell_sort(int l[], int size) {

	int i, j, temp, step;
	i,j=0;
	for (step = size/2; step > 0; step=step/2) {
		printf("1st Level: step=%d, i=%d, j=%d\n", step, i, j);
		for (i=step; i<SIZE; i++) {
			printf("2nd Level: step=%d, i=%d, j=%d\n", step, i, j);
			for (j=i-step; j>=0 && l[j]>l[j+step]; j=j-step) {
				printf("3rd Level: step=%d, i=%d, j=%d\n",step, i, j);
				swap(l, j, j+step);
				display_list(l, SIZE);
			}
		}
	}
}

void merge_sort(int l[], int tmp[], int size) {


}

int binary_search (int l[], int low, int high, int key) {

	int middle;

	middle = (low+high)/2;
	while (low <= high) {		
		if (key == l[middle])
			return key;
		else if (key < l[middle])
			high = middle -1;
		else if (key > l[middle])
			low = middle + 1;
		else
			printf("Impossible to reach here\n");

		middle=(low+high)/2;
	}
	return -1;
}

display_menu() {

	printf("Sorting Algorithms\n");
	printf("Press 0  to display this menu\n");	
	printf("Press 1 for Quick Sort\n");
	printf("Press 2 for Bubble Sort\n");
	printf("Press 3 for Selection Sort\n");
	printf("Press 4 for Insertion Sort\n");
	printf("Press 5 for Shell Sort\n");
	printf("Press 6 for Merge Sort\n");
	printf("Press 7 for Binary Search\n");
	printf("Press -1 to quit\n");
}

int main (int argc, char *argv[]) {

	int command;
	int key, result, inputsize=100;

	int list[SIZE]={8,6,10,3,1,2,5,4};
	int tmp[SIZE];

	int *dlist;
	
	
	if (argc > 1) {
		inputsize = atoi(argv[1]);	
		/* initialize dynamic array */
		dlist = (int *)malloc(sizeof(int)*inputsize);
	}

	srand(time(NULL));

	display_menu();

	/*initialize the array
	 generate numbers between 1 and 100 
	for (i=0; i<SIZE; i++) {

		j = rand()%100 + 1;
		list[i]=j;
	}*/

	while(TRUE) {
		printf("Enter a command from above menu:");
		scanf("%d", &command);

		switch (command) {

		case 1:
			printf("List before sorting is:\n");
			display_list(list, SIZE);
			quick_sort(list, 0, SIZE-1);
			printf("List after sorting is:\n");
			display_list(list, SIZE);
			break;
		case 2:
			printf("List before sorting:\n");
			display_list(list, SIZE);
			bubble_sort(list, SIZE);
			printf("List after sorting:\n");
			display_list(list, SIZE);
			break;
		case 3:
			printf("List before sorting:\n");
			display_list(list, SIZE);
			selection_sort(list, SIZE);
			printf("List after sorting:\n");
			display_list(list, SIZE);
			break;
		case 4:
			printf("List before sorting:\n");
			display_list(list, SIZE);
			insertion_sort(list, SIZE);
			printf("List after sorting:\n");
			display_list(list, SIZE);
			break;
		case 5:
			printf("List before sorting:\n");
			display_list(list, SIZE);
			shell_sort(list, SIZE);
			printf("List after sorting:\n");
			display_list(list, SIZE);
			break;
		case 6:
			printf("List before sorting:\n");
			display_list(list, SIZE);
			merge_sort(list, tmp, SIZE);
			printf("List after sorting:\n");
			display_list(list, SIZE);
			break;
		case 7:
			printf("Sorting array now...");
			insertion_sort(list, SIZE);
			display_list(list, SIZE);
			printf("Enter key to find:");
			scanf("%d", &key);
			result=binary_search(list, 0, SIZE-1, key);
			(result >=0) ? printf("Key found\n") : printf("Key not found\n");
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
