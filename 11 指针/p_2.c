#include <stdio.h>

void find_closest_flight(int desired_time, int* departure_time, int* arrival_time);

int d1 = 480, a1 = 616,
	d2 = 583, a2 = 712,
	d3 = 679, a3 = 811,
	d4 = 767, a4 = 900,
	d5 = 840, a5 = 968,
	d6 = 945, a6 = 1075,
	d7 = 1140, a7 = 1280,
	d8 = 1305, a8 = 1438;


int main(void)
{
	int hour, minute, time, departure_time, arrival_time;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	time = hour * 60 + minute;
	find_closest_flight(time, &departure_time, &arrival_time);
	printf("Closest departure time is %d:%d %c.m., arriving at %d:%d %c.m.\n",
		departure_time / 60 <= 12 ? departure_time / 60 : departure_time / 60- 12,
		departure_time % 60, departure_time < 60 ? 'a' : 'p',
		arrival_time / 60 <= 12 ? arrival_time / 60 : arrival_time / 60 - 12,
		arrival_time % 60, arrival_time < 12 ? 'a' : 'p');

	return 0;
}
void find_closest_flight(int desired_time, int* departure_time, int* arrival_time)
{
	if (desired_time <= (d1 + d2) / 2.0f)
	{
		*departure_time = d1;
		*arrival_time = a1;
	}
	else if (desired_time <= (d2 + d3) / 2.0f)
	{
		*departure_time = d2;
		*arrival_time = a2;
	}
	else if (desired_time <= (d3 + d4) / 2.0f)
	{
		*departure_time = d3;
		*arrival_time = a3;
	}
	else if (desired_time <= (d4 + d5) / 2.0f)
	{
		*departure_time = d4;
		*arrival_time = a4;
	}
	else if (desired_time <= (d5 + d6) / 2.0f)
	{
		*departure_time = d5;
		*arrival_time = a5;
	}
	else if (desired_time <= (d6 + d7) / 2.0f)
	{
		*departure_time = d6;
		*arrival_time = a6;
	}
	else if (desired_time <= (d7 + d8) / 2.0f)
	{
		*departure_time = d7;
		*arrival_time = a7;
	}
	else
	{
		*departure_time = d8;
		*arrival_time = a8;
	}
}