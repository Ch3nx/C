#include <stdio.h>
#include<math.h>
int main(void)
{
	char ch;
	int num1, denom1, num2, denom2, result_num, result_denom, gcd, denom, temp;

	printf("Enter two fractions separated by a plus sign: ");
	scanf("%d/%d%c%d/%d", &num1, &denom1, &ch, &num2, &denom2);

	switch (ch)
	{
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			break;
		case '/':
			result_num = num1 * denom2;
			result_denom = num2 * denom1;
			break;
	}

	gcd = result_num;
	denom = result_denom;
	while (denom != 0)
	{
		temp = denom;
		denom = gcd % denom;
		gcd = temp;
	}

	if (result_num % result_denom == 0)
		printf("The result is %d\n", result_num / result_denom);
	else if (abs(result_num) > abs(result_denom))
		printf("The result is: %d %d/%d\n",
			result_num / result_denom, result_num % result_denom, result_denom / gcd);
	else
		printf("The result is %d/%d\n", result_num / gcd, result_denom / gcd);

	return 0;
}