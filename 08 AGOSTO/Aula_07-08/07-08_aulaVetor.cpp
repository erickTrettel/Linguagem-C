#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int vetor1[100], valor, valoresVetor1 = 0, vetor2[100], valoresVetor2 = 0;
	
	
	//Preenche os vetores com o -1
	for(int i = 0; i<100; i++){
		vetor1[i] = -1;
		vetor2[i] = -1;
	}
	
	
	//Usuario insere valores do vetor 1
	do{
		printf("VETOR 1: Insira um valor de 0-9 e -1 para sair: ");
		scanf("%d", &valor);
		
		if(valor >= 0 && valor <= 9){
			vetor1[valoresVetor1] = valor;
			valoresVetor1++;
		}else{
			if(valor != -1){
				printf("Valor inválido\n");	
			}else{
				printf("\n");
			}
		}
			
	}while(valor != -1 && valoresVetor1 < 100);
	
	
	//Usuario insere valores do vetor 2
	do{
		printf("VETOR 2: Insira um valor de 0-9 e -1 para sair: ");
		scanf("%d", &valor);
		
		if(valor >= 0 && valor <= 9){
			vetor2 [valoresVetor2] = valor;
			valoresVetor2++;
		}else{
			if(valor != -1){
				printf("Valor inválido\n");	
			}else{
				printf("\n");
			}
		}
			
	}while(valor != -1 && valoresVetor2 < 100);
	
	int funcaoLogica = 0, contVetor1, contVetor2;
	
	if(valoresVetor1 >= valoresVetor2){
		for(int i = 0; i<valoresVetor1 && funcaoLogica == 0; i++){
			contVetor1 = i;
			contVetor2 = 0;
			while(contVetor2 < valoresVetor2 && vetor1[contVetor1] == vetor2[contVetor2]){
				contVetor1++;
				contVetor2++;
			}
			
			if(contVetor2 == valoresVetor2){
				funcaoLogica = 1;
			}
		}	
	}else{
		for(int i = 0; i<valoresVetor2 && funcaoLogica == 0; i++){
			contVetor2 = i;
			contVetor1 = 0;
			while(contVetor1 < valoresVetor1 && vetor2[contVetor2] == vetor1[contVetor1]){
				contVetor1++;
				contVetor2++;
			}
			
			if(contVetor1 == valoresVetor1){
				funcaoLogica = 1;
			}
		}
	}
	
	if(funcaoLogica == 1){
		printf("\nSim\n");
	}else{
		printf("\nNão\n");
	}
	
	system("PAUSE");
	return 0;
}
