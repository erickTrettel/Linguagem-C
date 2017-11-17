#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include "Produtos.c"

void abrirVenda(int numeroProdutos, Produto *lista);
float adicionarProduto(int numeroProdutos, Produto *lista);
void fecharVenda(float valor);

int mini(){

	Produto *lista;
	int opc, numeroProdutos;
	int capacidade;
	lista = abrirArquivo(&numeroProdutos, &capacidade);

	do{
		printf("TELA VENDAS - \n\n");
		printf(" 1. ABRIR VENDA\n");
		printf(" 2. SAIR\n\n");
		printf(">> ");
		scanf("%i", &opc);

		switch(opc){
			case 1:
				abrirVenda(numeroProdutos, lista);
				break;
		}

	}while(opc != 2);

	system("cls");
	main();

	return 0;
}

void abrirVenda(int numeroProdutos, Produto *lista){

	system("cls");

	int opc;
	float valor=0;

	do{
		printf(" - VENDA - \n\n");
		printf("TOTAL: %.2f\n", valor);
		printf(" 1. ADICIONAR PRODUTO\n");
		printf(" 2. FECHAR VENDA\n");
		printf(" 3. SAIR\n");
		printf(">> ");
		scanf("%i", &opc);

		switch(opc){
			case 1:
				valor += adicionarProduto(numeroProdutos, lista);
				break;
			case 2:
				salvar(lista, numeroProdutos);
				fecharVenda(valor);
				break;
		}
	}while(opc!=3);

}

float adicionarProduto(int numeroProdutos, Produto *lista){

	system("cls");

	int cod, i, quant;
	float valor;

	printf("\nCod. do Produto: ");
	scanf("%i", &cod);

	for(i=0; i<numeroProdutos; i++)
		if(cod == lista[i].cod){

			if(lista[i].estoque > 0){

				printf("\nPRODUTO: %s\n", lista[i].nome);
				printf(" QUANTIDADE: ");
				scanf("%i", &quant);
				if(lista[i].estoque > quant){
					valor = lista[i].preco * quant;
					lista[i].estoque -= quant;
				}else if(lista[i].estoque == 1){
					printf("\nULTIMO DO ESTOQUE\n");
				}else{
					printf("\nESTOQUE INSUFICIENTE\n");
				}
			}else{
				printf("\nFORA DE ESTOQUE\n");
			}

		}

	return valor;
}

void fecharVenda(float valor){

	system("cls");
	printf("VALOR TOTAL DA VENDA: R$%.2f\n", valor);
	valor=0;
	mini();
}
