#include <stdio.h>
int  main(void)
{
	int A[6] = { 2, 3, 1, 0, 9, 6};
	int *ptr1;
	int *ptr2 = &A[5];
	ptr1 = A;
	ptr1 += 2;
	*ptr1 = 5;
	ptr2--;
	*(ptr2) = *ptr1 + *(ptr2-1) + *(ptr2+1);
	for (int i = 0; i < 6; ++i)
	{
		int tmp= A[i];
		printf("vector en la posicion %d= %d\n",i,tmp );
	}
	return 0;
}