#include "colas.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void make(Queue* queue) {
	queue->front = queue->rear = MAXQUEUE - 1;
}

int isEmpty(Queue* queue) {
	if(queue->front == queue->rear) {
		return TRUE;
	} else{
		return FALSE;
	}
}

QUEUEELEMENT remove(Queue* queue) {
	if(isEmpty(queue)) {
		printf("La cola esta vacía, no se pueden retirar elmentos de ella");
		exit(1);
	}
	
	if(queue->front == MAXQUEUE - 1) {
		queue->front = 0;
	} else{
		(queue->front)++;
	}
	
	return queue->items[queue->front];
}

void insert(Queue* queue, QUEUEELEMENT elem) {
	if(queue->rear == MAXQUEUE - 1) {
		queue->rear = 0;
	} else{
		(queue->rear)++;
	}
	
	if(queue->front == queue->rear) {
		printf("Queue Overflow xD");
		exit(1);
	} else{
		queue->items[queue->rear] = elem;
	}
}
