#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num, month, day, year;
    float price;
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("\nItem\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    while (fscanf(fp, "%d,%f,%d/%d/%d", &num, &price, &month, &day, &year) != EOF)
        printf("%-d\t\t$%7.2f\t%-d/%-.2d/%-.2d\n", num, price, month, day, year);

    fclose(fp);
    return 0;
}