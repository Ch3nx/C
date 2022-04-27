#include <stdio.h>

#define N 10

void max_min(int a[], int* max, int* min);

int main(void)
{
	int big, small, b[N];

	printf("Enter %d numbers: ", N);
	for (int i = 0; i < N; i++)
		scanf("%d", &b[i]);

	max_min(b, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int a[], int* max, int* min)
{
	*max = *min = a[0];
	for (int* i = a + 1; i < a + N; i++)
		if (*i > *max)
			*max = *i;
		else if (*i < *min)
			*min = *i;
}