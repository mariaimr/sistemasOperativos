#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

typedef struct{
	struct point point1;
	struct point point2;	
}rect;

int main(int argc, char const *argv[])
{
	int x1 = atoi(argv[1]);
	int y1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y2 = atoi(argv[4]);


	struct rect.point1.x = x1;
	/*rect.point1.y = y1;
	rect.point2.x = x2;
	rect.point2.y = y2;

	int base = (rect.point2.x) - (rect.point1.x);
	int altura = (rect.point2.y) - (rect.point1.y);

	int area = base * altura;

	printf("El area del rectangulo con coordenadas (%d, %d), (%d, %d) ingresado es: %d \n",rect.point1.x, rect.point1.y, rect.point2.x, rect.point2.y);*/
	*/

	return 0;
}