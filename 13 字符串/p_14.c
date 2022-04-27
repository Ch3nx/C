#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 80

bool are_anagrams(const char* word1, const char* word2);

int main(void)
{
	bool same;
	char word1[MAX_LEN + 1], word2[MAX_LEN + 1];

	printf("Enter first word: ");
	scanf("%s", word1);
	printf("Enter second word: ");
	scanf("%s", word2);
	
	same = are_anagrams(word1, word2);

	if (same)
		printf("The word are anagrams.\n");
	else
		printf("The word are not anagrams.\n");
}

bool are_anagrams(const char* word1, const char* word2)
{
	int fstscd[26] = { 0 };

	while (*word1 != '\0')
		if (isalpha(*word1))
			fstscd[tolower(*word1++) - 'a']++;
	while (*word2 != '\0')
		if (isalpha(*word2))
			fstscd[tolower(*word2++) - 'a']--;
	for (int i = 0; i < 26; i++)
		if (fstscd[i] != 0)
			return false;
	return true;
}
