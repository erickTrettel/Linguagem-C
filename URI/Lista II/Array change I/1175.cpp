#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N[20], i, j, aux=0;
	
	for(i=0; i<20; i++){
		N[i] = 0;
	}
	
	for(i=0; i<20; i++){
		scanf("%i", &N[i]);
	}
	
	for(i=19, j=0; i>=0; i--, j++){
		printf("N[%i] = %i\n", j, N[i]);
	}
	
	return 0;
}
