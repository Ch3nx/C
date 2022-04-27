#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char ch, area[4], local[4], exact[5];
    int len = 0;
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

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isdigit(ch))
        {
            if (len < 3)
            {
                area[len++] = ch;
                if (len == 3)
                    area[len] = '\0';
                continue;
            }
            else if (len >= 3 && len < 6)
            {
                local[len++ - 3] = ch;
                if (len == 6)
                    local[len - 3] = '\0';
                continue;
            }
            else
            {
                exact[len++ - 6] = ch;
                if (len == 10)
                {
                    exact[len - 6] = '\0';
                    printf("(%s) %s-%s\n", area, local, exact);
                    len = 0;
                }
                continue;
            }
        }
    }

    return 0;
}