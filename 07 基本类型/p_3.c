#include <stdio.h>
int main(void)
{
	double n, sum = 0.0;

	printf("this program sum s a series of integers.\n");
	printf("enter entegers (0 to terminate): ");

	scanf("%lf", &n);
	while (n != 0)
	{
		sum += n;
		scanf("%lf", &n);
	}
	printf("the sum is: %lf\n", sum);


	return 0;
}