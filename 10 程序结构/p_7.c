#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 30

const int segments[10][7] = { {1, 1, 1, 1, 1, 1},
							  {0, 1, 1},
							  {1, 1, 0, 1, 1, 0, 1},
							  {1, 1, 1, 1, 0, 0, 1},
							  {0, 1, 1, 0, 0, 1, 1},
							  {1, 0, 1, 1, 0, 1, 1},
							  {1, 0, 1, 1, 1, 1, 1},
							  {1, 1, 1},
							  {1, 1, 1, 1, 1, 1, 1},
							  {1, 1, 1, 1, 0, 1, 1} };
char digits[3][4 * MAX_DIGITS];
const int segment_grid[7][2] = { {0, 1},
								 {1, 2},
								 {2, 2},
								 {2, 1},
								 {2, 0},
								 {1, 0},
								 {1, 1} };

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
	char ch;
	int position = 0;

	clear_digits_array();
	printf("Enter a number: ");
	while ((ch = getchar()) != '\n')
		if (isdigit(ch))
		{
			process_digit(ch - '0', position);
			position += 4;
		}
	print_digits_array();

	return 0;
}

void clear_digits_array(void)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4 * MAX_DIGITS; j++)
			digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
	int row, col;

	for (int i = 0; i < 7; i++)
	{
		row = segment_grid[i][0];
		col = segment_grid[i][1] + position;
		if (segments[digit][i])
			digits[row][col] = i % 3 == 0 ? '_' : '|';
	}
}

void print_digits_array(void)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4 * MAX_DIGITS; j++)
			putchar(digits[i][j]);
		printf("\n");
}