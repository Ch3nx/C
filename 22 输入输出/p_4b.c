#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    bool flag = false;
    char ch;
    int words = 0;
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

    while ((ch = getc(fp)) != EOF)
    {
        if (isspace(ch))
            flag = false;
        else
        {
            if (!flag)
            {
                flag = true;
                words++;
            }
        }
    }
    printf("There are %d words in %s\n", words, argv[1]);

    fclose(fp);
    return 0;
}