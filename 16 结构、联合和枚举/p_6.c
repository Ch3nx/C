#include <stdio.h>

struct date
{
	int month, day, year;
};

int compare_date(struct date d1, struct date d2);

int main(void)
{
	int comparison;
	struct date d1, d2;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

	comparison = compare_date(d1, d2);
	if (comparison == -1)
		printf("%d/%d/%.2d is ealier than %d/%d/%.2d\n",
			d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
	else if (comparison == 1)
		printf("%d/%d/%.2d is ealier than %d/%d/%.2d\n",
			d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
	else
		printf("%d/%d/%d and %d/%d/%d are equal\n",
			d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);

	return 0;
}

int compare_date(struct date d1, struct date d2)
{
	if (d1.year > d2.year)
		return 1;
	else if (d1.year < d2.year)
		return -1;
	else if (d1.month > d2.month)
		return 1;
	else if (d1.month < d2.month)
		return -1;
	else if (d1.day > d2.day)
		return 1;
	else if (d1.day < d2.day)
		return -1;
	else
		return 0;
}