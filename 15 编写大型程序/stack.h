#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);

#endif