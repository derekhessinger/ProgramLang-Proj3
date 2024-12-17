/**
 * Test code for Stack 
 *
 * Ying Li
 * edits by Derek Hessinger
 * 08/01/2016
 */


#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>

#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    Stack *s = stk_create(20); 
    
    int i;
    for (i = 0; i < 10; i++) {
        stk_push(s, i+1); 
    }
    
    /// Mark 1 (first memory picture)
    printf("\nmark1:\n");
    printf("Addr of Stack: %p\n", (void*)&s);        
    printf("Addr of Stack's data array: %p\n", (void*)s->data); 
    printf("Addr of loop control var: %p\n", (void*)&i); 


    printf("\n Original list: ");
    stk_display(s, 0); 
    
    printf("Reversed list: ");
    stk_display(s, 1); 
    
 
    stk_destroy(s);

    // Mark 2 (after stack destruction)
    printf("\nmark2:\n");
    printf("stack still points to: %p but memory has been freed\n", (void*)s);
    
    return 0;
}