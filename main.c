/**
 * This file contains the driver function to test the rpn calculator
 * 
 * Created on: February 9, 2022
 * Author: Alysa Vermeulen
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	char eqn[MAX_EQ_LEN];	 // string to store the input RPN expression
	char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"

	/* TODO */
	do{
		printf("Enter an equation (in RPN):\n");
		fgets(eqn, MAX_EQ_LEN, stdin);
		double result = evaluate(eqn);
		if (!isnan(result)){
			printf("%0.3f\n", result);
		}
		printf("\nEvaluate another? (y/n): ");
		fgets(resp, MAX_EQ_LEN, stdin);
		while (strlen(resp) > 2 || (resp[0] != 'y' && resp[0] != 'n')){ // invalid input
			printf("\nPlease enter a valid input.\n");
			printf("Evaluate another? (y/n): ");
			fgets(resp, MAX_EQ_LEN, stdin);
		}
	} while (resp[0] == 'y');

	printf("Exiting...\n");
	return 0;
}
