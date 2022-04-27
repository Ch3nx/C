#include <stdio.h>
int main(void)
{
	char dep_m, arr_m;
	int hour, minute, time, dep_hour, dep_minute, arr_hour, arr_minute,
		dep_time[8] = { 480, 583, 679, 767, 840, 945, 1140, 1305 },
		arr_time[8] = { 616, 712, 811, 900, 968, 1075, 1280, 1438 };

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	time = hour * 60 + minute;
	printf("Closest departure time is ");
	for (int i = 0; i < 7; i++)
	{
		if (time <= (dep_time[i] + dep_time[i + 1]) / 2.0f)
		{
			dep_hour = time[i].departure / 60;
			dep_minute = time[i].departure % 60;
			arr_hour = time[i].arrival / 60;
			arr_minute = time[i].arrival % 60;
			dep_m = dep_hour < 12 ? 'a' : 'p';
			arr_m = arr_hour < 12 ? 'a' : 'p';
			dep_hour = dep_hour <= 12 ? dep_hour : dep_hour - 12;
			arr_hour = arr_hour <= 12 ? arr_hour : arr_hour - 12;
			break;
		}
	}
	printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
		dep_hour, dep_minute, dep_m, arr_hour, arr_minute, arr_m);

	return 0;
}