#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int main(void)
{
	char message[MAX_SIZE];
	int n = 0;

	printf("Enter message: ");
    while ((message[n++] = getchar()) != '\n' && n < MAX_SIZE);

	for (int i = 0; i < n; i++)
	{
		switch (toupper(message[i]))
		{
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(toupper(message[i]));
                break;
		}
	}
    printf("!!!!!!!!!!\n");

	return 0;
}