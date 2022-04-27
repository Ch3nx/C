#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned char byte, count;
    long int pos;
    char *filename;
    FILE *compress, *uncompress;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: filename\n");
        exit(EXIT_FAILURE);
    }
    if (strstr(argv[1], ".rle") == NULL)
    {
        fprintf(stderr, "Usage: %s compressed-file.rle\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((compress = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    filename = malloc(strlen(argv[1]) - 3);
    strncpy(filename, argv[1], strlen(argv[1]) - 4);
    filename[strlen(argv[1]) - 4] = '\0';
    if ((uncompress = fopen(filename, "wb")) == NULL)
    {
        printf("%s can't be written\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fread(&count, sizeof(unsigned char), 1, compress))
    {
        fread(&byte, sizeof(unsigned char), 1, compress);
        printf(":%d:%c:\n", count, byte);
        for (int i = 0; i < count; i++)
            fwrite(&byte, sizeof(unsigned char), 1, uncompress);
    }

    fclose(compress);
    fclose(uncompress);
    return 0;
}