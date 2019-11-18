#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/* Estructuras y tipos */
typedef struct _nodo {
	int dato;
	struct _nodo *derecho;
	struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

/* Funciones con árboles: */
void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);

/*Tipos de recorridos*/
void InOrden(Arbol, void(*func)(int*));
void PreOrden(Arbol, void(*func)(int*));
void PostOrden(Arbol, void(*func)(int*));

/* Funciones auxiliares: */
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);
void Mostrar(int *d);

int main() {
	Arbol ArbolInt=NULL;
	int altura;
	int nnodos;
	
	/* Inserción de nodos en árbol: */
	Insertar(&ArbolInt, 10); 
	Insertar(&ArbolInt, 5); 
	Insertar(&ArbolInt, 12); 
	Insertar(&ArbolInt, 4);
	Insertar(&ArbolInt, 7); 
	Insertar(&ArbolInt, 3); 
	Insertar(&ArbolInt, 6); 
	Insertar(&ArbolInt, 9);
	Insertar(&ArbolInt, 8); 
	Insertar(&ArbolInt, 11); 
	Insertar(&ArbolInt, 14); 
	Insertar(&ArbolInt, 13);
	Insertar(&ArbolInt, 2); 
	Insertar(&ArbolInt, 1); 
	Insertar(&ArbolInt, 15); 
	Insertar(&ArbolInt, 10);
	Insertar(&ArbolInt, 17); 
	Insertar(&ArbolInt, 18); 
	Insertar(&ArbolInt, 16);
	printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));
	
	/* Mostrar el árbol en tres ordenes distintos: */
	printf("InOrden: "); InOrden(ArbolInt, Mostrar); printf("\n");
	printf("PreOrden: "); PreOrden(ArbolInt, Mostrar); printf("\n");
	printf("PostOrden: "); PostOrden(ArbolInt, Mostrar); printf("\n");
	
	/* Borraremos algunos elementos: */
	printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
	Borrar(&ArbolInt, 5); printf("Borrar 5: "); InOrden(ArbolInt, Mostrar); printf("\n");
	Borrar(&ArbolInt, 8); printf("Borrar 8: "); InOrden(ArbolInt, Mostrar); printf("\n");
	Borrar(&ArbolInt, 15); printf("Borrar 15: "); InOrden(ArbolInt, Mostrar); printf("\n");
	Borrar(&ArbolInt, 245); printf("Borrar 245: "); InOrden(ArbolInt, Mostrar); printf("\n");
	Borrar(&ArbolInt, 4); printf("Borrar 4: "); InOrden(ArbolInt, Mostrar); printf("\n");
	Borrar(&ArbolInt, 17); printf("Borrar 17: "); InOrden(ArbolInt, Mostrar); printf("\n");
	printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
	
	/*Alturas*/
	printf("Altura de 1 %d\n", Altura(ArbolInt, 1));
	printf("Altura de 10 %d\n", Altura(ArbolInt, 10));
	printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));
	
	/* Liberar memoria asociada al árbol: */
	Podar(&ArbolInt);
	system("PAUSE");
	return 0;
}

void Podar(Arbol *a) {
	/* Algoritmo recursivo, recorrido en postorden */
 	
	if(*a) {
		Podar(&(*a)->izquierdo); /* Podar izquierdo */
		Podar(&(*a)->derecho); /* Podar derecho */
		free(*a); /* Eliminar nodo */
		*a = NULL;
	}
}

void Insertar(Arbol *a, int dat) {
	pNodo padre = NULL;
	pNodo actual = *a;
	
	/* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
	while(!Vacio(actual) && dat != actual->dato) {
		padre = actual;
		if(dat < actual->dato) 
			actual = actual->izquierdo;
		else if(dat > actual->dato) 
			actual = actual->derecho;
	}
	
	/* Si se ha encontrado el elemento, regresar sin insertar */
	if(!Vacio(actual)) return;
	
	/* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será el nodo raiz */
	if(Vacio(padre)) {
		*a = (Arbol)malloc(sizeof(tipoNodo));
		(*a)->dato = dat;
		(*a)->izquierdo = (*a)->derecho = NULL;
	}else if(dat < padre->dato) {	/* Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda */
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->izquierdo = actual;
		actual->dato = dat;
		actual->izquierdo = actual->derecho = NULL;
	}else if(dat > padre->dato) {	/* Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha */
		actual = (Arbol)malloc(sizeof(tipoNodo));
		padre->derecho = actual;
		actual->dato = dat;
		actual->izquierdo = actual->derecho = NULL;
	}
}

void Borrar(Arbol *a, int dat) {
	pNodo padre = NULL;
	pNodo actual;
	pNodo nodo;
	int aux;
	actual = *a;
	
	/* Mientras sea posible que el valor esté en el árbol */
	while(!Vacio(actual)) {
		if(dat == actual->dato) { /* Si el valor está en el nodo actual */
			if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
				if(padre) /* Si tiene padre (no es el nodo raiz) */
					/* Anulamos el puntero que le hace referencia */
					if(padre->derecho == actual) 
						padre->derecho = NULL;
					else if(padre->izquierdo == actual) 
						padre->izquierdo = NULL;
						
				free(actual);
				actual = NULL;
					
				return;
			}else { /* Si el valor está en el nodo actual, pero no es hoja */
				padre = actual;
				/* Buscar nodo más izquierdo de rama derecha */
				if(actual->derecho) {
					nodo = actual->derecho;
					while(nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				} else{	/* O buscar nodo más derecho de rama izquierda */
					nodo = actual->izquierdo;
					while(nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				
				/* Intercambiar valores de no a borrar u nodo encontrado y continuar, cerrando el bucle. El
				nodo encontrado no tiene por qué ser un nodo hoja, cerrando el bucle nos aseguramos de que
				sólo se eliminan nodos hoja. */
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
		} else{ /* Todavía no hemos encontrado el valor, seguir buscándolo */
			padre = actual;
			
			if(dat > actual->dato) 
				actual = actual->derecho;
			else if(dat < actual->dato) 
				actual = actual->izquierdo;
		}
	}
}

void InOrden(Arbol a, void (*func)(int*)) {
	if(a->izquierdo) 
		InOrden(a->izquierdo, func);
	
	func(&(a->dato));
	
	if(a->derecho) 
		InOrden(a->derecho, func);
}

void PreOrden(Arbol a, void  (*func)(int*)) {
	func(&a->dato);
	
	if(a->izquierdo) 
		PreOrden(a->izquierdo, func);
	
	if(a->derecho) 
		PreOrden(a->derecho, func);
}

void PostOrden(Arbol a, void (*func)(int*)) {
	if(a->izquierdo) 
		PostOrden(a->izquierdo, func);
	if(a->derecho) 
		PostOrden(a->derecho, func);
	
	func(&a->dato);
}

int Buscar(Arbol a, int dat) {
	pNodo actual = a;
	/* Todavía puede aparecer, ya que quedan nodos por mirar */
	while(!Vacio(actual)) {
		if(dat == actual->dato) 
			return TRUE; /* dato encontrado */
		else if(dat < actual->dato) 
			actual = actual->izquierdo;
		else if(dat > actual->dato) 
			actual = actual->derecho;
	}
	
	return FALSE; /* No está en árbol */
}

int Altura(Arbol a, int dat) {
	int altura = 0;
	pNodo actual = a;
	
	/* Todavía puede aparecer, ya que quedan nodos por mirar */
	while(!Vacio(actual)) {
		if(dat == actual->dato) {
			return altura; /* encontrado: devolver altura */
		} else{
			altura++; /* Incrementamos la altura, seguimos buscando */
			if(dat < actual->dato) actual = actual->izquierdo;
			else if(dat > actual->dato) actual = actual->derecho;
		}
	}
	
	return -1; /* No está en árbol, devolver -1 */
}

int NumeroNodos(Arbol a, int *contador) {
	*contador = 0;
	auxContador(a, contador); /* Función auxiliar */
	return *contador;
}

void auxContador(Arbol nodo, int *c) {
	(*c)++; /* Otro nodo */
	
	/* Continuar recorrido */
	if(nodo->izquierdo) 
		auxContador(nodo->izquierdo, c);
	if(nodo->derecho) 
		auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol a, int *altura) {
	*altura = 0;
	auxAltura(a, 0, altura); /* Función auxiliar */
	return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura) {
	/* Recorrido postorden */
	if(nodo->izquierdo) 
		auxAltura(nodo->izquierdo, a+1, altura);
	if(nodo->derecho) 
		auxAltura(nodo->derecho, a+1, altura);
	
	/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	árbol, actualizamos la altura actual del árbol */
	if(EsHoja(nodo) && a > *altura) 
		*altura = a;
}

int Vacio(Arbol r) {
	return r==NULL;
}

int EsHoja(pNodo r) {
	return !r->derecho && !r->izquierdo;
}

void Mostrar(int *d) {
	printf("%d, ", *d);
}
