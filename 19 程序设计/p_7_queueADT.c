#include <stdio.h>
#include <stdlib.h>
#include "p_5_queueADT.h"

struct node
{
	Item data;
	struct node* next;
};

struct queue_type
{
	struct node* head;
	struct node* last;
	int items;
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

	q->items = 0;
	q->head = NULL;
	q->last = NULL;
	return q;
}

void append(Queue q, Item i)
{
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in append: node could not be append.");

	new_node->data = i;
	new_node->next = NULL;
	if (is_empty(q))
	{
		q->head = new_node;
		q->last = new_node;
	}
	else
	{
		q->last->next = new_node;
		q->last = new_node;
	}
	q->items++;
	
}

void outqueue(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	struct node* old_node = q->head;
	q->head = old_node->next;
	q->items--;
	if (q->head == q->last)
		q->last = NULL;
	free(old_node);
}

Item head(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	return  q->head->data;
}

Item tail(Queue q)
{
	if (is_empty(q))
		terminate("Error in pop: queue is empty.");

	return q->last->data;
}

bool is_empty(Queue q)
{
	return q->items == 0;
}

void destroy(Queue q)
{
	while (!is_empty(q))
		outqueue(q);
	free(q);
}