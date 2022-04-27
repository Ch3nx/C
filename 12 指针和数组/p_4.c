#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define N 100

int main(void)
{
	bool flag = true;
	char ch, message[N], * p = message, * q;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && p < message + N)
		if (isalpha(ch))
			*p++ = tolower(ch);

	for (q = message; q < message + (p - message) / 2; q++)
		if (*q != *(message + (p - q - 1)))
			flag = false;
	if (flag)
		printf("Palindrome");
	else
		printf("Not a palindrome");

	return 0;
}