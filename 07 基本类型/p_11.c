#include <stdio.h>
int main(void)
{
	char first_name, last_name, temp;
	int i = 0;

	printf("Enter a first and last name: ");
	
	while ((first_name = getchar()) == ' ');
	while ((temp = getchar()) != ' ');
	while ((last_name = getchar()) == ' ');
	putchar(last_name);
	while ((last_name = getchar()) != '\n')
		putchar(last_name);
	printf(", %c.\n", first_name);

	return 0;
}