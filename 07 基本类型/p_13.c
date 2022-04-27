#include <stdio.h>
int main(void)
{
	char ch;
	int num = 1;
	float aver = .0f;

	printf("Enter a sentence: ");

	while ((ch = getchar()) != '\n')
	{
		if ((ch == ' '))
			num++;
		else
			aver++;
	}
	
	printf("Average word length: %.1f\n", aver / num);

	return 0;
}