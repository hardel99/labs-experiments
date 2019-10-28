#include "DinamicQueue.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void freenode(Ptrnodoq p) {
	free(p);
}

Ptrnodoq getnode(void) {
	Ptrnodoq p;
	p = (Ptrnodoq)malloc(sizeof(struct Nodoq));
	return(p);
}

void LimpiarCola(TipoCola * pq) {
	pq->Frente = NULL;
	pq->Final = NULL;
}

int ColaVacia(TipoCola q) {
	return((q.Frente == NULL)? TRUE: FALSE);
}

void Poner(TipoDato x, TipoCola* pq) {
	Ptrnodoq T;
	
	T = getnode();
	T->Info=x;
	T->Sgte=NULL;
	
	if (ColaVacia(*pq))
		pq->Frente=T;
	else
		(pq->Final)->Sgte=T;
		
	pq->Final=T;
}

void Quitar(TipoDato* px, TipoCola* pq) {
	Ptrnodoq A;
	if (!ColaVacia(*pq)) { 
		*px = (pq->Frente)->Info;
		A = pq->Frente;
		pq->Frente = (pq->Frente)->Sgte;
		
		if (pq->Frente==NULL) {
			pq->Final = NULL;
		}
		
		freenode(A);
	}
}
