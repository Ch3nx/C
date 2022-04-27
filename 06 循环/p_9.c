#include <stdio.h>
int main(void)
{
	int time;
	float loan, rate, payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &rate);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	printf("Enter number of payments: ");
	scanf("%d", &time);

	printf("\n");
	for (int i = 0; i < time; i++)
	{
		loan += loan * rate / 1200 - payment;
		printf("Balance ramaining after first payment: $%.2f\n", loan);
	}

	return 0;
}