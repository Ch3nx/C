#include <stdio.h>
int main(void)
{
	int num, digit;

	printf("Enter a number: ");
	scanf("%d", &num);
	if (num >= 0 && num <= 9)
		digit = 1;
	else if (num >= 10 && num <= 99)
		digit = 2;
	else if (num >= 100 && num <= 999)
		digit = 3;
	else
		digit = 4;

	printf("The number %d has %d digits\n", num, digit);

	return 0;
}