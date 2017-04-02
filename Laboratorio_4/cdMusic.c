
struct ​cdMusic {
 char ​title[40];
 char ​artist[40];
 char ​genre[15];
 int ​numSongs;
 int ​releaseYear;
 float ​price;
} cd1, cd2; 	// Se declaran 2 variables después de
 				// definir la estructura.

int main() {
	
	cd1 = {“Brindo con el alma”, “Diomedes Diaz”, “Vallenato”, 11, 1986, 19900.0}; //inicializa 
	
	//Inicializando cada miembro por separado
	strcpy(cd2.title, “Incarnate”); //strcpy= copia la cadena que hay en el segundo parametro al primer parametro.
	strcpy(cd2.artist, “Killswitch Engage”);
	strcpy(cd2.genre, “Metalcore”);
	cd2.numSongs = 12;
	cd2.releaseYear = 2016;
	cd2.price = 200.0
	return 0;
}