#include <stdio.h>
int main(void)
{
	//C99
	printf("%zu\n", sizeof(int));
	printf("%zu\n", sizeof(short));
	printf("%zu\n", sizeof(float));
	printf("%zu\n", sizeof(double));
	printf("%zu\n", sizeof(long double));

	/*C89
	* printf("%d\n", (int)sizeof(int));
	* printf("%d\n", (int)sizeof(short));
	* printf("%d\n", (int)sizeof(float));
	* printf("%d\n", (int)sizeof(double));
	* printf("%d\n", (int)sizeof(long double));
	*/

	return 0;
}