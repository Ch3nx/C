#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned char byte, next_byte;
    int count;
    long int pos;
    char *filename;
    FILE *uncompress, *compress;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if ((uncompress = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    filename = malloc(strlen(argv[1]) + 5);
    strcat(strcpy(filename, argv[1]), ".rle");
    if ((compress = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "%s can't be written\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fread(&byte, sizeof(unsigned char), 1, uncompress))
    {
        count = 1;
        pos = ftell(uncompress);
        while (fread(&next_byte, sizeof(unsigned char), 1, uncompress) && byte == next_byte)
            count++;
        fwrite(&count, sizeof(unsigned char), 1, compress);
        fwrite(&byte, sizeof(unsigned char), 1, compress);
        fseek(uncompress, pos + count - 1, SEEK_SET);
    }

    fclose(uncompress);
    fclose(compress);
    return 0;
}