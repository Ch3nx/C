#include <stdlib.h>
#include "p_2_stack.h"

struct  stack_p_2
{
	char* contents;
	int size;
	int top;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(int size)
{
	Stack s = malloc(sizeof(struct  stack_p_2));
	if (s == NULL)
		terminate("Error in create: stack could not be created.");
	s->contents = malloc(sizeof(size * sizeof(char)));
	s->size = size;
	s->top = 0;
}

void destroy(Stack s)
{
	free(s->contents);
	free(s);
}

void make_empty(Stack s)
{
	s->top = 0;
}

bool is_empty(Stack s)
{
	return s->top == 0;
}

bool is_full(Stack s)
{
	return s->top == s->size;
}

void push(Stack s, char i)
{
	if (is_full(s))
		terminate("Expression is too complex.");
	else
		s->contents[s->top++] = i;
}

char pop(Stack s)
{
	if (is_empty(s))
		terminate("Not enough operands in expression.");
	else
		return s->contents[--s->top];
}