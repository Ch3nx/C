#include <stdio.h>
#include "p_1_stack.h"

int main(void)
{
	
	char ch;
	int i = 0;
	Stack s;

	s = create();
	printf("Enter parenteses and/or braces: ");
	while ((ch = getchar()) != '\n')
	{
		switch (ch)
		{
			case '{':
			case '(':
				push(s, i);
				break;
			case '}':
			case ')':
				pop(s, i);
				break;
		}
	}
	if (!is_empty(s))
	{
		printf("Parentheses/braces are not nested properly\n");
		return 0;
	}
	printf("Parentheses/braces are nested properly\n");
	return 0;
}
