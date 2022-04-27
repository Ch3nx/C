#include <stdio.h>
int main(void)
{
	float shares, share_price, commission, value, rival;

	printf("Enter number of shares: ");
	scanf("%f", &shares);
	printf("Enter price per share: ");
	scanf("%f", &share_price);

	value = shares * share_price;
	if (value < 2500.0f)
		commission = 30.0f + .017f * value;
	else if (value < 6250.0f)
		commission = 56.0f + .0066f * value;
	else if (value < 20000.0f)
		commission = 76.0f + .0034f * value;
	else if (value < 50000.0f)
		commission = 100.0f + .0022f * value;
	else if (value < 500000.0f)
		commission = 155.0f + .0011f * value;
	else
		commission = 255.0f + .0009f * value;
	if (commission < 39.0f)
		commission = 39.0f;
	if (shares < 2000.0f)
		rival = 33.00f + .03f * shares;
	else
		rival = 33.00f + .02f * shares;

	printf("Commission: $%.2f\n", commission);
	printf("Rival commission: $%.2f\n", rival);

	return 0;
}