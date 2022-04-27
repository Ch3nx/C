#include <stdio.h>
#include <stdlib.h>
#include "p_5_queueADT.h"

#define QUEUE_SIZE 100

struct queue_type
{
	Item contents[QUEUE_SIZE];
	int items;
	int empty_index;
	int removal_index;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");

	q->items = 0;
	q->empty_index = 0;
	q->removal_index = 0;
	return q;
}

void append(Queue q, Item i)
{
	if (q->items == QUEUE_SIZE)
		terminate("Error in pop: queue is full.");

	q->contents[q->empty_index] = i;
	q->empty_index == QUEUE_SIZE - 1 ? q->empty_index = 0 : q->empty_index++;
	q->items++;
}

void outqueue(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	q->removal_index == QUEUE_SIZE - 1 ? q->removal_index = 0 : q->removal_index++;
	q->items--;
}

Item head(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	return q->contents[q->removal_index];
}

Item tail(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	if (q->empty_index == 0)
		return q->contents[QUEUE_SIZE - 1];
	else
		return q->contents[q->empty_index - 1];
}

bool is_empty(Queue q)
{
	return q->items == 0;
}

void destroy(Queue q)
{
	free(q);
}