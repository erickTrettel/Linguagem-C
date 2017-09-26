#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N[10], valor, i;
	
	for(i=0; i<10; i++){
		N[i] = 0;
	}
	
	scanf("%i", &valor);
	
	N[0] = valor;
	for(i=1; i<10; i++){
		N[i] = valor*2;
		valor = N[i];
	}
	
	for(i=0; i<10; i++){
		printf("N[%i] = %i\n", i, N[i]);
	}
	
	return 0;
}
