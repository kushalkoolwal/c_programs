#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*  5! = 5 * 4 * 3 * 2 * 1
	n = n * (n-1)
 */
int factorial (int num) {

	int i, result=1;
	
	for (i=num; i>=1; i--)
		result = result * num;
	
	return result;
}

int mypow (int base, int power) {

	int i,result=1;
	
	for (i = 1; i <= power; i++)
		result = result * base;

	return result;
}

void display_menu () {

	printf("\n***Math functions in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to calculate power\n");
	printf("Press 2  to calculate factorial\n");
	printf("Press -1 to quit\n");

}


int main (void) {

	int command;
	int base, power, num;
	display_menu ();
	printf("Enter a command from above menu:");
	scanf("%d", &command);

	switch (command) {
	
		case 0:
			display_menu();
			break;
		case 1:
			printf("Enter base:");
			scanf("%d", &base);
			printf("Enter power:");
			scanf("%d", &power);
			printf("The pow(base,power) is %d\n", mypow(base, power));
			break;
		case 2:
			printf("Enter number to find factorial:");
			scanf("%d", &num);			
			printf("The factorial of %d is %d\n", num, factorial(num));
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	return 0;
}
