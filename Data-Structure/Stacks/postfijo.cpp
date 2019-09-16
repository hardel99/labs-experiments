#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TipoElemento;

typedef struct UnNodo {
	TipoElemento e;
	struct UnNodo *sig;
} Nodo;

typedef Nodo Pila;

int EsVaciaP(Pila *P) {
	return P == NULL;
}

void VaciaP(Pila** P) {
	*P = NULL;
}

void AnadeP(Pila** P, TipoElemento a) {
	Nodo * NuevoNodo;
	NuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	NuevoNodo->e = a;
	NuevoNodo->sig=(*P);
	*P=NuevoNodo;
}

TipoElemento PrimeroP(Pila *P){
	TipoElemento aux;
	
	if (EsVaciaP(P)) {
		puts ("Se intenta extraer un elemento de una pila vacia");
		exit(1);
	}
	
	aux = P->e;
	return aux;
}

void BorrarP(Pila** P) {
	Pila *NuevoNodo;
	
	if (EsVaciaP(*P)) {
		puts ("Se intenta extraer un elemento de una pila vacia");
		exit(1);
	}
	
	NuevoNodo=(*P);
	(*P) = NuevoNodo->sig;
	free(NuevoNodo);
}

int PrioridadDentro(char opdor) {
	switch (opdor) {
		case '(' : return 0;
		case '^' : return 3;
		case '/' : return 2;
		case '*' : return 2;
		case '+' : return 1;
		case '-' : return 1;
	}
	return 0 ;
}

int PrioridadFuera(char opdor) {
	switch (opdor) {
		case '(' : return 5;
		case '^' : return 4;
		case '/' : return 2;
		case '*' : return 2;
		case '+' : return 1;
		case '-' : return 1;
	}
	return 0 ;
}

int Operador (char ch) {
	return ( ch == '(' || ch =='+' || ch =='-' || ch == '*' ||ch == '/' || ch == '^' );
}

void Postfija (char Linea[80], char post[80]) {
	Pila *P;
	char ch, aux[2];
	int i, Apilado;
	VaciaP(&P);
	aux[1] = '\0';
	post[0] = '\0';
	for(i=0; i < strlen(Linea) ; i++) {
		if (Operador(Linea[i])) {
			Apilado = 0 ;
			while (Apilado == 0) {
				if (EsVaciaP(P)) {
					AnadeP(&P, Linea[i]) ;
					Apilado = 1 ;
				}else {
					ch = PrimeroP(P) ;
					if (PrioridadDentro(ch) >= PrioridadFuera(Linea[i])) {
						aux[0] = ch ;
						strcat(post, aux) ;
						BorrarP(&P) ;
					}else {
						AnadeP(&P, Linea[i]) ;
						Apilado = 1 ;
					}
				}
			}
		}else if (Linea[i] == ')' ) {
			ch = PrimeroP(P) ;
			BorrarP(&P) ;
			while (ch != '(' ) {
				aux[0] = ch;
				strcat(post, aux);
				ch = PrimeroP(P);
				BorrarP(&P);
			}
		}else {
			aux[0] = Linea[i];
			strcat(post, aux);
		}
	}
	
	while (!EsVaciaP(P)) {
		ch = PrimeroP(P) ;
		BorrarP(&P) ;
		aux[0] = ch ;
		strcat(post, aux) ;
	}
}

int main() {
	char post[80], Linea[80] ;
	puts(" Expresion a pasar a PostFija\n") ;
	gets(Linea) ;
	Postfija (Linea, post) ;
	puts("\n Postfija \n") ;
	puts(post) ;
	puts("\n\tPresione cualquier tecla para continuar") ;
	getch() ;
	return 0;
}

