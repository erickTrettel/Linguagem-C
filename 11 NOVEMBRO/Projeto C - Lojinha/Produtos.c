#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

typedef struct{
	int cod;
	char nome[100];
	float preco;
	int estoque;
} Produto;

Produto * abrirArquivo(int *numeroProdutos, int *capacidade);
void cadastrarProduto(Produto *lista, int *numeroProdutos, int *capacidade);
void exibirProdutos(Produto *lista, int numeroProdutos);
void apagarProduto(Produto *lista, int *numeroProdutos);
void salvar(Produto *lista, int numeroProdutos);
void consultarProduto(Produto *lista, int numeroProdutos);
void consultarCodigo(Produto *lista, int numeroProdutos);
void editarProduto(Produto *lista, int numeroProdutos);

int master(){

	Produto *lista;
	int capacidade, numeroProdutos, opcao;

	lista = abrirArquivo(&numeroProdutos, &capacidade);

	do{
		printf("TELA ADMINISTRACAO -\n\n");
		printf(" 1. CADASTRAR PRODUTO\n");
		printf(" 2. EXIBIR PRODUTOS\n");
		printf(" 3. APAGAR PRODUTO\n");
		printf(" 4. CONSULTAR PRODUTO POR NOME\n");
		printf(" 5. CONSULTAR PRODUTO POR CODIGO\n");
		printf(" 6. EDITAR PRODUTO\n");
		printf(" 7. SAIR\n\n");
		printf(">> ");
		scanf("%i", &opcao);

		switch(opcao){
			case 1:
				cadastrarProduto(lista, &numeroProdutos, &capacidade);
				break;
			case 2:
				exibirProdutos(lista, numeroProdutos);
				break;
			case 3:
				apagarProduto(lista, &numeroProdutos);
				break;
			case 4:
				consultarProduto(lista, numeroProdutos);
				break;
			case 5:
				consultarCodigo(lista, numeroProdutos);
				break;
			case 6:
				editarProduto(lista, numeroProdutos);
				break;
		}

	}while(opcao != 7);

	salvar(lista, numeroProdutos);

	free(lista);

	system("cls");
	main();

	return 0;
}

Produto * abrirArquivo(int *numeroProdutos, int *capacidade){

	Produto *lista;

	FILE *file = fopen("lista.txt", "r");

	if(file == NULL){
		*numeroProdutos = 0;
		*capacidade = 10;

		lista = (Produto *) malloc(sizeof(Produto) * (*capacidade));
	}else{
		fread(numeroProdutos, sizeof(int), 1, file);

		*capacidade = (*numeroProdutos) * 2;

		lista = (Produto *) malloc(sizeof(Produto) * (*capacidade));

		fread(lista, sizeof(Produto), *numeroProdutos, file);

		fclose(file);
	}

	return lista;

}

void cadastrarProduto(Produto *lista, int *numeroProdutos, int *capacidade){
	
	system("cls");
	
	printf(" - CADASTRO DE PRODUTO - \n\n");
	
	if(*numeroProdutos == *capacidade){
		*capacidade = *capacidade * 2;
		lista = (Produto*)realloc(lista, sizeof(Produto)*(*capacidade));
	}

	fflush(stdin);

	int cod = *numeroProdutos;
	lista[*numeroProdutos].cod = cod;

	printf("	Nome: ");
	gets(lista[*numeroProdutos].nome);

	printf("	Preco: ");
	scanf("%f", &lista[*numeroProdutos].preco);

	printf("	Estoque: ");
    char digitado[50], c;
    int i=0, numero=0;
	
	do
	{
       c=getch();
	   if (isdigit(c)!=0)
	   {
          digitado[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          digitado[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    digitado[i]='\0';
    numero = atoi(digitado);
	lista[*numeroProdutos].estoque = numero;

	(*numeroProdutos)++;
	system("cls");
}

void exibirProdutos(Produto *lista, int numeroProdutos){
	
	system("cls");
	printf(" - LISTA DE PRODUTOS - \n\n");
	int i;

	for(i=0; i<numeroProdutos;i++){
		printf("\n\n--- PRODUTO %i ------ \n", i+1);
		printf(" CODIGO: %i\n", lista[i].cod);
		printf(" NOME:	%s\n", lista[i].nome);
		printf(" PRECO:	%.2f\n", lista[i].preco);
		printf(" ESTOQUE: %i\n", lista[i].estoque);
		printf("-------------------- \n\n");
	}

}

void apagarProduto(Produto *lista, int *numeroProdutos){
	system("cls");
	int cod, i, j, opcao;
	int a=0;

	fflush(stdin);
	printf("Codigo do produto a ser removido: ");
	scanf("%i", &cod);

	for(i=0; i< *numeroProdutos; i++){
		if(lista[i].cod == cod){
			
			printf("\n-> %s", lista[i].nome);
			
			printf("\n\nVoce tem certeza?");
			printf("\n1. SIM");
			printf("\n2. NAO\n");
			printf(">> ");
			scanf("%i", &opcao);
			
			if(opcao==1){
				a=1;
				for(j=i; j< *numeroProdutos; j++)
					lista[j] = lista[j+1];

				(*numeroProdutos)--;
				i = *numeroProdutos;
			}			
		}
	}
	
	if(a==1){
		system("cls");
		printf("\nProduto removido\n");	
	}
	else if(opcao!=1)
		system("cls");	
	else{
		system("cls");
		printf("\nProduto nao encontrado\n");	
	}
		
	a=0;

}

void salvar(Produto *lista, int numeroProdutos){

	if(numeroProdutos > 0){

		FILE *file = fopen("lista.txt", "w");

		fwrite(&numeroProdutos, sizeof(int), 1, file);

		fwrite(lista, sizeof(Produto), numeroProdutos, file);

		fclose(file);

	}

}

void consultarProduto(Produto *lista, int numeroProdutos){
	system("cls");
	char nome[100];
	int i;

	fflush(stdin);
	printf("\nProduto a ser pesquisado: ");
	gets(nome);

	for(i=0; i<numeroProdutos; i++){
		if(strcmp(lista[i].nome, nome)==0){
			printf("\n\n--- PRODUTO %i ------ \n", i+1);
			printf(" CODIGO: %i\n", lista[i].cod);
			printf(" NOME:	%s\n", lista[i].nome);
			printf(" PRECO:	%.2f\n", lista[i].preco);
			printf(" ESTOQUE: %i\n", lista[i].estoque);
			printf("-------------------- \n\n");
		}
	}

}

void consultarCodigo(Produto *lista, int numeroProdutos){
	system("cls");
	int i, cod;

	fflush(stdin);
	printf("\nCod. do Produto: ");
	scanf("%i", &cod);

	for(i=0; i<numeroProdutos; i++){
		if(cod==lista[i].cod){
			printf("\n\n--- PRODUTO %i ------ \n", i+1);
			printf(" CODIGO: %i\n", lista[i].cod);
			printf(" NOME:	%s\n", lista[i].nome);
			printf(" PRECO:	%.2f\n", lista[i].preco);
			printf(" ESTOQUE: %i\n", lista[i].estoque);
			printf("-------------------- \n\n");
		}
	}

}

void editarProduto(Produto *lista, int numeroProdutos){

	system("cls");

	int i, cod, opc;
	int a=0;

	printf("Codigo do produto a ser editado: ");
	scanf("%i", &cod);

	for(i=0; i<numeroProdutos; i++){
		if(lista[i].cod == cod){
			a=1;
			printf("\nPRODUTO: %s\n", lista[i].nome);

			printf("\n	SELECIONE O QUE DESEJA EDITAR");
			printf("\n	 1. NOME");
			printf("\n	 2. PRECO");
			printf("\n	 3. ESTOQUE\n");
			scanf("%i", &opc);

			switch (opc) {
				case 1:
					fflush(stdin);
					printf("\nNome: ");
					gets(lista[i].nome);
					printf("Nome alterado\n");
					break;
				case 2:
					printf("\nPreco: ");
					scanf("%f", &lista[i].preco);
					printf("Preco alterado\n");
					break;
				case 3:
					printf("\nEstoque: ");
					scanf("%i", &lista[i].estoque);
					printf("Estoque alterado\n");
					break;
				default:
					printf("\nOpcao Invalida\n");
			}

		}
	}
	
	if(a==0){
		printf("\nCodigo invalido\n");
	}
	
	a=0;

}
