#include <stdio.h>
#include <conio.h>

int busqueda_bin ( int [], int, int, int );

int main() {
	int arre[]={25, 29, 33, 38, 44, 56, 89, 102, 128, 323, 679, 2007};
	int low, high, dig, pos;
	
	printf("Busqueda binaria en un arreglo ordenado. Version recursiva.\n");
	printf("Digite el numero que quiere buscar. Debe estar en el rango 24 y 2008.\n");
	scanf("%d", &dig);
	
	pos = busqueda_bin( arre, dig, 0, 11 );
	if (pos != -1 ) {
		printf("El numero fue encontrado, en la posición %d del arreglo.\n", pos);
	}else {
		printf("El numero no fue encontrado en el arreglo.\n");
	}
	
	getch();
	return 0;
}

/*Definicion de la funcion recursiva que realiza una busqueda binaria en un arreglo
** ordenado. Los parametros son: el arreglo, el valor que se busca, el subindice
** inferior y el subindice superior del arreglo que representa la zona donde se va a buscar */

/*Algoritmo eficiente en un cociente de nlog(n)*/
int busqueda_bin ( int a[], int p, int low, int high ) {
	int mid, aux;
	
	if ( low > high ) {
		aux = -1;
	}else {
		mid = ( low + high ) / 2;
		if ( p == a[mid]) {
			aux = mid;
		}else if ( p < a[mid]) {
			aux = busqueda_bin ( a, p, low, mid-1 );
		}else{
			aux = busqueda_bin ( a, p, mid+1, high );
		}
	}
	
	return aux; 
}
