#include <stdio.h>

int main(void)
{
	char message[80];
	int shift, i = 0;

	printf("Enter message to be encrypted: ");
	while ((message[i++] = getchar()) != '\n');
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	
	printf("Encrypted massage: ");
	for (int j = 0; j < i; j++)
	{
		if (message[j] >= 'a' && message[j] <= 'z')
			putchar((message[j] - 'a' + shift) % 26 + 'a');
		else if (message[j] >= 'A' && message[j] <= 'Z')
			putchar((message[j] - 'A' + shift) % 26 + 'A');
		else
			putchar(message[j]);
	}

	return 0;
}