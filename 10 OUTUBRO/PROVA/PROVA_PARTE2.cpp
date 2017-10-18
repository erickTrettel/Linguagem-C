#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * construirMatriz(int tamanho);
void receberValores(int *p, int tamanho);
void liberarMemoria(int *p);
void busca(int *p, int tamanho);
int procurarValores(int *p, int tamanho, int busca);

int main(){
	
	int *p, linhas, colunas;
	
	printf("Quantidade de linhas: ");
	scanf("%d", &linhas);
	
	printf("Quantidade de colunas: ");
	scanf("%d", &colunas);
	
	int tamanho = linhas * colunas;
	
	p = construirMatriz(tamanho);
	
	receberValores(p, tamanho);
	
	busca(p, tamanho);
	
	liberarMemoria(p);
	
	return 0;
}

int * construirMatriz(int tamanho){
	int *p;
	
	p = (int *) malloc(tamanho * sizeof(int));
	
	if (!p) {
		printf ("\nMemoria Insuficiente\n");
		exit;
	}
	
	return p;
}

void receberValores(int *p, int tamanho){
	
	int valor;
	
		for(int i=0; i<tamanho; i++){
			scanf("%d", &valor);
			
			if(valor >= 0 && valor <= 9)
				p[i] = valor;
		}
			
	
}

void liberarMemoria(int *p){

	free(p);
	
}

void busca(int *p, int tamanho){
	
	int busca, quantValores=0;
	
	do{
		
		printf("\nBusca: ");
		scanf("%d", &busca);
		
		if(busca >= 0 && busca <= 9)
			quantValores =  procurarValores(p, tamanho, busca);
		else
			printf("\nDigite um valor entre 0 e 9");
		
		if(quantValores > 1)
			printf("\n%d valores\n", quantValores);
		else if(quantValores == 1)
			printf("\n%d valor\n", quantValores);
		else
			printf("\nNenhum valor\n");
		
	}while(busca != -1);
	
}

int procurarValores(int *p, int tamanho, int busca){
	
	int valores = 0, ref = 0;
	int linhas = sqrt(tamanho);
	int colunas = linhas;
    
	for(int i=0; i<linhas; i++)
		for(int j=0; j<colunas; j++){
			
			if(p[i+j] == busca){
				
				while(p[i+j] == busca)
					valores++;
				
				if(ref <= valores)
					ref = valores;
					
				valores = 0;
			}
		}
	
	
	return ref;
	
}
