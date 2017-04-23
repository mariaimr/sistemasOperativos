
//Declaracion de estructura
struct point{
	int x;
	int y;
};

typedef struct ​{
 struct ​point pt1; // Es posible anidar estructuras
 struct ​point pt2;
} rect;


int main()
{	
	rect r = {{1, 1}, {5, 4}}; // se inicializa
	return 0;
}
