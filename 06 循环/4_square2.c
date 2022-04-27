#include <stdio.h>
int main(void)
{
	int i, n;

	printf("This program pints a table of squares.\n");
	printf("Enter numver of entries in table: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		printf("%10d%10d\n", i, i * i);

	return 0;
}