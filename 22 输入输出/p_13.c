#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int hour, minute, time, f_hour, f_minute, minutes[8], i = 0;
    FILE *fp;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

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

    while (fscanf(fp, "%d:%d %*d:%*d", &f_hour, &f_minute) != EOF)
        minutes[i++] = f_hour * 60 + f_minute;

    time = hour * 60 + minute;
    printf("Closest departure time is ");
    if (time <= (minutes[0] + minutes[1]) / 2.0f)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (time <= (minutes[1] + minutes[2]) / 2.0f)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (time <= (minutes[2] + minutes[3]) / 2.0f)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (time <= (minutes[3] + minutes[4]) / 2.0f)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (time <= (minutes[4] + minutes[5]) / 2.0f)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (time <= (minutes[5] + minutes[6]) / 2.0f)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (time <= (minutes[6] + minutes[7]) / 2.0f)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");

    fclose(fp);
    return 0;
}