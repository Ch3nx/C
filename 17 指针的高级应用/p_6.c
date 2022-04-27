#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 20
#define MAX_WORD_LEN 20

int num_word = 0;

void read_word(char* word);
void malloc_words(char* words[], char* word);
int compare_words(const void* p, const void* q);

int main(void)
{
	char* words[MAX_WORD], word[20];

	for (;;)
	{
		printf("Enter word: ");
		read_word(word);
		if (strlen(word) == 0)
			break;
		malloc_words(words, word);
	}

	qsort(&words[0], num_word, sizeof(words[0]), compare_words);
	printf("\nIn sorted order: ");
	for (int i = 0; i < num_word; i++)
	{
		printf("%s", words[i]);
		if (i < num_word - 1)
			putchar(' ');
	}
	putchar('\n');

	return 0;
}

void read_word(char* word)
{
	int ch, i = 0;

	while ((ch = getchar()) == ' ');
	while (ch != '\n')
	{
		word[i++] = ch;
		ch = getchar();
	}
	word[i] = '\0';
}

void malloc_words(char* words[], char* word)
{
	words[num_word] = malloc(strlen(word) + 1);
	if (words[num_word] == NULL)
	{
		printf("Error: realloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(words[num_word], word);
	num_word++;
}

int compare_words(const void* p, const void* q)
{
	return strcmp(*(char**)p, *(char**)q);
}