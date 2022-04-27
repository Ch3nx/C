#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char ch;
    FILE *in_fp, *out_fp;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((in_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf("%s can't be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(in_fp)) != EOF)
    {
        if (ch != '\x0d' && ch != '\x1a')
            fputc(ch, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}