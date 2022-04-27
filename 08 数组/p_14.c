#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
	char ch, sentence[MAX_SIZE];
	int start, end, i = 0;

	printf("Enter a sentence: ");
	do
	{
		sentence[i++] = getchar();
	} while (sentence[i - 1] != '.' && sentence[i - 1] != '?' && sentence[i - 1] != '!' && i < MAX_SIZE);

	printf("Reversal of sentence: ");
	end = i - 1;
	for (int j = end; j >= 0; j--)
	{
		if (sentence[j] == ' ')
		{
			start = j + 1;
			for (int k = start; k < end; k++)
				putchar(sentence[k]);
			putchar(' ');
			end = start - 1;
		}
	}
	for (int j = 0; j < end; j++)
		putchar(sentence[j]);
	printf("%c\n", sentence[i-1]);

	return 0;
}