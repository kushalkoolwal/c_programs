#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0


/* List of bitwise operators:
	&    bitwise AND
	¦    bitwise inclusive OR
	^    bitwise exclusive OR
	<<   left shift
	>>   right shift
	~    one’s complement (unary)
*/

/* function to check odd or even using Bitwise AND (&). LSB of every odd
   number is 1, therefore odd number & 1 = 1, number is odd otherise even.
   note: '0' is even number
*/
void check_odd_even (int num) {

	if (num & 1 == 1)
		printf("Odd\n");
	else
		printf("Even\n");

}

void display_menu () {

	printf("\n***Bitwise Programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to check odd or even\n");		
	printf("Press -1 to quit\n");

}


int main (void) {

	int command, num;

	display_menu();
	printf("Enter a command from above menu:");
	scanf("%d", &command);
	switch (command) {
	
		case 0:
			display_menu();
			break;
		case 1:			
			printf("Check number is even or odd:");
			scanf("%d", &num);
			check_odd_even(num);
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
}
