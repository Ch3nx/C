#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

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
void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
	exit(EXIT_FAILURE);
}