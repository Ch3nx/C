#ifndef P_2_STACK_H
#define P_2_STACK_H

#include <stdbool.h>

typedef struct stack_p_2* Stack;

Stack create(int size);
void destroy(Stack s);
void make_empty(void);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, char i);
char pop(Stack s);

#endif