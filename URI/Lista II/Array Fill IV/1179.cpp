#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, j, jPar=0, jImpar=0, par[5], impar[5], valor;
	
	for(i=0; i<5; i++){
		par[i] = 0;
		impar[i] = 0;
	}
	
	for(i=0; i<15; i++){
		scanf("%i", &valor);
		
		if(valor%2==0){
			par[jPar] = valor;
			jPar++;
		}else{
			impar[jImpar] = valor;
			jImpar++;
		}
		
		if(jPar == 5){
			for(j=0; j<5; j++)
				printf("par[%i] = %i\n", j, par[j]);
			jPar=0;
		}else if(jImpar == 5){
			for(j=0; j<5; j++)
				printf("impar[%i] = %i\n", j, impar[j]);
			jImpar=0;
		}
	}
	
	for(i=0; i<jImpar; i++){
		printf("impar[%i] = %i\n", i, impar[i]);
	}
	
	for(i=0; i<jPar; i++){
		printf("par[%i] = %i\n", i, par[i]);
	}
	
	return 0;
}
