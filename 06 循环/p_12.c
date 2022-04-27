#include <stdio.h>
int main(void)
{
	int i = 1, temp = 1;
	float num, result = 1.0f;

	printf("Enter epsilon: ");
	scanf("%f", &num);

	if (result < num)
	{
		printf("Approximation of e: %f\n", result);
		return 0;
	}
	for (;;)
	{
		
		if (1.0f / temp < num)temp *= i++;
			break;
		result += 1.0f / temp;
	}

	printf("Approximation of e: %f\n", result);

	return 0;
}