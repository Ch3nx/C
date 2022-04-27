#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 20
#define MAX_SIZE 30

int main(void)
{
	char sentence[MAX_SIZE][MAX_LEN + 1];
	int ch, i = 0, j = 0;

	printf("Enter a sentence: ");
	do
	{
		for (;;)
		{
			ch = getchar();
			if (isalpha(ch) || ch == '\'' && j < MAX_LEN)
				sentence[i][j++] = ch;
			else
			{
				sentence[i++][j] = '\0';
				break;
			}
		}
		j = 0;
	} while (ch != '.' && ch != '?' && ch != '!' && i < MAX_SIZE);

	printf("Reversal of sentence: ");
	for (--i; i > 0; i--)
		printf("%s ", sentence[i]);
	printf("%s%c\n", sentence[i], ch);

	return 0;
}