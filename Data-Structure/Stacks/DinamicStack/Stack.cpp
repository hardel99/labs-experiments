#include "Stack.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <String.h>
#include <iostream>

int Vacio(Pila * pila) {
	if((*pila) == NULL) {
		return TRUE;
	} else{
		return FALSE;
	}
}

void Push(Pila * pila, Elemento e){
	pNodo nuevo;
	
	nuevo = (pNodo) malloc(sizeof(tiponodo));
	
	if(nuevo != NULL){
		nuevo->elemento = e;
		nuevo->siguiente = *pila;
		*pila = nuevo;
	} else{
		printf("\n%s\n","No se pudo ingresar el elemento. Falta de memoria");
	}
}

Elemento Pop (Pila * pila){
	pNodo temp;
	Elemento e;
	
	if(Vacio(pila)==FALSE){
		temp = *pila;
		e = (*pila)->elemento;
		*pila = (*pila)->siguiente;

		free(temp);
		
		return e;
	} else{
		printf("No se pudo extraer elemento, pila vacia");
		exit(0);
	}
}

Elemento ingresarObjeto(){
	Elemento objeto;
	
	printf("\nIngresar Carnet:");
	fflush(stdin);
	cin.getline(objeto.carnet,8,'\n');
	
	printf("\nIngresar nombre:");
	fflush(stdin);
	cin.getline(objeto.nombre,41,'\n');	
	
	printf("\nIngresar carrera: ");
	fflush(stdin);
	scanf("%i",&objeto.carrera);
	
	return objeto;
}

void imprimirElemento(Elemento * e){
	printf("\n-------------------------\n");
	printf("Estudiante extraido:");
	printf("\nCarnet: %s",e->carnet);
	printf("\nNombre: %s",e->nombre);
	printf("\nCarrera: %i",e->carrera);
	printf("\n-------------------------\n");
}