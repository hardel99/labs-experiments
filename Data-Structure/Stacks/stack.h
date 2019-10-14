#define TRUE 1
#define FALSE 0
#define STACKSIZE 100

typedef char STACKELEMENT;

typedef struct{
	int top;
	STACKELEMENT items[STACKSIZE];
} Stack;

void clear(Stack*);
int isEmptyStack(Stack*);
int isFull(Stack*);

STACKELEMENT pop(Stack*);
void push(Stack*, STACKELEMENT);
