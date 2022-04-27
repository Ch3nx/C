#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf("%s can't be opened\n", argv[i]);
                exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

    return 0;
}