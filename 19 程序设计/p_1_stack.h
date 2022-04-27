#ifndef p_1_STACK_H
#define p_1_STACK_H

#include <stdbool.h>

typedef struct stack_p_1* Stack;

Stack create(void);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, char i);
void pop(Stack s, char i);

#endif