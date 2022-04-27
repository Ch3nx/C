#include <stdio.h>
int main(void)
{
	int num, temp = 1;
	float result = 1.0f;

	printf("Enter integer number: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		temp *= i;
		result += 1.0f / temp;
	}

	printf("Approximation of e: %f\n", result);

	return 0;
}