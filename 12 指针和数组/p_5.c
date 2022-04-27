#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
	char* start, * end, sentence[MAX_SIZE], * p = sentence;

	printf("Enter a sentence: ");
	do
	{
		*p++ = getchar();
	} while (*(p - 1) != '.' && *(p - 1) != '?' && *(p - 1) != '!' && p < sentence + MAX_SIZE);

	printf("Reversal of sentence: ");
	end = p - 1;
	for (char* i = end; i >= sentence; i--)
	{
		if (*i == ' ')
		{
			start = i + 1;
			for (char* j = start; j < end; j++)
				putchar(*j);
			putchar(' ');
			end = start - 1;
		}
	}
	for (char* i = sentence; i < end; i++)
		putchar(*i);
	printf("%c\n", *(p - 1));

	return 0;
}