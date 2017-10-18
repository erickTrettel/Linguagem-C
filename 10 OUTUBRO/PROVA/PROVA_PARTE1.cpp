#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int main(){
	
	int valorBusca=0, contValores=0, valor=0, matriz[TAM][TAM] = {0};
	int contValoresLinha, contValoresColuna, linha, coluna;
	
	for(int i=0 ; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			scanf("%i", &valor);
		
			if(valor >= 0 && valor <= 9){
				matriz[i][j] = valor;
			}else{
				printf("\nSomente são aceitos valores entre 0 e 9.\n");
			}
		}
	}
	
	do{
		
		printf("\nDigite um valor de busca entre 0 e 9: ");
		scanf("%i", &valorBusca);
		
		if(valorBusca >= 0 && valorBusca <= 9){
			
			//VERIFICAR SEQUENCIA DE REPETIÇÃO
			for(int i=0; i<TAM; i++){
				for(int j=0; j<TAM; j++){
					
					if(matriz[i][j] == valor){						
						contValores++;
						
						if(matriz[i+1][j] == valor){							
							
							for(linha=i;linha<TAM; linha++){
								while(matriz[linha][coluna] == valor){
									contValoresLinha++;
									linha++;
								}
								
								if(contValores < contValoresLinha){
									contValores = contValoresLinha;
									contValoresLinha=0;
								}else{
									contValoresLinha=0;
								}
							}
							
						}else if(matriz[i][j+1] == valor){
							
							for(coluna=j;coluna<TAM; coluna++){
								while(matriz[linha][coluna] == valor){
									contValoresColuna++;
									coluna++;
								}
								
								if(contValores < contValoresColuna){
									contValores = contValoresColuna;
									contValoresColuna=0;
								}else{
									contValoresColuna=0;
								}
									
							}
							
						}
						
					}	
				}	
			}
			
			printf("\n%d\n", contValores);
			contValores = 0;
		}else{
			printf("\nValor deve estar entre 0 e 9\n");
		}
		
	}while(valorBusca != -1);
	
	return 0;
}
