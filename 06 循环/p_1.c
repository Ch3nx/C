#include <stdio.h>
int main(void)
{
	float num, max = 0.0f;
	
	do
	{
		printf("Enter a num: ");
		scanf("%f", &num);
		if (max < num)
			max = num;
	} while (num > 0);
		

	printf("\nThe largest number entered was %g\n", max);

	return 0;
}