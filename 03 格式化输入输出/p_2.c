#include <stdio.h>
int main(void)
{
	int num, month, day, year;
	float price;

	printf("Enter item number: ");
	scanf("%d", &num);
	printf("Enter unit price: ");
	scanf("%f", &price);
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("\nItem\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");
	printf("%-d\t\t$%7.2f\t%-d/%-.2d/%-.2d\n", num, price, month, day, year);

	return 0;
}