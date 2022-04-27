#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60

int line_len = 0;
int num_words = 0;

struct node
{
	struct node* next;
	char word[];
};

struct node* line = NULL;

void clear_line(void)
{
	struct node* p;

	while (line != NULL)
	{
		p = line;
		line = line->next;
		free(p);
	}
	line_len = 0;
	num_words = 0;
}

void add_word(const char* word)
{
	struct node* new_word, *p = line;

	new_word = malloc(sizeof(struct node) + strlen(word) + 1);
	if (new_word == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	strcpy(new_word->word, word);
	new_word->next = NULL;
	if (p == NULL)
		line = new_word;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = new_word;
	}

	if (num_words > 0)
		line_len++;
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i;
	struct node* p = line;

	extra_spaces = space_remaining();
	while (line_len && p != NULL)
	{
		printf("%s", p->word);
		line_len -= (strlen(p->word) + 1);
		p = p->next;
		if (num_words > 1)
		{
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (i = 1; i <= spaces_to_insert + 1; i++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}

void flush_line(void)
{
	struct node* p = line;

	if (line_len > 0)
	{
		for (int i = 0; p != NULL; i++, p = p->next)
		{
			if (i > 0 && p->next != NULL)
				putchar(' ');
			printf("%s", p->word);
		}
	}
	printf("\n");
	clear_line();
}