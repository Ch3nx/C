#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int hour, minute;
	char ch;

	printf("Enter a 12-hour time: ");
	scanf("%d:%d %c", &hour, &minute, &ch);

	hour += toupper(ch) == 'P' ? hour == 12 ? 0 : 12 : 0;
	printf("Equivalent 24-hour time: %.2d:%.2d\n", hour, minute);

	return 0;
}