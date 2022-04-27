#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 255

int main(int argc, char *argv[])
{
    char filename[NAME_LEN], *in_file, *out_file, ch;
    int shift, i = 0;
    FILE *in_fp, *out_fp;

    printf("Enter name of file to be encrypted: ");
    scanf("%s", filename);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    in_file = malloc(strlen(filename) + 1);
    strcpy(in_file, filename);
    if ((in_fp = fopen(in_file, "r")) == NULL)
    {
        fprintf(stderr, "%s can't be opened\n", in_file);
        exit(EXIT_FAILURE);
    }
    out_file = malloc(strlen(filename) + 5);
    strcat(strcpy(out_file, in_file), ".enc");
    if ((out_fp = fopen(out_file, "w")) == NULL)
    {
        fprintf(stderr, "%s can't be written\n", out_file);
        exit(EXIT_FAILURE);
    }


    while ((ch = fgetc(in_fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            fputc((ch - 'a' + shift) % 26 + 'a', out_fp);
        else if (ch >= 'A' && ch <= 'Z')
            fputc((ch - 'A' + shift) % 26 + 'A', out_fp);
        else
            fputc(ch, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}