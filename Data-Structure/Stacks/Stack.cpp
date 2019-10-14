#include "stack.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void clear(Stack* stack) {
	stack->top = -1;
}

int isEmpty(Stack* stack) {
	if(stack->top == -1) {
		return TRUE;
	} else{
		return FALSE;
	}
}

int isFull(Stack* stack) {
	if(stack->top == STACKSIZE -1) {
		return TRUE;
	}  else{
		return FALSE;
	}
}

void push(Stack* stack, STACKELEMENT elem) {
	if(isFull(stack)) {
		printf("Stack Overflooowwww :3!!!!");
		exit(1);
	} else{
		stack->items[++(stack->top)] = elem;
	}
}

STACKELEMENT pop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack Underflooowwww?!!");
		exit(1);
	} else{
		return stack->items[(stack->top--];
	}
}
