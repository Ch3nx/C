#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char word;
	int same = 1, fstscd[26] = { 0 };

	printf("Enter first word: ");
	while ((word = getchar()) != '\n')
		if (isalpha(word))
			fstscd[tolower(word) - 'a']++;
	printf("Enter second word: ");
	while ((word = getchar()) != '\n')
		if (isalpha(word))
			fstscd[tolower(word) - 'a']--;

	for (int i = 0; i < 26; i++)
		if (fstscd[i] != 0)
		{
			same = 0;
			break;
		}

	if (same)
		printf("The word are anagrams.\n");
	else
		printf("The word are not anagrams.\n");
}