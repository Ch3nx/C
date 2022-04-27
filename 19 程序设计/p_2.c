#include <stdio.h>
#include <ctype.h>
#include "p_2_stack.h"

#define STACK_SIZE 100

int main(void)
{
	char ch, op;
	int i = 0, result;
	Stack s;

	s = create(STACK_SIZE);
	printf("Enter an RPN expression: ");
	for (;;)
	{
		scanf(" %c", &ch);
		if (isdigit(ch))
			push(s, ch - '0');
		else
		{
			switch (ch)
			{
				case '+':
					result = pop(s) + pop(s);
					push(s, result);
					break;
				case '-':
					op = pop(s);
					result = pop(s) - op;
					push(s, result);
					break;
				case '*':;
					result = pop(s) * pop(s);
					push(s, result);
					break;
				case '/':
					op = pop(s);
					result = pop(s) / op;
					push(s, result);
					break;
				case '=':
					printf("Value of expression: %d\n", pop(s));
					printf("Enter an RPN expression: ");
					break;
				default:
					return 0;
			}
		}
	}
}
