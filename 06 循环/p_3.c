#include <stdio.h>
int main(void)
{
	int num, denom, temp, n, d;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num, &denom);

	n = num;
	d = denom;
	while (denom != 0)
	{
		temp = denom;
		denom = num % denom;
		num = temp;
	}

	printf("In lowest terms: %d/%d\n", n / num, d / num);

	return 0;
}