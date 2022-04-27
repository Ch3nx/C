#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char ch = ' ';
    unsigned char buffer[10];
    int i, n;
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

    printf("Offset               Bytes               Characters\n"
           "------   -----------------------------   ----------\n");

    for (int offset = 0; ch != EOF; offset += 10)
    {
        n = fread(buffer, sizeof(buffer[0]), 10, fp);
        if (n == 0)
            break;

        printf("%6d  ", offset);
        for (i = 0; i < 10; i++)
                printf(" %.2X", buffer[i]);
        for (; i < 10; i++)
            printf("   ");
        printf("   ");
        for (int i = 0; i < n; i++)
        {
            if (isprint(buffer[i]))
                printf("%c", buffer[i]);
            else
                printf(".");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}