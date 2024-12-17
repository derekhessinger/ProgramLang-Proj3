#include "cstk2.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Account {
    char *name;
    int balance;
} Account;

int main() {
  
    Stack *stack = stk_create(10);

    for (int i = 0; i < 5; i++) {
        int *x = (int *)malloc(sizeof(int));
        *x = i;
        stk_push(stack, x);

        //print addr of the pointers and where it points in the heap
        printf("stack[%d] is at address: %p, points to: %p (value: %d)\n",  i, (void *)&stack->data[i], (void *)x, *x);
    }

    Account account = {"Max Bender", 10};
    stk_push(stack, &account);

    //print the addr of account pointer
    printf("stack[5] is at address: %p, points to: %p (Account)\n", (void *)&stack->data[5], (void *)&account);

    printf("Account.name points to: %p, name: %s, balance: %d\n", (void *)account.name, account.name, account.balance);

    // MARK 1 - current memory state of the stack and heap
    return 0;
}
