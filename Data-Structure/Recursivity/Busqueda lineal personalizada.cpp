#include <stdio.h>
#include <conio.h>

/* Programa que lee e imprime un arreglo de enteros
y después hace búsqueda lineal recursiva de ciertos
valores digitados por el usuario. */

int busquedalineal ( int *V, int n, int b);

int main () {
	int arreglo[12];
	int pos, i, num, bus, buscar=1;
	pos = 0;
	printf("Digite 12 valores para guardar en el arreglo:\n");
	
	for ( i = 0; i<12; i++ ) {
		printf("Digite el valor de la posicion %d del vector:", i);
		scanf("%d", &arreglo[i]);
	}
	
	printf("Los elementos del arreglo son: \n");
	
	for ( i = 0; i<12; i++) {
		printf("%d ", arreglo[i]);
	}
	
	printf("\n");
	
	while ( buscar ) {
		printf("Digite un numero a buscar en el arreglo:\n");
		scanf("%d",&num);
		pos = busquedalineal(arreglo, 11, num);
		if ( pos )
		printf("El numero %d se encuentra en el arreglo.\n",num);
		else
		printf("El numero %d no se encuentra en el arreglo.\n", num);
		printf("Desea buscar otro numero? S/N\n");
		bus=getch();
		if (bus == 's' || bus == 'S')
		buscar = 1;
		else
		buscar = 0;
	}
	
	getch();
	return 0;
}

/* funcion recursiva de búsqueda lineal */
int busquedalineal ( int *V, int n, int b) {
	if ( n==0 )
		return ( V[0] == b );
	else if ( V[n] == b )
		return 1;
	else
		return busquedalineal( V, n-1, b);
}
