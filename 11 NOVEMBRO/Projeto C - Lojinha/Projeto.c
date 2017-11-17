#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Produtos.c"
#include "Loja.c"

#define LIM_SENHA 16

char * lerSenha(int max);

int main(void){

    SetConsoleTitle("Projeto Linguagem de Programacao");

    char *codAcesso;

    printf("COD. ACESSO: ");
    printf("\n>> ");
    codAcesso = lerSenha(LIM_SENHA);

    if(strcmp(codAcesso, "master")==0){
    	system("cls");
    	master();
	}else if(strcmp(codAcesso, "mini")==0){
		system("cls");
		mini();
	}else
		printf("\nERRO");

    return 0;
}

char * lerSenha(int max){
    int i=0;
    char *senha = (char *)malloc(sizeof(char) * max);
    char c;

	do{
		c=getch();

		if(i<=max){
			if(c==8&&i){
				senha[i] = '\0';
				i--;
				printf("\b \b");
			}else if(c==8 && i==0){

			}else if(c!=13){
				senha[i] = c;
				i++;
				printf("*");
			}
		}else{
			if(c==8&&i){
				senha[i] = '\0';
				i--;
				printf("\b \b");
			}
		}

	}while(c!=13);

    return senha;
}
