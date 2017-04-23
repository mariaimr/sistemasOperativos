#include <stdio.h>
int main()
{
	int a, b=3, c=8, d;
	int *p1= &a, *p2, *p3 = &c;

	*p1= 2;
	p2= p3;
	*p2 = *p1 - b;
	d = (*p2) * (*p1);
	p3 = &d;
	b= a+b+c;

	printf("a=%d, b=%d, c= %d, d=%d\n",a,b,c,d );
	return 0;
}