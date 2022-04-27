#include <stdio.h>
int main(void)
{
	int num, result  = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		result *= i;

	printf("Factotial of %d: %d\n", num, result);

	return 0;
}
//short 7
//int 12
//long 12
//long long 20
//float 34
//double 170
//long double 170