	#include <stdio.h>
	
	
	int main()
	{
	    int matriz4[2][2]={1,2,3,4};
		int *p = &matriz4[0][0];
		int **p2;
		
		printf("\n%d", *p++);
		printf("\n%d", *p++);
		printf("\n%d", *p++);
		printf("\n%d", *p++);
		
		p = &matriz4[0][0];
		p2 = &p;
		
		printf("\n%d", **p2);
		p++;
		printf("\n%d", **p2);
		p++;
		printf("\n%d", **p2);
		p++;
		printf("\n%d", **p2);
	
	
		p  = &matriz4[0][0];
		p2 = &p;
		
		printf("\n%d", **p2);
		printf("\n%d", *(*p2 +1));
		printf("\n%d", *(*p2 +2));
		printf("\n%d", *(*p2 +3));
		
		
		
		
		
	}

 
