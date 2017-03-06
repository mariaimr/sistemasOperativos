#include <stdio.h>

int main()
{
   FILE *fichero;
   char nombre[10] = "datos.txt";
   unsigned int i, x1, x2, x3, x4;

   fichero = fopen( nombre, "r" );
   printf( "Fichero: %s (para lectura) -> ", nombre );
   if( fichero )
      printf( "existe (ABIERTO)\n" );
   else
   {
      printf( "Error (NO ABIERTO)\n" );
      return 1;
   }
   //ejemplo fprintf
   fprintf( fichero, "Esto es un ejemplo de usar la funcion \'fprintf\'\n" );
   fprintf( fichero, "\t 2\t 3\t 4\n" );
   fprintf( fichero, "x\tx\tx\tx\n\n" );
   for( i=1; i<=10; i++ )
      fprintf( fichero, "%d\t%d\t%d\t%d\n", i, i*i, i*i*i, i*i*i*i );

  	printf("Datos guardados en el fichero: %s\n", nombre );
   //fprintf

   //ejemplo fscanf
   printf( "Datos leidos del fichero: %s\n", nombre );
   printf( "Esto es un ejemplo de usar la funcion \'fscanf\'\n" );
   printf( "\t 2\t 3\t 4\n" );
   printf( "x\tx\tx\tx\n\n" );

   fscanf( fichero, "Esto es un ejemplo de usar la funcion \'fprintf\'\n" );
   fscanf( fichero, "\t 2\t 3\t 4\n" );
   fscanf( fichero, "x\tx\tx\tx\n\n" );
   for( i=1; i<=10; i++ )
   {
      fscanf( fichero, "%d\t%d\t%d\t%d\n", &x1, &x2, &x3, &x4 );
      printf( "%d\t%d\t%d\t%d\n", x1, x2, x3, x4 );
   }
   //fscanf
   if( !fclose(fichero) )
      printf( "Fichero cerrado\n" );
   else
   {
      printf( "Error: fichero NO CERRADO\n" );
      return 1;
   }

   return 0;
}