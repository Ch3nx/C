#include <stdio.h>
int main(void)
{
	float income, tax;

	printf("Enter taxable income: ");
	scanf("%f", &income);

	if (income < 750.00f)
		tax = income * .01f;
	else if (income <= 2250.00f)
		tax = (income - 750.00f) * .02f + 7.50f;
	else if (income <= 3750.00f)
		tax = (income - 2250.00f) * .03f + 37.50f;
	else if (income <= 5250.00f)
		tax = (income - 3750.00f) * .04f + 82.50f;
	else if (income <= 7000.00f)
		tax = (income - 5250.00f) * .05f + 142.50f;
	else
		tax = (income - 7000.00f) * .06f + 230.00f;

	printf("Tax due: $%.2f\n", tax);

	return 0;
}