#include <stdio.h>

#define N 100

int main(void)
{
	char ch, message[N];
	int i = 0;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && i < N)
		message[i++] = ch;

	printf("Reversal is: ");
	while (i > 0)
		putchar(message[--i]);

	return 0;
}