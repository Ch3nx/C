/*
* 禁止程序执行任何乘法操作而计算连续的平方值
*/
#include <stdio.h>
int main(void)
{
	int i, n, odd, square;

	printf("This program pints a table of squares.\n");
	printf("Enter numver of entries in table: ");
	scanf("%d", &n);

	i = 1;
	odd = 3;
	for (square = 1; i <= n; odd += 2)
	{
		printf("%10d%10d\n", i, square);
		++i;
		square += odd;
	}

	return 0;
}