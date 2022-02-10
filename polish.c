/*
 * polish.c
 *
 * Created on: February 9, 2022
 * Author: Alysa Vermeulen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
#include "polish.h"


double evaluate(char *s){
    Stack *stack = (Stack*) malloc(sizeof(Stack));
	stack->top = NULL;
    char* token = NULL;
	token = strtok(s, " \t\n"); // get first token
	while (token != NULL){  // go through tokens
        char t = token[0];
		if (isdigit(t)){ // if token is a number (operand)
			double val = atof(token);
            push(stack,val);
		}
        else if (ispunct(t)){ // if token is a punctuation
            if (size(stack) < 2){
                printf("Error: insufficient operands.\n");
                empty(stack);
                return NAN;
            }
            else{
                double x = pop(stack); // second operand in equation
                double y = pop(stack); // first operand in equation
                double result;
                if (t == '+'){ // perform addition
                    result = y + x;
                }
                else if (t == '-'){ // perform subtraction
                    result = y - x;
                }
                else if (t == '*'){ // perform multiplication
                    result = y * x;
                }
                else if (t == '/'){ // perform division
                    if (x == 0){
                        printf("Error: divide-by-zero.\n");
                        empty(stack);
                        return NAN;
                    }
                    result = y / x;
                }
                else{ // if token is not a valid operator
                    printf("Error: operator %c unrecognized.\n", t);
                    empty(stack);
                    return NAN;
                }
                push(stack,result);
            }
        }
        else{ // if token is neither a number nor a punctuation (invalid input)
            printf("Error: input %c unrecognized.\n", t);
            empty(stack);
            return NAN;
        }
		token = strtok(NULL, " \t\n");
	}
    if (size(stack) > 1){
        printf("Error: too many operands entered.\n");
        empty(stack);
        return NAN;
    }
    else{
        double finalResult = pop(stack);
        return finalResult;
    }
}