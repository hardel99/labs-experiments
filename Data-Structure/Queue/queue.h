#define TRUE 1
#define FALSE 0
#define MAXQUEUE 100

typedef char QUEUEELEMENT;
typedef struct{
	int front, rear;
	QUEUEELEMENT items[MAXQUEUE];
} Queue;

void make(Queue*);
int isEmpty(Queue*);
QUEUEELEMENT remove(Queue*);
void insert(Queue*, QUEUEELEMENT);
