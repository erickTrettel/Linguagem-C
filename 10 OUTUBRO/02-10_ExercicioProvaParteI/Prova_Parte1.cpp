#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHAS 20
#define COLUNAS 1012

void exibirMatriz(int saquesMensais[LINHAS][COLUNAS]);
void digitarValores(int saquesMensais[LINHAS][COLUNAS]);
int menorValorSomatorio(int somatorioFilial[LINHAS]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	int saquesMensais[LINHAS][COLUNAS] = {0};
	
	digitarValores(saquesMensais);
	
	exibirMatriz(saquesMensais);
	
	return 0;
}

void digitarValores(int saquesMensais[LINHAS][COLUNAS]){
	
	int mes, valor = 0, contagemMeses = 0, quantidadeSaques[6], somatorioFilial[LINHAS];
	
	for(int i=0; i<6; i++){
		quantidadeSaques[i] = 0;
		somatorioFilial[i] = 0;
	}
	
	for(int i=0;i<LINHAS; i++){
		//printf("FILIAL %d:\n", i+1);
		//printf("	MES %d -\n", contagemMeses+1);
		for(int j=0; j<COLUNAS; j++){			
			//printf("	Valor do saque: ");
			scanf("%d", &valor);
			
			if(valor == -1)
				contagemMeses++;
			
			if(contagemMeses < 6){
				if(valor > 0){
					somatorioFilial[i] += valor;
					if(somatorioFilial[i] > 1000){
						printf("\n O valor máximo de saque por filial é de 1000\n");
						somatorioFilial[i] -= valor;	
					}else{
						saquesMensais[i][j] = valor;
						quantidadeSaques[contagemMeses]++;	
					}
				}else if(valor == -1){
					//printf("\n	MÊS %d -\n", contagemMeses+1);
					saquesMensais[i][j] = valor;
				}else
					printf("********Valor digitado inválido\n");	
			}else{
				contagemMeses = 0;
				break;
			}	
		}
	}
	
	printf("\nMês: ");
	scanf("%d", &mes);
	if(mes > 5)
		printf("\nValor inválido\n");
	else
		printf("\nSaques: %d\n", quantidadeSaques[mes]);
	
	int menorValor = menorValorSomatorio(somatorioFilial);
	
	printf("\nMenor valor somatório: %d\n", menorValor);
}

int menorValorSomatorio(int somatorioFilial[LINHAS]){
	int menor = 1000;
	
	for(int i=0; i<LINHAS; i++){
		if(somatorioFilial[i] < menor){
			menor = somatorioFilial[i];
		}else{
			menor = menor;
		}
	}
	
	return menor;
}

void exibirMatriz(int saquesMensais[LINHAS][COLUNAS]){
	
	for(int i=0; i<LINHAS; i++){
		for(int j=0; j<COLUNAS; j++){
			if(saquesMensais[i][j] != 0)
				if(saquesMensais[i][j+1] == 0)
					printf("%d ", saquesMensais[i][j]);
				else
					printf("%d, ", saquesMensais[i][j]);
		}
		printf("\n");
	}
}
