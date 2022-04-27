#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

int compare_ints(const void *p, const void *q);

int main(int argc, char *argv[])
{
    int count = 0, median, numbers[MAX_NUM];
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (count <= MAX_NUM && fscanf(fp, "%d", &numbers[count++]) != EOF);
    count--;
    qsort(numbers, count, sizeof(int), compare_ints);
    if (count % 2 == 0)
        median = (numbers[(count - 1) / 2] + numbers[(count - 1) / 2 + 1]) / 2;
    else
        median = numbers[(count - 1) / 2];

    printf("Max: %d\nMedian: %d\nMin: %d\n", numbers[count - 1], median, numbers[0]);

    fclose(fp);
    return 0;
}

int compare_ints(const void *p, const void *q)
{
    return *((int *)p) - *((int *)q);
}