#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int hour, minute, time, t1 = 480, t2 = 583, t3 = 679, t4 = 767, t5 = 840, t6 = 945, t7 = 1140, t8 = 1305;
	char ch, temp;
	int i = 0;

	printf("Enter a 12-hour time: ");
	scanf("%d:%d %c", &hour, &minute, &ch);

	
	/*if ((ch == 'a' || ch == 'A') || ((ch == 'p' || ch == 'P') && hour == '12'))
		time = hour * 60 + minute;
	else
		time = (hour + 12) * 60 + minute;*/
	time = ((toupper(ch) == 'P' ? hour == 12 ? 0 : 12 : 0) + hour) * 60 + minute;
	printf("Closest departure time is ");
	if (time <= (t1 + t2) / 2.0f)
		printf("8:00 a.m., arriving at 10:16 a.m.\n");
	else if (time <= (t2 + t3) / 2.0f)
		printf("9:43 a.m., arriving at 11:52 a.m.\n");
	else if (time <= (t3 + t4) / 2.0f)
		printf("11:19 a.m., arriving at 1:31 p.m.\n");
	else if (time <= (t4 + t5) / 2.0f)
		printf("12:47 p.m., arriving at 3:00 p.m.\n");
	else if (time <= (t5 + t6) / 2.0f)
		printf("2:00 p.m., arriving at 4:08 p.m.\n");
	else if (time <= (t6 + t7) / 2.0f)
		printf("3:45 p.m., arriving at 5:55 p.m.\n");
	else if (time <= (t7 + t8) / 2.0f)
		printf("7:00 p.m., arriving at 9:20 p.m.\n");
	else
		printf("9:45 p.m., arriving at 11:58 p.m.\n");

	return 0;
}