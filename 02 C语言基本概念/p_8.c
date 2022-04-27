#include <stdio.h>
int main(void)
{
	float loan, rate, payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &rate);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);

	loan += loan * rate / 1200 - payment;
	printf("\nBalance ramaining after first payment: $%.2f\n", loan);
	loan += loan * rate / 1200 - payment;
	printf("Balance ramaining after second payment: $%.2f\n", loan);
	loan += loan * rate / 1200 - payment;
	printf("Balance ramaining after third payment: $%.2f\n", loan);

	return 0;
}