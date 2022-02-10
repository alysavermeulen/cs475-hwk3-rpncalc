/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

// TODO: declaration of stack struct and its functions go here

/**
 * Struct for a stack element
 */
typedef struct Element
{
	double val;
	struct Element *next;	 // pointer to next value on stack
} Element;

/**
 * Struct for stack
 */
typedef struct Stack
{
	Element *top; // pointer to top element on stack
} Stack;

// function declarations
int size(Stack *stack);
void push(Stack *stack, double token);
double pop(Stack *stack);
void empty(Stack *stack);

#endif /* STACK_H_ */
