/*
* Derek Hessinger
* Prof. Ying Li
* CS 333
* 10/11/24
*/

#ifndef cstk_h
#define cstk_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack 
{
	int *data; // this is a pointer to the start of the data for the stack
	int *top; // this will point to the next place to insert in the stack
	int capacity; // this is the maximal size of the stack
} Stack;

Stack *stk_create(int); // creates a Stack with a maximal capacity specified by the int value

int stk_empty(Stack *); // returns 1 if the given Stack is empty, otherwise 0.

int stk_full(Stack *); // returns 1 if the given Stack is full, otherwise 0.

void stk_push(Stack *, int); // adds a new value to the top of the stack if there's space. 
                             // If there's no space, prints out a warning but does nothing (and doesn't crash).

int stk_peek(Stack *); // returns the value on the top of the stack if such a value exists. Otherwise, prints out a warning and returns 0.

int stk_pop(Stack *); // removes and returns the value on the top of the stack if such a value exists. Otherwise, prints out a warning and returns 0.

void stk_display(Stack *, int); // prints out the list in the reverse order (LILO) if the int value is 1, otherwise, prints out in the original order (LIFO).

void stk_destroy (Stack *); // frees up the memory 

Stack *stk_copy(Stack *); // copies the contents into another Stack of the same maximal size and returns it.

#endif