#include <stdio.h>

#define N 100

int main(void)
{
	int i = 0;
	char ch, message[N], * p = &message[0];

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && p < &message[N])
		*p++ = ch;

	printf("Reversal is: ");
	while (p > &message[0])
		putchar(*--p);

	return 0;
}