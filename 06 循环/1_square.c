#include <stdio.h>
int main(void)
{
	int i, n;

	printf("This program pints a table of squares.\n");
	printf("Enter numver of entries in table: ");
	scanf("%d", &n);

	i = 1;
	while (i <= n)
	{
		printf("%10d%10d\n", i, i * i);
		i++;
	}

	return 0;
}