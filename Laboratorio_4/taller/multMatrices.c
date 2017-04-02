#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program can create, multiply and print 2D-matrices*/

/* Functions to provide */
int** create_matrix(int dim);
void print_matrix(int** matrix, int dim);
void free_matrix(int**, int dim);
int** mult_matrix(int** m_A, int** m_B, int dim);

int main(int argc, char *argv[]){

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
  // TODO: call function to create matrix_A
  // TODO: call function to print matrix_A

  int** matA = create_matrix(dim);
  print_matrix(matA, dim);

  printf("Creating Matrix B:\n");
  // TODO: call function to create matrix_B
  // TODO: call function to print matrix_B
  int** matB = create_matrix(dim);
  print_matrix(matB, dim);

  printf("Multiplying Matrices A * B:\n");
  // TODO: call function to multiply A * B
  // TODO: call function to print result R

  int** matR = mult_matrix(matA, matB, dim);
  print_matrix(matR,dim);
  
  // TODO: call function to free matrices memory
  free_matrix(matA, dim);
  free_matrix(matB, dim);
  free_matrix(matR, dim);
  return 0;  
}

int** create_matrix(int dim){
  // TODO: reserve memory for a give matrix
  // TODO: initilize matrix's values
  int** matrix;
  int i,j;
  matrix = (int **)malloc (dim*sizeof(int *));
  for (i=0;i<dim;i++)
  matrix[i] = (int *) malloc (dim*sizeof(int));

  //srand(time(NULL));
  for (i = 0; i < dim; i++)
  {
    for (j = 0; j < dim; j++)
    {
      int randon = rand() % 10;
      matrix[i][j]= randon;
    }
  }
  printf("In create_matrix\n");
  return matrix;
}

void print_matrix(int** matrix, int dim){
  // TODO: print matrix
  int i,j;
  for (i=0; i<dim; i++) 
  { 
    printf("\n"); 
    for (j=0; j<dim; j++) 
      printf("\t%d", matrix[i][j] ); 
  } 

  printf("In print_matrix\n");
}

void free_matrix(int** matrix, int dim){
  // TODO: use free() to free matrix's memory
  int i;
  for (i = 0; i < dim; ++i)
  {
    free(matrix[i]);
  }
  free(matrix);

  printf("In free_matrix\n");
}

int** mult_matrix(int** m_A, int** m_B, int dim){
  // TODO: create memory to result matrix
  // TODO: Multiply matrices
  int** m_R;
  int i,j,k;
  m_R= (int **)malloc (dim*sizeof(int *));
  for (i=0;i<dim;i++)
  m_R[i] = (int *) malloc (dim*sizeof(int));

  for (i = 0; i < dim; ++i)
  {
    for (j= 0; j < dim; ++j)
    {
      for (k = 0; k < dim; ++k)
      {
        m_R[i][j] += m_A[i][k] * m_B[k][j]; 
      }
    }
  }
  
  printf("In mult_matrix\n");
  return m_R;
}