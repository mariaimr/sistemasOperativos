#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int aleatorio();
int ** generarMatriz(int n, int m);
void sumarMatriz(int ** matriz, int n, int m);

int main(){
	srand(time(NULL));
	int n,m;
	int **matriz;
	printf("ingrese el numero de vectores:");
	scanf("%d", &n);	
	printf("ingrese la dimension de los vectores:");
	scanf("%d", &m);	
	
	printf("la cantidad de vectores son %d con %d componentes\n", n, m);
	
	matriz = generarMatriz(n, m);

	sumarMatriz(matriz, n, m);

}
int ** generarMatriz(int n, int m){
	int i, j;
	int **matriz;
	matriz = malloc(sizeof(int*) * n );
	for (i=0;i<n;i++){
		matriz[i] = malloc(sizeof(int)*m);
		for(j=0;j<m;j++){
		matriz[i][j] = aleatorio();
		}
	}
return matriz;
}
int aleatorio(){	
	return rand()%100 -50;
}

void sumarMatriz(int ** matriz, int n, int m){
int i,j,suma;
printf("vector resultado: [");
for(j=0;j<m;j++){
suma = 0;
	for(i=0;i<n;i++){
	suma += matriz[i][j];
}
printf("%d", suma);
}
puts("]");

}
