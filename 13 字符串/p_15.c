#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100
#define MAX_LEN 100

char contents[STACK_SIZE];
int top = 0;

bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);
int are_PRN_expression(const char* expression);

int main(void)
{
	char expression[MAX_LEN + 1];
	int result;
	
	for (;;)
	{
		printf("Enter an RPN expression: ");
		gets(expression);
		result = are_PRN_expression(expression);
		printf("Value of expression: %d\n", result);
	}
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

int are_PRN_expression(const char* expression)
{
	int op, result;

	for (;;)
	{
		if (isdigit(*expression))
			push(*expression - '0');
		else
		{
			switch (*expression)
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
					return result;
				case ' ':
					break;
				default:
					exit(EXIT_SUCCESS);
			}
		}
		expression++;
	}
}