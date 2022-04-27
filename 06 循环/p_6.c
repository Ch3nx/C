#include <stdio.h>
int main(void)
{
	int num, i = 1;

	printf("Enter limit n maximum square: ");
	scanf("%d", &num);

	while (i * i <= num)
	{
		if (i % 2 == 0)
			printf("%d\n", i * i);
		i++;
	}
	/*for (int i = 2; i * i <= num; i += 2)
		printf("%d\n", i * i);*/

	return 0;
}