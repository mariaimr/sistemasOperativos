#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* This program can create, multiply and print 2D-matrices*/

/* Functions to provide */
//int random();
int** create_matrix(int dim);
void print_matrix(int** matrix, int dim);
void free_matrix(int**, int dim);
int** mult_matrix(int** m_A, int** m_B, int dim);

int main(int argc, char *argv[]){

  srand(time(NULL));
  int** matrix_A;
  int** matrix_B;
  int** matrix_R;
  int dim;

  if( argc != 2 ){ 
    printf("ERROR: you need to provide the dimention of the square matrices\n");
    return -1;
  }
  else{
    printf("The matrix dimention is %s x %s\n",argv[1],argv[1]);
  }

  dim = atoi(argv[1]);
  
  printf("Creating Matrix A:\n");
  matrix_A= create_matrix(dim);
  print_matrix(matrix_A,dim);
  printf("\nCreating Matrix B:\n");
  matrix_B= create_matrix(dim);
  print_matrix(matrix_B,dim);

  printf("\nMultiplying Matrices A * B:\n");
  matrix_R= mult_matrix(matrix_A,matrix_B,dim);
  print_matrix(matrix_R,dim);
  
  free_matrix(matrix_A,dim);
  free_matrix(matrix_B,dim);
  free_matrix(matrix_R,dim);

  return 0;  
}

int** create_matrix(int dim){
  int i, j;
  int **new_matrix;
  new_matrix = malloc(sizeof(int*) * dim );
  for (i=0;i<dim;i++){
    new_matrix[i] = malloc(sizeof(int)*dim);
    for(j=0;j<dim;j++){
    new_matrix[i][j] = rand()%20 -5;
    }
  }
  printf("In create_matrix\n");
return new_matrix;
}
  
void print_matrix(int** matrix, int dim){
  int i, j;
  for (i=0;i<dim;i++){
    for(j=0;j<dim;j++){ 
    printf(" |%-3d|", matrix[i][j]);

    }
    printf("\n");
  }
printf("In print_matrix\n");
}

void free_matrix(int** matrix, int dim){
  int i;
  for (i = 0; i < dim; ++i)
  {
    free(matrix[i]);
  }
  free(matrix);
  printf("In free_matrix\n");
}

int** mult_matrix(int** m_A, int** m_B, int dim){
 
  int** m_R;
  int i,j,k, temporal;
  m_R = malloc(sizeof(int*) * dim );
  for (i=0;i<dim;i++){
    m_R[i] = malloc(sizeof(int)*dim);
    for(j=0;j<dim;j++){
      temporal=0;
      for (k = 0; k < dim; k++)
      {
        temporal += m_A[i][k]* m_B[k][j];
        m_R[i][j] = temporal;
      }
   
    }
  }
  printf("In mult_matrix\n");
  return m_R;
}


