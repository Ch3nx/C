#include <stdio.h>
int main(void)
{
	int num[5][5], row_sum[5] = { 0 }, col_sum[5] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		printf("Enter row %d: ", i + 1);
		for (int j = 0; j < 5; j++)
			scanf("%d", &num[i][j]);
	}

	printf("\nRow totals: ");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			row_sum[i] += num[i][j];
		printf(" %d", row_sum[i]);
	}
	printf("\nColumn totals: ");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			col_sum[i] += num[j][i];
		printf(" %d", col_sum[i]);
	}
	printf("\n");
		

	return 0;
}