#include <stdio.h>
#include <stdlib.h>
#include "p_5_queueADT.h"

struct queue_type
{
	Item* contents;
	int items;
	int empty_index;
	int removal_index;
	int size;
};

static void terminate(const char* message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");

	q->contents = malloc(size * sizeof(Item));
	if (q->contents == NULL)
		terminate("Error in create: queue could not be created.");

	q->items = 0;
	q->empty_index = 0;
	q->removal_index = 0;
	q->size = size;
	return q;
}

void append(Queue q, Item i)
{
	if (q->items == q->size)
		terminate("Error in pop: queue is full.");

	q->contents[q->empty_index] = i;
	q->empty_index == q->size - 1 ? q->empty_index = 0 : q->empty_index++;
	q->items++;
}

void outqueue(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	q->removal_index == q->size - 1 ? q->removal_index = 0 : q->removal_index++;
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
		return q->contents[q->size - 1];
	else
		return q->contents[q->empty_index - 1];
}

bool is_empty(Queue q)
{
	return q->items == 0;
}

void destroy(Queue q)
{
	free(q->contents);
	free(q);
}