#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_15b.h"
#include "p_15c.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
    char word[MAX_WORD_LEN + 2];
    int word_len;
    FILE *in_fp, *out_fp;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((in_fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((out_fp = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "%s can't be written\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    clear_line();
    for (;;)
    {
        read_word(word, MAX_WORD_LEN + 1, in_fp);
        word_len = strlen(word);
        if (word_len == 0)
        {
            flush_line(out_fp);
            return 0;
        }
        if (word_len + 1 > space_remaining())
        {
            write_line(out_fp);
            clear_line();
        }
        add_word(word);
    }

    fclose(in_fp);
    fclose(out_fp);
}