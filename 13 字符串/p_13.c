#include <stdio.h>

#define MAX_LEN 80

void encrypt(char* message, int shift);

int main(void)
{
	char message[MAX_LEN + 1];
	int shift, i = 0;

	printf("Enter message to be encrypted: ");
	gets(message);
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	printf("Encrypted massage: ");
	encrypt(message, shift);

	return 0;
}

void encrypt(char* message, int shift)
{
	for (int j = 0; message[j] != '\0'; j++)
	{
		if (message[j] >= 'a' && message[j] <= 'z')
			putchar((message[j] - 'a' + shift) % 26 + 'a');
		else if (message[j] >= 'A' && message[j] <= 'Z')
			putchar((message[j] - 'A' + shift) % 26 + 'A');
		else
			putchar(message[j]);
	}
	printf("\n");
}