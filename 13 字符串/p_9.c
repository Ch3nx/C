#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 80

int compute_vowel_count(const char* sentence);

int main(void)
{
	char ch, sentence[MAX_LEN + 1];
	int num, i = 0;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n' && i < MAX_LEN)
		sentence[i++] = ch;
	sentence[i] = '\0';

	num = compute_vowel_count(sentence);
	
	printf("Your sentence contains %d vowels.\n", num);

	return 0;
}

int compute_vowel_count(const char* sentence)
{
	int num = 0;

	while (*sentence)
	{
		switch (toupper(*sentence++))
		{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				num++;
				break;
			default:
				break;
		}
	}

	return num;
}