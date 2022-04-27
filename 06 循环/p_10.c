#include <stdio.h>
int main(void)
{
	int month, day, year, min_month, min_day, min_year;

	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &min_month, &min_day, &min_year);
	for (;;)
	{
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d", &month, &day, &year);
		if ((month == 0 && day == 0 && year == 0) ||
			(min_month == 0 && min_day == 0 && min_year == 0))
			break;
		if (year < min_year ||
			(year == min_year && month < min_month) ||
			(year == min_year && month == min_month && day < min_day))
		{
			min_month = month;
			min_day = day;
			min_year = year;
		}
	}

	printf("%d/%d/%.2d is the earliest date\n", min_month, min_day, min_year);

	return 0;
}