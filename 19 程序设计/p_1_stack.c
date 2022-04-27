#include <stdio.h>
#include <stdlib.h>
#include "p_1_stack.h"

#define STACK_SIZE 100

struct stack_p_1
{
	char contents[STACK_SIZE];
	int top;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_p_1));
	if (s == NULL)
		terminate("Error in create: stack could not be created.");
	s->top = 0;
	return s;
}

bool is_empty(Stack s)
{
	return s->top == 0;
}
bool is_full(Stack s)
{
	return s->top == STACK_SIZE;
}

void push(Stack s, char i)
{
	if (is_full(s))
		terminate("Stack overflow.");
	else
		s->contents[s->top++] = i;
}

void pop(Stack s, char i)
{
	if (is_empty(s))
		terminate("Stack underflow");
	else if ((s->contents[s->top - 1] == '{' && i == ')') || (s->contents[s->top - 1] == '(' && i == '}'))
		terminate("Parentheses/braces are not nested properly.");
	else
		s->contents[--s->top];
}