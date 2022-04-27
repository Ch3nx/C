#include <stdio.h>
int main(void)
{
	int i, n;
	char ch;

	printf("This program pints a table of squares.\n");
	printf("Enter numver of entries in table: ");
	scanf("%d", &n);
	ch = getchar();

	for (i = 1; i <= n; i++)
	{
		printf("%10d%10d\n", i, i * i);
		if (i % 24 == 0)
		{
			do
			{
				printf("Press Enter to continue ...");
			} while ((ch = getchar()) != '\n');
			continue;
		}
	}

	return 0;
}