#include <stdio.h>

#define MAX_LEN 80

double compute_average_word_length(const char* sentence);

int main(void)
{
	char ch, sentence[MAX_LEN + 1];
	int i = 0;
	float result = .0f;
	

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n' && i < MAX_LEN)
		sentence[i++] = ch;
	sentence[i] = '\0';

	result = compute_average_word_length(sentence);

	printf("Average word length: %.1f\n", result);

	return 0;
}

double compute_average_word_length(const char* sentence)
{
	int num = 1;
	float aver = .0f;

	while (*sentence)
	{
		if ((*sentence == ' '))
			num++;
		else
			aver++;
		sentence++;
	}

	return aver / num;
}