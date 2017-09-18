#include <stdio.h>
#include <stdlib.h>

int main(){
	int X=0, N, i, j, valor;
	
	while(scanf("%i", &valor) != EOF && valor<= 200 && valor>=0){
		int N = 0;
		X++;
		
		for(i=0; i<=valor; i++){
			for(j=0;j<i;j++){
				N++;
			}
		}
		
		if(N == 0){
			printf("Caso %i: %i numero\n", X, N+1);
		}else{
			printf("Caso %i: %i numeros\n", X, N+1);
		}
		
		printf("%i", 0);
		for(i=0; i<=valor; i++){
			for(j=0;j<i;j++){
				printf(" %i", i);
			}
		}
		
		printf("\n\n");
	}
	
	return 0;
}
