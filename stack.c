/*
 * stack.c
 *
 * Created on: February 9, 2022
 * Author: Alysa Vermeulen
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

/**
 * Returns the number of elements currently on the stack
 * @param stack Pointer to the stack
 * @return Number of elements currently on the stack
 */
int size(Stack *stack){
    if (stack->top == NULL){
        return 0;
    }
    else{
        Element *currentElement = stack->top;
        int num = 0;
        while (currentElement != NULL){
            num++;
            currentElement = currentElement->next;
        }
        return num;
    }
}

/**
 * Given a token, allocates a new stack element and pushes it onto the top of the stack
 * @param stack Pointer to the stack
 * @param token	New operand to be added to the stack
 */
void push(Stack *stack, double token){
    // create and initialize new stack element
    Element *newElement = (Element*) malloc(sizeof(Element));
    newElement->val = token;
    newElement->next = NULL;
    // push element onto top of stack
    if (stack->top == NULL){
        stack->top = newElement;
    }
    else{
        newElement->next = stack->top;
        stack->top = newElement;
    }
}

/**
 * Pops off the top element from the stack, returns the stored double value, and
 * deallocates it from the heap
 * @param stack Pointer to the stack
 * @return Value stored in the top element on the stack
 */
double pop(Stack *stack){
    if (stack->top != NULL){
        Element *topElement = stack->top;
        double val = topElement->val;
        stack->top = topElement->next;
        free(topElement);
        return val;
    }
    return NAN;
}

/**
 * Empties the stack in case an error occurs (to ensure no memory leaks)
 * @param stack Pointer to the stack
 */
void empty(Stack *stack){
    while (size(stack) > 0){
        pop(stack);
    }
}