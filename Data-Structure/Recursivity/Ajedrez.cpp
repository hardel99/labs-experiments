#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 8
#define n (N+1)
#define Ncuadrado N*N
#define True 1
#define False 0

void Caballo(int i, int Posx, int Posy, int* exito) ;
void PresentaResultado() ;
/* Se declara el tablero de ajedrez */
int Tab[n][n] ;
/* Los posibles 8 movimientos del caballo */
int Movimiento[8][2]={ {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} } ;

int main () {
	int solucion;
	/* Se coloca el caballo en la casilla 1,1 */
	Tab[1][1] = 1 ;
	Caballo(2,1,1, &solucion);
	
	if (solucion) {
		puts ("\n El Problema tiene solucion:\n") ;
		PresentaResultado() ;
	} else {
		puts ("\n No se ha encontrado solucion al Problema\n") ;
	}
	
	getch() ;
	return 0;
}

void Caballo(int i, int Posx, int Posy, int* exito) {
	/* Donde: i= número de salto
	Posx, Posy = Coordenadas Actuales
	Cx, Cy , Mov = Coordenadas de los posibles movimientos que resulten
	aceptables cuando
	no hayan sido ocupados previamente y no caigan fuera del tablero */
	
	int Cx, Cy, Mov ;
	*exito = False ;
	
	/* Inicializa el conjunto posible de movimientos */
	Mov = 0 ;
	
	while ( (Mov < 8) && !(*exito) ) {
		Cx = Posx+Movimiento[Mov][0] ;
		Cy = Posy+Movimiento[Mov][1] ;
		/* Determina si nuevas coordenadas son aceptables */
		if ( (Cx >= 1) && (Cx <= N) && (Cy >= 1) && (Cy <= N) && (Tab[Cx][Cy] == 0 ) ) {
			/* Anota un Movimiento, es decir pone en la posicion correspondiente
			del tablero el valor del número de movimiento */
			Tab[Cx][Cy] = i ;
			if (i < Ncuadrado) {
				Caballo(i+1, Cx, Cy, exito) ;
				if (!(*exito))
				/* No hay Solucion, Borra un Movimiento, es decir pone en la
				posicion
				correspondiente del tablero el valor de cero*/
				Tab[Cx][Cy] = 0 ;
			} else {
				/* Hay Solucion */
				*exito = True ;
			}
		}
		Mov++ ;
	}
}

void PresentaResultado ( ) {
	int i, j ;
	for (i=1; i<= N; i++) {
		for (j=1; j <= N; j++) {
			printf("%d %c", Tab[i][j], (j < N ? ' ' : '\n') );
		}
	}
}

