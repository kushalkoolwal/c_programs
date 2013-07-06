#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int mypow (int base, int power) {

	int i,result=1;
	
	for (i = 1; i <= power; i++)
		result=result*base;

	return result;
}

void display_menu () {

	printf("\n***Math functions in C***\n");
	printf("Press 0  to display this menu\n");
	printf("Press 1  to calculate power\n");
	printf("Press -1 to quit\n");

}


int main (void) {

	int command;
	int base, power=0;

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
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	return 0;
}
