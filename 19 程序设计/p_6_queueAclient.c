#include <stdio.h>
#include "p_5_queueADT.h"

int main(void)
{
	Queue q1, q2;
	int n;

	q1 = create(2);
	q2 = create(2);

	append(q1, 1);
	append(q1, 2);

	n = head(q1);
	outqueue(q1);
	printf("Removed %d from q1\n", n);
	append(q2, n);
	n = head(q1);
	outqueue(q1);
	printf("Removed %d from q1\n", n);
	append(q2, n);
	destroy(q1);

	while (!is_empty(q2))
	{
		printf("Removed %d from s2\n", head(q2));
		outqueue(q2);
	}

	append(q2, 3);
	if (is_empty(q2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");

	destroy(q2);

	return 0;
}