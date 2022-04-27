#include <stdio.h>
int main(void)
{
	char op;
	float value, num;

	printf("Enter an expression: ");
	scanf("%f", &value);

	while ((op = getchar()) != '\n')
	{
		scanf("%f", &num);
		switch (op)
		{
			case '+':
				value += num;
				break;
			case '-':
				value -= num;
				break;
			case '*':
				value *= num;
				break;
			case '/':
				value /= num;
				break;
		}
	}

	printf("Value of expression: %.1f\n", value);

	return 0;
}