#include <stdio.h>

#define PI 3.14
#define SCALE_FACTOR (4.0f / 3.0f)

int main(void)
{
	int raduis;
	float volume;

	printf("Enter radius: ");
	scanf("%d", &raduis);
	volume = SCALE_FACTOR * PI * raduis * raduis * raduis;

	printf("Sphere volume: %f cubic meters\n", volume);

	return 0;
}