#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

bool is_empty(void);
bool is_full(void);
void push(char i);
void pop(char i);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	char ch;
	int i = 0;

	printf("Enter parenteses and/or braces: ");
	while ((ch = getchar()) != '\n')
	{
		switch (ch)
		{
			case '{':
			case '(':
				push(ch);
				break;
			case '}':
			case ')':
				pop(ch);
				break;
		}
	}
	if (!is_empty())
	{
		printf("Parentheses/braces are not nested properly\n");
		return 0;
	}
	printf("Parentheses/braces are nested properly\n");
	return 0;
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

void pop(char i)
{
	if (is_empty())
		stack_underflow();
	else if ((contents[top-1] == '{' && i == ')') || (contents[top - 1] == '(' && i == '}'))
	{
		printf("Parentheses/braces are not nested properly\n");
		exit(EXIT_FAILURE);
	}
	else
		contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow\n");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Stack underflow\n");
	exit(EXIT_FAILURE);
}