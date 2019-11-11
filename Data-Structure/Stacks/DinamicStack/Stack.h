#define TRUE 1
#define FALSE 0
#define NULL 0

using namespace std;

struct Objeto{
	char carnet[47];
	char nombre[40];
	int carrera;
};

typedef struct Objeto Elemento;

typedef struct nodo{
	Elemento elemento;
	struct nodo *siguiente; 
} tiponodo;

typedef tiponodo *pNodo;
typedef tiponodo *Pila;

int Vacio(Pila*);
Elemento Pop(Pila*);
void Push(Pila* , Elemento);
Objeto ingresarObjeto(void);
void imprimirElemento(Elemento*);