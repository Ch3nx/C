#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int year, month, day;
    const char *months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s date; where date is in the form mm-dd-yyyy or as mm/dd/yyyy\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[1], "%d%*[-/]%d%*[-/]%d", &month, &day, &year);
    printf("%s %d, %d\n", months[month - 1], day, year);

    return 0;
}