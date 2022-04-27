#include <stdio.h>

int main(void)
{
	int size, i, j, flag = 1, square[99][99] = { 0 };

	printf("This program created a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);

	i = 0;
	j = size / 2;
	for (int k = 1; k <= size * size; k++)
	{
		if (square[i][j])
		{
			i = (i + 2) % size;
			j = (j - 1 + size) % size;
			square[i][j] = k;
		}
		else
			square[i][j] = k;
		i = (i - 1 + size) % size;
		j = (j + 1 + size) % size;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%4d", square[i][j]);
		printf("\n");
	}

	return 0;
}