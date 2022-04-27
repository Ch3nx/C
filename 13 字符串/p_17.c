#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define N 100

bool is_palindrome(const char* message);

int main(void)
{
	bool flag;
	char ch, message[N + 1];
	int i = 0;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && i < N)
		if (isalpha(ch))
			message[i++] = tolower(ch);
	message[i] = '\0';

	flag = is_palindrome(message);

	if (flag)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}

bool is_palindrome(const char* message)
{
	char* head = message, * tail;
	
	while (*message)
		message++;
	tail = --message;
	while (head < tail)
		if (*head++ != *tail--)
			return false;
	return true;
}