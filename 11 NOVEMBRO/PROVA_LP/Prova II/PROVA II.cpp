#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
	int codigo;
	char funcao[100];
	char local[100];
	int idioma;
	char preenchida[5];
} Vaga;

Vaga * AbrirArquivo(int *numeroRegistros, int *capacidade);
void Salvar(Vaga * vagas, int numeroRegistros);
void cadastrarVaga(Vaga *vagas, int *numeroRegistros);
void finalizarVaga(Vaga *vagas, int numeroRegistros);
void listarVagas(Vaga *vagas, int numeroRegistros);

int main(){
	
	
	int opc=0, numeroRegistros=0, capacidade=0;
	Vaga *vagas;
	
	vagas = AbrirArquivo(&numeroRegistros, &capacidade);
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++)
			vagas[i].idioma = 0;
	}
	
	do{
		printf("1. CADASTRAR UMA VAGA\n");
		printf("2. FINALIZAR UMA VAGA\n");
		printf("3. LISTAR VAGAS EM ABERTO\n");
		printf("4. SAIR\n");
		printf("\n >> ");
		scanf("%i", &opc);
		
		switch(opc){
			case 1:
				cadastrarVaga(vagas, &numeroRegistros);
				break;
			case 2:
				finalizarVaga(vagas, numeroRegistros);
				break;
			case 3:
				listarVagas(vagas, numeroRegistros);
				break;
		}
		
	}while(opc!=4);
	
	Salvar(vagas, numeroRegistros);
	
	free(vagas);
	
	return 0;
}

Vaga * AbrirArquivo(int *numeroRegistros, int *capacidade){
	
	Vaga *vagas;
	
	FILE *arquivo = fopen("vagas.txt", "r");

	if(arquivo == NULL){
		*capacidade = 20;
		*numeroRegistros = 0;

		vagas = (Vaga *) malloc(sizeof(Vaga)*(*capacidade));
	}else{
		fread(numeroRegistros, sizeof(int), 1, arquivo);

		*capacidade = (*numeroRegistros)*2;

		vagas = (Vaga *)malloc(sizeof(Vaga)*(*numeroRegistros));

		fread(vagas, sizeof(Vaga), *numeroRegistros, arquivo);

		fclose(arquivo);
	}

	return vagas;
	
}

void Salvar(Vaga * vagas, int numeroRegistros){
	
	if(numeroRegistros > 0){

		FILE *file = fopen("vagas.txt", "w");

		fwrite(&numeroRegistros, sizeof(int), 1, file);

		fwrite(vagas, sizeof(Vaga), numeroRegistros, file);

		fclose(file);

	}
	
}

void cadastrarVaga(Vaga *vagas, int *numeroRegistros){
	
	int codigoVaga;
	
	system("cls");

	printf(" - CADASTRAR VAGA - \n\n");

	fflush(stdin);
	printf(" CODIGO: ");
	scanf("%i", &codigoVaga);
	
	for(int i=0; i<=*numeroRegistros; i++){
		if(codigoVaga == vagas[i].codigo){
			printf("Codigo ja cadastrado");
			break;
		}else{
			vagas[*numeroRegistros].codigo = codigoVaga;
			
			fflush(stdin);
			printf(" FUNCAO: ");
			gets(vagas[*numeroRegistros].funcao);

			fflush(stdin);
			printf(" LOCAL: ");
			gets(vagas[*numeroRegistros].local);
			
			int opcao=0;
			printf(" IDIOMA: ");
			printf("\n1. Portugues");
			printf("\n2. Ingles");
			printf("\n3. Frances");
			printf("\n4. Espanhol");
			printf("\n5. Italiano");
			printf("\n6. FIM\n");
			printf("\n >> ");
			scanf("%i", &opcao);
				
			vagas[*numeroRegistros].idioma = opcao;
			
			char nao[5] = "Nao";
			strcpy(vagas[i].preenchida, nao);

			(*numeroRegistros)++;
			system("cls");

			printf("SUCESSO.");	
			break;
		}
	}

	
	printf("\n\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");
	
}

void finalizarVaga(Vaga *vagas, int numeroRegistros){
	
	int codigoVaga=0;
	char sim[5] = "Sim";
	
	printf("CODIGO DA VAGA: ");
	scanf("%i", &codigoVaga);
	
	for(int i=0; i<=numeroRegistros; i++){
		if(codigoVaga == vagas[i].codigo){
			
			strcpy(vagas[i].preenchida, sim);
			
		}
	}
	
	printf("\n\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");
	
}

void listarVagas(Vaga *vagas, int numeroRegistros){
	
	int opcao;
	char nao[5] = "Nao";
	
	do{
		printf(" IDIOMA: ");
		printf("\n1. Portugues");
		printf("\n2. Ingles");
		printf("\n3. Frances");
		printf("\n4. Espanhol");
		printf("\n5. Italiano");
		printf("\n6. VOLTAR\n");
		printf("\n >> ");
		scanf("%i", &opcao);
		
		if(opcao!=6){
			
			for(int i=0; i<numeroRegistros; i++){				
					if(opcao == vagas[i].idioma && strcmp(vagas[i].preenchida, nao)==0){
					
						printf("\n\n --- %s --- \n", vagas[i].funcao);
						printf(" CODIGO: %i\n", vagas[i].codigo);
						printf(" LOCAL: %s\n", vagas[i].local);
						printf(" PREENCHIDA: %s\n", vagas[i].preenchida);
						printf(" IDIOMAS: %i\n", vagas[i].idioma);
						printf(" ------------------------ \n\n");
					}
			}
		}	
		
	}while(opcao!=6);
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
	system("cls");
	
}

