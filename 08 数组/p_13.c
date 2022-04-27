#include <stdio.h>
int main(void)
{
	char temp, name[20];
	int i = 0;

	printf("Enter a first and last name: ");

	while ((name[i++] = getchar()) != '\n');
	printf("You enered the name: ");
	i = 0;
	while (name[i++] != ' ');
	while (name[i++] == ' ');
	putchar(name[--i]);
	while (name[++i] != '\n')
		putchar(name[i]);
	printf(", %c.\n", name[0]);

	return 0;
}