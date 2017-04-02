#include <stdio.h>

/* Definition of structures. */
typedef struct {
    char nombre[10];
    //char *nombre;
    int numeroCuenta;
    float montoApertura;
} cuentaAhorro;

/* Declaring functions. */
void determinarTipo(float monto);
void mostrarInformacion(cuentaAhorro *c);
//propuesto
void obtenerInformacion(cuentaAhorro *ptrAhorro);

/* Main function. */
int main(){
    /* Local variables. */
    cuentaAhorro ahorrador;
    /*ejercicio propuesto*/
    cuentaAhorro *ptrAhorro;
    ptrAhorro= &ahorrador;
  
    // Obteniendo informacion del nuevo cliente
   obtenerInformacion(ptrAhorro);
    // mostrar informacion del nuevo cliente
    mostrarInformacion(ptrAhorro);

    return 0;
}

/* Implementation of functions. */

void determinarTipo(float monto) {
    printf("El cliente es tipo: ");
    if (monto < 100000) {
        printf("MiniAhorrador\n");
    } else if (monto > 200000) {
        printf("PreferencialProX\n");
    } else {
        printf("Ahorregular\n");
    }
}

// Modifique las siguientes lineas
void mostrarInformacion(cuentaAhorro *c) {
    printf("|%10s|%10s|%10s|\n", "Nombre", "Cuenta", "Apertura" );
    printf("|%10s|%10d|%10.2f|\n", c->nombre, c->numeroCuenta, c->montoApertura);
    determinarTipo(c->montoApertura);
}

void obtenerInformacion(cuentaAhorro *ptrAhorro){
	printf("$$$ Registrando un nuevo cliente $$$\n");
    printf("Nombre: ");
    setbuf(stdin, NULL);
    scanf("%s", ptrAhorro->nombre);  // Responda: porque no se utiliza el operador &
    printf("Numero de cuenta: ");
    setbuf(stdin, NULL);
    scanf("%d", &ptrAhorro->numeroCuenta);
    printf("Monto de apertura: ");
    setbuf(stdin, NULL);
    scanf("%f", &ptrAhorro->montoApertura);
}