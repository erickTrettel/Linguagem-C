#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define CAP 50

typedef struct{
	char titulo[100];
	char autor[100];
	float preco;
	char editora[100];
	char assunto[100];
	int codigo;
} Livro;

void receberInformacoes(Livro livros[CAP], int *quantidadeLivros);
void listarLivrosAutor(Livro livros[CAP], int quantidadeLivros);
void editarLivro(Livro livros[CAP], int quantidadeLivros, int codigoLivro);
void removerLivro(Livro livros[CAP], int *quantidadeLivros, int codigoLivro);

int main(void){

	Livro livros[CAP];

	int opc=0, quantidadeLivros=0;
	int codigoLivro;

	do{

		printf("1. RECEBER INFORMACOES\n");
		printf("2. LISTAR LIVROS DE UM ATOR\n");
		printf("3. EDITAR LIVRO\n");
		printf("4. REMOVER LIVRO\n");
		printf("5. SAIR\n");
		printf("\n>> ");
		scanf("%i", &opc);

		switch(opc){
			case 1:
				receberInformacoes(livros, &quantidadeLivros);
				break;
			case 2:
				listarLivrosAutor(livros, quantidadeLivros);
				break;
			case 3:
				printf(" CODIGO: ");
				scanf("%i", &codigoLivro);
				editarLivro(livros, quantidadeLivros, codigoLivro);
				break;
			case 4:
				printf(" CODIGO: ");
				scanf("%i", &codigoLivro);
				removerLivro(livros, &quantidadeLivros, codigoLivro);
				break;
		}

	}while(opc!=5);

	return 0;
}

void receberInformacoes(Livro livros[CAP], int *quantidadeLivros){

	int codigoLivro;

	system("cls");

	printf(" - RECEBER INFORMACOES LIVRO - \n\n");

	if(*quantidadeLivros == CAP){
		printf("Erro ao receber informa��es, capacidade atingida\n");
	}else{
		fflush(stdin);
		printf(" CODIGO: ");
		scanf("%i", &codigoLivro);

		for(int i=0; i<=*quantidadeLivros; i++){
			if(codigoLivro == livros[i].codigo){
				printf("Codigo ja cadastrado");
				break;
			}else{
				livros[*quantidadeLivros].codigo = codigoLivro;

				fflush(stdin);
				printf(" TITULO: ");
				gets(livros[*quantidadeLivros].titulo);

				fflush(stdin);
				printf(" AUTOR: ");
				gets(livros[*quantidadeLivros].autor);

				printf(" PRECO: ");
				scanf("%f", &livros[*quantidadeLivros].preco);

				fflush(stdin);
				printf(" EDITORA: ");
				gets(livros[*quantidadeLivros].editora);

				fflush(stdin);
				printf(" ASSUNTO: ");
				gets(livros[*quantidadeLivros].assunto);

				(*quantidadeLivros)++;
				system("cls");

				printf("SUCESSO.");
				break;
			}
		}
	}

	printf("\n\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");

}

void listarLivrosAutor(Livro livros[CAP], int quantidadeLivros){

	system("cls");

	char autor[100];
	int i;
	int verificador=0;

	fflush(stdin);
	printf("AUTOR: ");
	gets(autor);

	for(i=0; i<quantidadeLivros; i++){
		if(strcmp(autor, livros[i].autor)==0)
			verificador=1;
	}

	if(verificador==0){
		printf("\nAUTOR NAO ENCONTRADO");
	}else{
		for(i=0; i<quantidadeLivros; i++){

			if(strcmp(autor, livros[i].autor)==0){

				printf("\n\n --- %s --- \n", livros[i].titulo);
				printf(" CODIGO: %i\n", livros[i].codigo);
				printf(" AUTOR: %s\n", livros[i].autor);
				printf(" PRECO: %.2f\n", livros[i].preco);
				printf(" EDITORA: %s\n", livros[i].editora);
				printf(" ASSUNTO: %s\n", livros[i].assunto);
				printf(" ------------------------ \n\n");
			}
		}
	}

	printf("\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");

}

void editarLivro(Livro livros[CAP], int quantidadeLivros, int codigoLivro){

	system("cls");

	int i, opc;
	int verificador=0;

	for(i=0; i<quantidadeLivros; i++){
		if(livros[i].codigo == codigoLivro){
			verificador=1;

			do{
				printf("\n-->%s\n", livros[i].titulo);

				printf("\nSELECIONE O QUE DESEJA EDITAR: \n");
				printf("\n 1. TITULO");
				printf("\n 2. AUTOR");
				printf("\n 3. PRECO");
				printf("\n 4. EDITORA");
				printf("\n 5. ASSUNTO");
				printf("\n6. VOLTAR\n");
				printf("\n>> ");
				scanf("%i", &opc);

				switch(opc){
					case 1:
						fflush(stdin);
						printf("\nTITULO: ");
						gets(livros[i].titulo);
						printf("Titulo alterado");
						getch();
						system("cls");
						break;
					case 2:
						fflush(stdin);
						printf("\nAUTOR: ");
						gets(livros[i].autor);
						printf("Autor alterado");
						getch();
						system("cls");
						break;
					case 3:
						printf("\nPRECO: ");
						scanf("%f", &livros[i].preco);
						printf("Preco alterado");
						getch();
						system("cls");
						break;
					case 4:
						fflush(stdin);
						printf("\nEDITORA: ");
						gets(livros[i].editora);
						printf("Editora alterada");
						getch();
						system("cls");
						break;
					case 5:
						fflush(stdin);
						printf("\nASSUNTO: ");
						gets(livros[i].assunto);
						printf("Assunto alterado");
						getch();
						system("cls");
						break;
				}

			}while(opc!=6);
		}

	}

	if(verificador==0)
		printf("\nCodigo invalido.");


	printf("\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");

	verificador=0;

}

void removerLivro(Livro livros[CAP], int *quantidadeLivros, int codigoLivro){

	system("cls");

	int i, j, opc;
	int ver=0;

	fflush(stdin);
	for(i=0; i< *quantidadeLivros; i++){
		if(livros[i].codigo == codigoLivro){
			printf("\n--> %s", livros[i].titulo);

			printf("\n\nVoce tem certeza?");
			printf("\n1. SIM");
			printf("\n2. NAO");
			printf("\n>> ");
			scanf("%i", &opc);

			if(opc==1){
				ver=1;
				for(j=i; j<*quantidadeLivros; j++)
					livros[j] = livros[j+1];

				(*quantidadeLivros)--;
				i = *quantidadeLivros;
			}
		}
	}

	if(ver==0){
		printf("\nLivro nao encontrado\n");
	}else if(ver==1){
		system("cls");
		printf("\nRemovido com sucesso\n");
	}

	printf("\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");

	ver=0;

}
