#include <stdio.h>
int main(void)
{
	int check_digit, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_num, second_num, total;

	printf("Enter the first (single) digit: ");
	scanf("%1d", &d);
	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
	printf("Enter the last (single) digit: ");
	scanf("%d", &check_digit);

	first_num = d + i2 + i4 + j1 + j3 + j5;
	second_num = i1 + i3 + i5 + j2 + j4;
	total = 9 - ((3 * first_num + second_num) - 1) % 10;

	if (check_digit == total)
		printf("VALID\n");
	
	else
		printf("INVALID\n");

	return 0;
}