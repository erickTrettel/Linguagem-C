	#include <stdio.h>
	
	
	int main()
	{
		int valor = 10;
		int *p1; 
		int **p2;
		
		
		p1 = &valor;
		p2 = &p1;
		
		printf("\n%d", valor);
		printf("\n%d", *p1);
		printf("\n%d",  p1);
		printf("\n%d", **p2);
		printf("\n%d", * p2);
		printf("\n%d",   p2);
		printf("\n%d",   &p2);
		
		
		
		
	}

 
