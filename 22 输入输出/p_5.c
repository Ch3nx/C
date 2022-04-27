#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    int orig_char, new_char;
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

    while ((orig_char = getc(fp)) != EOF)
        putchar(orig_char ^ KEY);

    return 0;
}