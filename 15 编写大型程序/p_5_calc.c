#include <ctype.h>
#include "stack.h"

int main(void)
{
	char ch, op;
	int i = 0, result;

	printf("Enter an RPN expression: ");
	for (;;)
	{
		scanf(" %c", &ch);
		if (isdigit(ch))
			push(ch - '0');
		else
		{
			switch (ch)
			{
				case '+':
					result = pop() + pop();
					push(result);
					break;
				case '-':
					op = pop();
					result = pop() - op;
					push(result);
					break;
				case '*':;
					result = pop() * pop();
					push(result);
					break;
				case '/':
					op = pop();
					result = pop() / op;
					push(result);
					break;
				case '=':
					printf("Value of expression: %d\n", pop());
					printf("Enter an RPN expression: ");
					break;
				default:
					return 0;
			}
		}
	}
}
