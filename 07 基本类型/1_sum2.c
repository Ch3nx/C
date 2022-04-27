#include <stdio.h>
int main(void)
{
	long n, sum = 0;

	printf("this program sum s a series of integers.\n");
	printf("enter entegers (0 to terminate): ");

	scanf("%ld", &n);
	while (n != 0)
	{
		sum += n;
		scanf("%ld", &n);
	}
	printf("the sum is: %ld\n", sum);


	return 0;
}