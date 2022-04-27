#include <stdio.h>
#include <string.h>

#define N 100

void reverse(const char* message);

int main(void)
{
	char ch, message[N + 1];
	int i = 0;

	printf("Enter a message: ");
	gets(message);

	reverse(message);

	printf("Reversal is: %s\n", message);

	return 0;
}

void reverse(const char* message)
{
	char* head = message, * tail;
	char temp;

	while (*message)
		message++;
	tail = --message;

	while (head < tail)
	{
		temp = *head;
		*head++ = *tail;
		*tail-- = temp;
	}
}