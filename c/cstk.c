/*
* Derek Hessinger
* Prof. Ying Li
* CS 333
* 10/14/24
*
* cstk.c
*/

#include  "cstk.h"
#include <stdio.h>
#include <stdlib.h>

/*Creates a stack*/
Stack *stk_create(int num){

    Stack *stk  = (Stack*)malloc(sizeof(Stack));

    // error check for empty stack
    if (stk == NULL) {
        return NULL;
    }

    stk->data = (int *)malloc(sizeof(int)*num);
    
    // error check for no num
    if (stk->data == NULL) {
        free(stk);
        return NULL;
    }

    stk->capacity = num;
    stk->top = stk->data;

    return stk;
}
/*Returns if a stack is empty or not*/
int stk_empty(Stack *stk){
    return stk->top-stk->data==0;
}

/*Checks if a stack is full*/
int stk_full(Stack *stk){

    // subtract top and data mem addresses to see if stack is full
    return stk->top-stk->data>=stk->capacity;
}

/*Pushes a value to the stack*/
void stk_push(Stack *stk, int num){

    if (stk_full(stk) == 0){
        *(stk->top) = num;  // set top pointer to new num value
        stk->top++; // increment top to point to next empty slot
    }
    else{
        #warning The stack space is full, cannot push to stack
    }
}

/*Returns the top element of the stack*/
int stk_peek(Stack *stk){
    if (stk_empty(stk)){
        #warning The stack is empty, returning 0
        return 0;
    }
    else{
        // return dereferrenced top pointer value
        int top = *(stk->top-1);
        return top;
    }
}

/*Removes the top element from the stack and returns it*/
int stk_pop(Stack *stk){
    if (stk_empty(stk)){
        #warning The stack is empty, returning 0
        return 0;
    }
    else{
        // get top val, decrement top pointer to one below, return popped val
        // come back and check if memory space needs to be freed
        int pop_val = stk_peek(stk);
        stk->top--;
        return pop_val;
    }
}

/*Displays all elements in the stack in both FIFO and LIFO*/
void stk_display(Stack *stk, int num){
    // if 1, create separate pointer at top, and count down while printing out
    if (num==1){ // LIFO order
        for (int *ptr = stk->top - 1; ptr >= stk->data; ptr--) {
            printf("%d ", *ptr);
        }
    } 
    // if 0, create separate pointer at data, and count down while printing out
    else {  // LILO order
        for (int *ptr = stk->data; ptr < stk->top; ptr++) {
            printf("%d ", *ptr);
        }
    }
}

/*Destroys the stack*/
void stk_destroy(Stack *stk){
    if (stk != NULL) {
        free(stk->data);
        stk->data = NULL;
        stk->top = NULL;
        stk->capacity = 0;
        free(stk);
    }
}

/*Returns a copy of the stack*/
Stack *stk_copy(Stack *stk){
    Stack *new_stk = stk_create(stk->capacity);
    for (int *ptr = stk->data; ptr < stk->top; ptr++) {
            stk_push(new_stk, *ptr);
        }
    return new_stk;
}
