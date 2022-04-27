#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
	bool same;
	int fst_word[26] = { 0 }, scd_word[26] = { 0 };

	read_word(fst_word);
	read_word(scd_word);

	same = equal_array(fst_word, scd_word);

	if (same)
		printf("The word are anagrams.\n");
	else
		printf("The word are not anagrams.\n");
	
	return 0;
}

void read_word(int counts[26])
{
	char word;

	printf("Enter word: ");
	while ((word = getchar()) != '\n')
		if (isalpha(word))
			counts[tolower(word) - 'a']++;
}

bool equal_array(int counts1[26], int counts2[26])
{
	for (int i = 0; i < 26; i++)
		if (counts1[i] != counts2[i])
			return false;

	return true;
}