#include <stdio.h>

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator);

int main(void)
{
	int num, denom, reduced_numerator, reduced_denominator;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num, &denom);

	reduce(num, denom, &reduced_numerator, &reduced_denominator);
	printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

	return 0;
}

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator)
{
	int temp, n = numerator, d = denominator;
	while (denominator != 0)
	{
		temp = numerator % denominator;
		numerator = denominator;
		denominator = temp;
	}
	*reduced_numerator = n / numerator;
	*reduced_denominator = d / numerator;

}