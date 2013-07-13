#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/* define boolean types */
#define TRUE 1		/* In C any non-zero value is considered as true */
#define FALSE 0
typedef int boolean;

/* define exit code */
#define CODE 0

#define ARRAY_SIZE 100

/* convert decimal to hex and store results in an array */
void dec_to_hex (int num) {

	int i, j;
	int result[ARRAY_SIZE];

	i=0;
	while (num != 0) {
		result[i++] = num % 16;
		num = num / 16;
	}

	printf("Hex:");
	if (i == 0) {
		printf("%d", i);
	}

	else {
		for (j=i-1; j>=0; j--) {
			/* to print a,b,c,d,e,f use %x */
			if (result[j] >= 10)
				printf("%x", result[j]);
			else
				printf("%d", result[j]);
		}
	}
	printf("\n");
}

/* convert decimal to binary and store bits in an array */
void dec_to_bin (int num) {

	int i,j, result[ARRAY_SIZE];

	i = 0;
	while (num != 0) {
		result[i] = num % 2;
		i++;
		num = num / 2;
	}

	printf("Binary:");
	if (i == 0) 
		printf("%d", i);
	else
		for (j=i-1; j>=0; j--)
			printf("%d", result[j]);

	printf("\n");
}

/* function to calculate fibonacci series 
   Example: Fibs(7) = 0,1,1,2,3,5,8
   Note: Except first two numbers, all others are sum of previous two numbers
 */
void calc_fibonacci(int num) {

	int i;
	/* define the first two number in the series to get the loop going */
	int running, first=0, second=1;

	/* for num=0, the program will not enter 'for' loop */
	for (i=0; i<num; i++) {
		/* 'if' condition will always print '0' and '1'. */
		if (i <= 1) {
			running = i;
		}
		else {
			running = first + second;
			first = second;
			second = running;
		}
		printf("%d\t", running);
	}
}

int mypow(int, int); /* prototype for mypower */

/*  function to reverse a given interger and also to check for palindrome
	Example: 423 -> 324
 */

int reverse_num (int num) {

	int result=0, rem;

	/* this is how you typically break apart an integer into individual digits*/
	while (num != 0) {
		rem = num % 10;
		result = (10 * result) + rem;
		num = num / 10;
	}
	return result;

}
void power_of_two (int num) {

	int total, currentpow, flag;
	total=num;
	currentpow=0;
	flag=1;

	/* find the nearest number expressible as power of 2 and get power.
	   Example: For number 22, 16 is the nearest number that can be expressed as
 	   power of two.
     */
	while (mypow (2, currentpow) < num)
		currentpow++;

	printf("Power = %d\n", currentpow);
	/* without 'currentpow--' in the below while loop, we need this	for debug */
	fflush(stdout);

	while (currentpow >= 0) {
		if (total >= mypow(2, currentpow)) {
			if (flag) {		
				printf("%d = 2^%d", num, currentpow);
				flag = 0;
			}
			else {
				printf(" + 2^%d", currentpow);
			}
			total = total - mypow(2, currentpow);
		}
		currentpow--;
	}
	printf("\n");
}

/* we use "%" operator to extract the digits from the number.
   Example: Sum of 47 = 4+7 = 11
   Note: (4 % 10) = 4, (4 / 10) = 0;	
 */

int sum_digits (int num) {

	int result=0, rem;

	/* this is how you typically break apart an integer into individual digits*/
	while (num != 0) {
		rem = num % 10;
		/*printf("Rem=%d\n", rem);*/
		result = result + rem;
		/*printf("Sum=%d\n", result);*/
		num = num / 10;
	}
	return result;
}
/* prime number has exactly two factors: 1 and number itself
   0 and 1 are not prime numbers. Note that 2 is even and prime.
   Example: 2, 3, 5, 7, 11, 13, 17
 */
boolean is_prime(int num) {

	int i;
	
	if (num == 0 || num == 1)
		return FALSE;

	for (i = 2; i < num; i++) {
		if (num % i == 0)
			return FALSE;
	}
	return TRUE;				
}

/* Factor is a number that divides exactly.
   1 and the number itself are always factors of given number.
   Example: Factors of 10: 1, 2, 5, 10. 
 */
void factors (int num) {

	int i, result;

	printf("Factors of %d:", num);
	if (num == 0)
		printf(" 0");
	for (i=1; i<=num; i++) {
		result = num % i;
			if (result == 0)
				printf(" %d ", i);
	}
	printf("\n");
}

/*  Defition of n!: n = n * (n-1)
	Example: 5! = 5 * 4 * 3 * 2 * 1
	Note: 0! = 1, 1! = 1
 */
int factorial_recurse (int num) {

	if (num == 0)
		return 1;
	else
		return (num * factorial_recurse(num-1));
}

int factorial (int num) {

	int i, result=1;
	
	for (i=num; i>=1; i--)
		result = result * num;
	
	return result;
}

/*  Powers of a number are obtained by multiplying it by itself power times.
    Example: pow(2,5) = 2^5 = 2 x 2 x 2 x 2 x 2
	Note: (anything)^0 = 1, 1^(anything) = 1
 */
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
	printf("Press 3  to calculate factors\n");
	printf("Press 4  to check for prime\n");
	printf("Press 5  to sum digits of a number\n");
	printf("Press 6  to express integer as sum of power of two\n");
	printf("Press 7  to reverse a number\n");
	printf("Press 8  to print Fibonacci series\n");
	printf("Press 9  to check if number is Palindrome\n");
	printf("Press 10  to convert decimal to binary\n");
	printf("Press 11  to convert decimal to hex\n");
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
			printf("Factorial of %d is %d\n", num, factorial(num));
			printf("Factorial (recursive)  of %d is %d\n", num, \
			factorial_recurse(num));			
			break;
		case 3:
			printf("Enter number to find its factors:");
			scanf("%d", &num);
			factors(num);			
			break;
		case 4:
			printf("Enter number to find its prime:");
			scanf("%d", &num);
			is_prime(num) ? printf("Prime number\n") : printf("Not  prime\n");	
			break;
		case 5:
			printf("Enter number to sum its digit:");
			scanf("%d", &num);
			printf("Sum of digits of %d: %d\n", num, sum_digits(num));
			break;
		case 6:
			printf("Enter number to express as sum of power of 2's:");
			scanf("%d", &num);
			power_of_two(num);
			break;
		case 7:
			printf("Enter number to reverse it:");
			scanf("%d", &num);
			printf("Reverse of %d: %d\n", num, reverse_num(num));
			break;
		case 8:
			printf("Enter number to calculate Fibonacci series:");
			scanf("%d", &num);
			calc_fibonacci(num);
			break;
		case 9:
			printf("Enter number to check for Palindrome:");
			scanf("%d", &num);
		    num == reverse_num(num) ? printf("Number is Palindrome\n") : \
			printf("Number is not Palindrome\n");
			break;
		case 10:
			printf("Enter number to convert to binary:");
			scanf("%d", &num);
			dec_to_bin(num);
			break;
		case 11:
			printf("Enter number to convert to hex:");
			scanf("%d", &num);
			dec_to_hex(num);
			break;
		case -1:
			return 0;
		default:
			printf("Invalid choice\n");
			break;
	}
	return 0;
}
