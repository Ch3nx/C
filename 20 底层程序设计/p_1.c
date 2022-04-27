#include <stdio.h>

union {
	float value1;
	struct {
		unsigned int fraction : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} value2;
} f;

int main(void)
{
	f.value2.fraction = 0;
	f.value2.exponent = 128;
	f.value2.sign = 1;

	printf("%f\n", f.value1);

	return 0;
}