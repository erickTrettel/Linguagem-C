#include <stdio.h>
#include <stdlib.h>
#define TAM	100

int main(){
	
	int i;
	float A[TAM];
	
	for(i=0; i<TAM; i++){
		scanf("%f", &A[i]);
	}
	
	for(i=0; i<TAM; i++){
		if(A[i] <= 10){
			printf("A[%i] = %.1f\n", i, A[i]);
		}
	}
	
	return 0;
}
