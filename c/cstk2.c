/*
* Derek Hessinger
* Prof. Ying Li
* CS 333
* 10/14/24
*
* cstk2.c
*/

#include  "cstk2.h"
#include <stdio.h>
#include <stdlib.h>

/*Creates a stack*/
Stack *stk_create(int capacity){
    // create a stack pointer
    Stack *stk = (Stack*)malloc(sizeof(Stack));

    // init data pointer
    stk->data = (void *)malloc(sizeof(void*)*capacity);

    // init capacity
    stk->capacity = capacity;

    //init top
    stk->top = stk->data;

    return stk;
}

/*Destorys a stack*/
void stk_destroy(Stack *stk){
    if (stk != NULL) {
        free(stk->data);
        stk->data = NULL;
        stk->top = NULL;
        stk->capacity = 0;
        free(stk);
    }
}

/*Returns the size of the stack*/
int stk_size(Stack *stk){

    // subtract top and data mem addresses to get the size of the stk
    return stk->top-stk->data;
}

/*Pushes an element to the stack*/
void stk_push(Stack *stk, void *item){

    *(stk->top) = item;  // set top pointer to new num value
    stk->top++; // increment top to point to next empty slot
}

/*Returns the top element of a stack*/
void *stk_peek(Stack *stk){
    // first check if stk is empty
    if (stk->top == stk->data) {
        return NULL;
    }
    // return reference at top of stk
    return *(stk->top - 1);
}

/*Removes the top element of a stack and returns it*/
void *stk_pop(Stack *stk){

    void *pop_val = stk_peek(stk);
    stk->top--;
    return pop_val;
}

/*toString function that works with void pointers*/
char *stk_toString(Stack *stk, char *(*toString)(void *)) {

    // Calculate the number of items in the stack
    int itemCount = (int)(stk->top - stk->data);

    // Handle empty stack case
    if (itemCount == 0) {
        char *emptyStack = malloc(3); // return empty string "[]\0"
        if (emptyStack != NULL) {
            strcpy(emptyStack, "[]");
        }
        return emptyStack;
    }

    // Initial buffer size for the string
    size_t bufferSize = 64;
    char *result = malloc(bufferSize);
    if (result == NULL) {
        return NULL;
    }

    // Start with an opening bracket
    size_t currentLength = 0;
    result[currentLength++] = '[';

    for (int i = 0; i < itemCount; i++) {
        // Convert each element to a string using the provided toString function
        char *itemString = toString(stk->data[i]);
        if (itemString == NULL) {
            free(result);
            return NULL;
        }

        size_t itemLength = strlen(itemString);
        size_t requiredLength = currentLength + itemLength + 3; // For ", " or "]" and null terminator

        // Resize the result buffer if needed
        if (requiredLength > bufferSize) {
            bufferSize = (requiredLength > bufferSize * 2) ? requiredLength : bufferSize * 2;
            char *temp = realloc(result, bufferSize);
            if (temp == NULL) {
                free(result);
                free(itemString);
                return NULL;
            }
            result = temp;
        }

        // Copy the item string to the result
        strcpy(result + currentLength, itemString);
        currentLength += itemLength;

        // Add comma and space or the closing bracket
        if (i < itemCount - 1) {
            result[currentLength++] = ',';
            result[currentLength++] = ' ';
        } else {
            result[currentLength++] = ']';
        }

        free(itemString); // Free the string returned by toString
    }

    // Null-terminate the final string
    result[currentLength] = '\0';

    // Optionally shrink the buffer to the exact size needed
    char *finalResult = realloc(result, currentLength + 1);
    return finalResult ? finalResult : result;
}
