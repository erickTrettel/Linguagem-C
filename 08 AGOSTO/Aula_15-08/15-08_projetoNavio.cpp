#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int pesoContainer, funcaoLogica = 1, setor[4], contContainer[4], contador = 0, maior = 0, menor = 250, boleana[4];
	char respostaUsuario[2], ref[2] = "s";
	
	//Inserir o valor 0 no vetor
	for(int i = 0; i<4; i++){
		setor[i] = 0;
		contContainer[i] = 0;
		boleana[i] = 0;
	}
	
	printf("---------- CARREGAMENTO DE NAVIO ----------\n\n");
	
	do{		
		printf("Digite o peso do contâiner: ");
		scanf("%d", &pesoContainer);
		
		//Verifica o maior peso entre os setores
		for(int i = 0; i<4; i++){
			if(setor[i] > maior){
				maior = setor[i];
			}
		}
				
		menor = 250;
		//Verifica o menor peso entre os setores
		for(int i = 0; i<4; i++){
			if(setor[i] < menor){
				menor = setor[i];
			}
		}
		
		if(maior - menor > 15){
			for(int i = 0; i<100; i++){
				putchar('\n');
			
			}
			
			printf("\n\n---------- SEU NAVIO AFUNDOU ----------\n\n");
			
			for(int i = 0; i<10; i++){
				putchar('\n');
			}
		}
		
		if(pesoContainer < 1 || pesoContainer > 15){
			for(int i = 0; i<100; i++){
				putchar('\n');
			}
			
			printf("\n.-- O peso do contâiner deve estar entre 1 e 15 toneladas --.\n");
		}else{
			if(contador <= 3){
				for(int i = 0; i<100; i++){
					putchar('\n');
				}
				//Armazenar nos primeiros setores
				setor[contador] = pesoContainer;
				contContainer[contador]++;
				printf("\n*O contâiner foi armazenado no setor %d", contador+1);
				printf("\n*O setor contém %d contâiners", contContainer[contador]);
				printf("\n*Peso total do setor: %d", setor[contador]);
				contador++;	
			}else{								
				for(int i = 0; i<4; i++){
					if(contContainer[i] >= 16){
						boleana[i] = 1;
					}
					
					if(setor[i] == menor && boleana[i] == 0){						
						setor[i] += pesoContainer;
						contContainer[i]++;
						for(int i = 0; i<100; i++){
							putchar('\n');
						}
						printf("\n*O contâiner foi armazenado no setor %d", i+1);
						printf("\n*O setor %d contém %d contâiners", i+1, contContainer[i]);
						printf("\n*Peso total do setor %d: %d", i+1, setor[i]);
						break;
					}else{
						
					}
				}
				
				//Verifica se todos os containers foram preenhidos
				if(boleana[0] == 1 && boleana[0] == boleana[1] && boleana[1] == boleana[2] && boleana[2] == boleana[3]){
					for(int i = 0; i<100; i++){
						putchar('\n');
					}
					printf("\n.-- Todos os containers foram totalmente preenchidos --.\n");
					for(int i = 0; i<10; i++){
						putchar('\n');
					}
					break;
				}
			}
		}
		for(int i = 0; i<10; i++){
			putchar('\n');
		}
		fflush(stdin);
		printf("\n\nDeseja continuar? (s/n): ");
		gets(respostaUsuario);
		
		funcaoLogica = strcmp(respostaUsuario, ref);
	}while(funcaoLogica == 0);
	
	for(int i = 0; i<100; i++){
		putchar('\n');
	}
	
	printf("\n---------- ESTATÍSTICAS ----------");
	printf("\n\nPesos - \nSETOR 1: %d toneladas --> %d contâiners", setor[0], contContainer[0]);
	printf("\nSETOR 2: %d toneladas --> %d contâiners", setor[1], contContainer[1]);
	printf("\nSETOR 3: %d toneladas --> %d contâiners", setor[2], contContainer[2]);
	printf("\nSETOR 4: %d toneladas --> %d contâiners", setor[3], contContainer[3]);
	printf("\n\n---------- FIM DE CARREGAMENTO ----------");
	
	for(int i = 0; i<10; i++){
		putchar('\n');
	}
	
	system("PAUSE");
	return 0;
}
