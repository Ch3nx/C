#include <stdio.h>
int main(void)
{
	long i, n;

	printf("This program pints a table of squares.\n");
	printf("Enter numver of entries in table: ");
	scanf("%ld", &n);

	for (i = 1; i <= n; i++)
		printf("%18ld%18ld\n", i, i * i);

	return 0;
}