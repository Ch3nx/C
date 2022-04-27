#include <stdio.h>

void create_magic_square(int n, int magic_square[99][99]);
void print_magic_square(int n, int magic_square[99][99]);

int main(void)
{
	int size, i, j, flag = 1, square[99][99] = { 0 };

	printf("This program created a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);

	create_magic_square(size, square);
	
	print_magic_square(size, square);

	return 0;
}

void create_magic_square(int n, int magic_square[99][99])
{
	int i = 0, j = n / 2;
	for (int k = 1; k <= n * n; k++)
	{
		if (magic_square[i][j])
		{
			i = (i + 2) % n;
			j = (j - 1 + n) % n;
			magic_square[i][j] = k;
		}
		else
			magic_square[i][j] = k;
		i = (i - 1 + n) % n;
		j = (j + 1 + n) % n;
	}
}

void print_magic_square(int n, int magic_square[99][99])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d", magic_square[i][j]);
		printf("\n");
	}
}