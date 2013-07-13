#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

#define BITS_IN_BYTES	8

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

/* prints binary representation of the number
   We use an AND operator and a variable 'mask' and check status of each
   individual bits. If the bit is OFF we print a 0 otherwise we print a 1.
   to get individual bits we use the left shift operator (<<). E.g:
   1 << 15 = 1000000000000000
   5 (101) & 1000000000000000 = 0
   5 (101) & 0100000000000000 = 0
*/

void showbits (int num) {

	int i, intsize, result, mask;

	intsize = sizeof(int)*BITS_IN_BYTES ;

	printf("Binary representation of %d:", num);
	for (i=intsize-1; i>=0; i--) {
		result = num & (1 << mask);		
		result == 0 ? printf("0") : printf("1");
	}
	printf("\n");
}


void display_menu () {

	printf("\n***Bitwise Programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  for showbits function\n");		
	printf("Press 2  to check odd or even\n");		
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
			printf("Enter a number to print binary representation:");
			scanf("%d", &num);
			showbits(num);
			break;
		case 2:			
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
