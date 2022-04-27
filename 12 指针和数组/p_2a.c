#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define N 100

int main(void)
{
	bool flag = true;
	char ch, message[N];
	int i = 0;

	printf("Enter a message: ");
	while ((ch = getchar()) != '\n' && i < N)
		if (isalpha(ch))
			message[i++] = tolower(ch);

	for (int j = 0; j < i / 2; j++)
		if (message[j] != message[i - j - 1])
			flag = false;
	if (flag)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}