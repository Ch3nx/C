#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r+")) == NULL)
    {
        fprintf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF)
            putchar(toupper(ch)); 

    fclose(fp);
    return 0;
}