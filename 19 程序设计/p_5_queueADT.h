#ifndef P_5_QUEUE_H
#define P_5_QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type* Queue;

Queue create(void);
void append(Queue q, Item i);
void outqueue(Queue q);
Item head(Queue q);
Item tail(Queue q);
bool is_empty(Queue q);
void destroy(Queue q);

#endif