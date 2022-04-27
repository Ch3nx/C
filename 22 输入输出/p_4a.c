#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int chars = 0;
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

    while (getc(fp) != EOF)
        chars++;

    printf("There are %d characters in %s\n", chars, argv[1]);

    fclose(fp);
    return 0;
}