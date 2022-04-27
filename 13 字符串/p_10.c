#include <stdio.h>

#define MAX_LEN 80

void reverse_name(char* name);

int main(void)
{
	char ch, name[MAX_LEN + 1];
	int i = 0;

	printf("Enter a first and last name: ");
	while ((ch = getchar()) != '\n' && i < MAX_LEN)
		name[i++] = ch;
	name[i] = '\0';

	reverse_name(name);

	return 0;
}

void reverse_name(char* name)
{
	char first_name;

	while (*name++ == ' ');
	first_name = *(name - 1);
	while (*name++ != ' ');
	while (*name++ == ' ');
	putchar(*(name - 1));
	while (*name != '\0')
		putchar(*name++);
	printf(", %c.\n", first_name);
}