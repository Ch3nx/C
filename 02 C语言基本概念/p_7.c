#include <stdio.h>
int main(void)
{
	int dollar_amount;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	printf("\n$20 bills: %d\n", dollar_amount / 20);
	dollar_amount -= (dollar_amount / 20) * 20;
	printf("$10 bills: %d\n", dollar_amount / 10);
	dollar_amount -= (dollar_amount / 10) * 10;
	printf("$5 bills: %d\n", dollar_amount / 10);
	dollar_amount -= (dollar_amount / 5) * 5;
	printf("$1 bills: %d\n", dollar_amount / 1);

	return 0;
}