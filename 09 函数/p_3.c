#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMEN 10

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
	srand((unsigned)time(NULL));

	char grid[DIMEN][DIMEN], letter = 'A';
	int up, right, down, left, move, i = 0, j = 0;

	generate_random_walk(grid);

	grid[i][j] = letter++;
	while (letter <= 'Z')
	{
		up = 0;
		right = 0;
		down = 0;
		left = 0;
		move = rand() % 4;
		if (i + 1 < DIMEN && grid[i + 1][j] == '.')
			up = 1;
		if (j + 1 < DIMEN && grid[i][j + 1] == '.')
			right = 1;
		if (i - 1 >= 0 && grid[i - 1][j] == '.')
			down = 1;
		if (j - 1 >= 0 && grid[i][j - 1] == '.')
			left = 1;
		if (up + right + down + left == 0)
			break;
		switch (move)
		{
			case 0:
				if (up)
				{
					grid[++i][j] = letter++;
					break;
				}
			case 1:
				if (right)
				{
					grid[i][++j] = letter++;
					break;
				}
			case 2:
				if (down)
				{
					grid[--i][j] = letter++;
					break;
				}
			case 3:
				if (left)
				{
					grid[i][--j] = letter++;
					break;
				}
			default:
				break;
		}
	}
	print_array(grid);

	return 0;
}

void generate_random_walk(char walk[10][10])
{
	for (int i = 0; i < DIMEN; i++)
		for (int j = 0; j < DIMEN; j++)
			walk[i][j] = '.';
}

void print_array(char walk[10][10])
{
	for (int i = 0; i < DIMEN; i++)
	{
		for (int j = 0; j < DIMEN; j++)
			printf(" %c", walk[i][j]);
		printf("\n");
	}
}