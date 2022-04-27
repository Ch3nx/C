#include <stdio.h>

struct flight
{
	int departure;
	int arrival;
} time[] = {
	{480, 616}, {583, 712}, { 679, 811},  {767, 900},
	{840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}
};

int main(void)
{
	char dep_m, arr_m;
	int i, hour, minute, user_time, dep_hour, dep_minute, arr_hour, arr_minute;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	user_time = hour * 60 + minute;
	printf("Closest departure time is ");
	for (i = 0; i < 7; i++)
		if (user_time <= (time[i].departure + time[i + 1].departure) / 2.0f)
			break;
	
	dep_hour = time[i].departure / 60;
	dep_minute = time[i].departure % 60;
	arr_hour = time[i].arrival / 60;
	arr_minute = time[i].arrival % 60;
	dep_m = dep_hour < 12 ? 'a' : 'p';
	arr_m = arr_hour < 12 ? 'a' : 'p';
	dep_hour = dep_hour <= 12 ? dep_hour : dep_hour - 12;
	arr_hour = arr_hour <= 12 ? arr_hour : arr_hour - 12;

	printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
		dep_hour, dep_minute, dep_m, arr_hour, arr_minute, arr_m);
	return 0;
}