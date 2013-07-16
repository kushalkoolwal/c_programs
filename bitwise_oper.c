#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

/* define boolean types */
#define TRUE 1
#define FALSE 0

/* define exit code */
#define CODE 0

typedef int boolean;

#define BITS_IN_BYTES	8

/* List of bitwise operators:
	&    bitwise AND				- check status of bit
	¦    bitwise inclusive OR       - to set (ON) a particular bit
	^    bitwise exclusive OR (XOR) - toggle a bit ON or OFF
	~    one’s complement (unary)   - to clear (OFF) a particular bit with &
	<<   left shift					- fills bits with 0
	>>   right shift				- fills bits with 0 for unsigned

*/

/* function to check endianness 
    
 */

int check_endianness () {

	int num=1

}

/* function to multiple numbers without * operator 
   num  << 1 = num times 2
   num  << 2 = num times 4
   num  << 3 = num times 8
   basically the shift number is raised to the power of 2 i.e. pow(2, shift)
 */
int mult_bitwise (int num, int mult) {

	num = num << mult;

	return num;

}

/* function to swap integers using  */
void swap_bitwise(int *x, int *y) {

	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;

}
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
		result = num & (1 << i);		
		result == 0 ? printf("0") : printf("1");
	}
	printf("\n");
}


void display_menu () {

	printf("\n***Bitwise Programs in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  for showbits function\n");
	printf("Press 2  to check odd or even\n");
	printf("Press 3  to swap numbers\n");
	printf("Press 4  to multiply numbers\n");
	printf("Press 5  to detect endianness of architecture\n");						
	printf("Press -1 to quit\n");

}


int main (void) {

	int command, num, x, y, z;

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
		case 3:			
			printf("Enter number in x:");
			scanf("%d", &x);
			printf("Enter number in y:");
			scanf("%d", &y);
			swap_bitwise(&x, &y);
			printf("x=%d, y=%d\n", x, y);
			break;
		case 4:			
			printf("Enter number:");
			scanf("%d", &x);
			printf("Enter left shit number (2^y):");
			scanf("%d", &y);
			z=pow(2,y);
			printf("%d times %d = %d\n", x, z, mult_bitwise(x, y));
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
}
