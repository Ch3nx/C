#include <stdio.h>
#include <math.h>
int main(void)
{
	double num, root = 1.0;

	printf("Enter a positive number: ");
	scanf("%lf", &num);

	while (fabs((root + num / root) / 2 - root) >= 0.00001 * root)
		root = (root + num / root) / 2;

	printf("Square root: %f\n", root);

	return 0;
}