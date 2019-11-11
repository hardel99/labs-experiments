#include "Stack.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <String.h>
#include <iostream>

using namespace std;

void isEmpty(Pila * );

int main (){
	int indicador = 1;
	Pila Estudiantes;
	
	while(indicador != 0){
		printf("\n1. Consultar si la pila esta vacia");
		printf("\n2. Ingresar elemento a la pila");
		printf("\n3. Extraer elemento de la pila");
		printf("\n0. Salir.");
		
		printf("\nIngrese su opcion ");
		scanf("%i",&indicador);
		
		switch(indicador){
			case 1:
				isEmpty(&Estudiantes);
				break;
			case 2:
				Elemento e01;
				e01 = ingresarObjeto();
				Push(&Estudiantes, e01);
				break;
			case 3:
				Elemento e02;
				e02 = Pop(&Estudiantes);
				imprimirElemento(&e02);
				break;
		}
	}
	printf("\n\n\n------------------------------------------------\nFin del programa\n------------------------------------------------");
	return 0;
}

void isEmpty(Pila * pila){
	if(Vacio(pila) == TRUE){
		printf("\nLa pila esta vacia");
	}
	else if(Vacio(pila) == FALSE){
		printf("\nLa pila no esta vacia");
	}
}

