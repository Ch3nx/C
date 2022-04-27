#include <stdio.h>

#define MAX_SIZE 100

void selection_sort(int num[], int n);

int main(void)
{
    char ch;
    int num[MAX_SIZE], i = 0;

    printf("Enter list of integers to be sorted: ");
    do {
        scanf("%d", &num[i++]);
    } while ((ch = getchar()) != '\n' && i <= MAX_SIZE);

    selection_sort(num, i);

    printf("Sorted list:");
    for (int j = 0; j < i; j++)
        printf(" %d", num[j]);
    printf("\n");
    
    return 0;
}

void selection_sort(int num[], int n)
{
    int temp, sub = 0;

    if (n == 0)
        return;

    for (int i = 1; i < n; i++)
        if (num[sub] < num[i])
            sub = i;

    temp = num[sub];
    num[sub] = num[n - 1];
    num[n - 1] = temp;

    selection_sort(num, n - 1);
}