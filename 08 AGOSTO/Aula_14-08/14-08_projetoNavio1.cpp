#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int setor1(){
	int setor1[16], contContainer = 0, i = 0, pesoContainer = 0, funcaoLogica = 1, pesoTotal = 0;
	char respostaUsuario[2], comparador[2] = "s";
	
	for(int j = 0; j<16; j++){
		setor1[j] = 0;
	}
	
	printf("\n---------- SETOR 1 ----------\n");
	
	do{
		if(contContainer >= 16){
			printf("\nVocê atingiu o limite de containers nesse setor\n");
			break;
		}else{
			printf("\nInforme o peso do container em toneladas (Min:1 - Max: 15): ");
			scanf("%d", &pesoContainer);
			
			if(pesoContainer < 1 || pesoContainer > 15){
				printf("\nValor inválido");
				fflush(stdin);
				printf("\nDeseja continuar? (s/n): ");
				gets(respostaUsuario);
			}else{
				contContainer++;
				setor1[i] = pesoContainer;
				fflush(stdin);
				printf("Deseja continuar? (s/n): ");
				gets(respostaUsuario);
			}
				
			funcaoLogica = strcmp(respostaUsuario, comparador);
		}
		
		i++;
	}while(funcaoLogica == 0);
	
	for(int j = 0; j<16; j++){
		pesoTotal += setor1[j];
	}
	
	return pesoTotal;
}

int setor2(){
	
	int setor2[16], contContainer = 0, i = 0, pesoContainer = 0, funcaoLogica = 1, pesoTotal = 0;
	char respostaUsuario[2], comparador[2] = "s";
	
	for(int j = 0; j<16; j++){
		setor2[j] = 0;
	}
	
	printf("\n---------- SETOR 2 ----------\n");
	
	do{
		if(contContainer >= 16){
			printf("\nVocê atingiu o limite de containers nesse setor\n");
			break;
		}else{
			printf("\nInforme o peso do container em toneladas (Min:1 - Max: 15): ");
			scanf("%d", &pesoContainer);
			
			if(pesoContainer < 1 || pesoContainer > 15){
				printf("\nValor inválido");
				fflush(stdin);
				printf("\nDeseja continuar? (s/n): ");
				gets(respostaUsuario);
			}else{
				contContainer++;
				setor2[i] = pesoContainer;
				fflush(stdin);
				printf("Deseja continuar? (s/n): ");
				gets(respostaUsuario);
			}
				
			funcaoLogica = strcmp(respostaUsuario, comparador);
		}
		
		i++;
	}while(funcaoLogica == 0);
	
	for(int j = 0; j<16; j++){
		pesoTotal += setor2[j];
	}
	
	return pesoTotal;
	
}

int setor3(){
	
	int setor3[16], contContainer = 0, i = 0, pesoContainer = 0, funcaoLogica = 1, pesoTotal = 0;
	char respostaUsuario[2], comparador[2] = "s";
	
	for(int j = 0; j<16; j++){
		setor3[j] = 0;
	}
	
	printf("\n---------- SETOR 3 ----------\n");
	
	do{
		if(contContainer >= 16){
			printf("\nVocê atingiu o limite de containers nesse setor\n");
			break;
		}else{
			printf("\nInforme o peso do container em toneladas (Min:1 - Max: 15): ");
			scanf("%d", &pesoContainer);
			
			if(pesoContainer < 1 || pesoContainer > 15){
				printf("\nValor inválido");
				fflush(stdin);
				printf("\nDeseja continuar? (s/n): ");
				gets(respostaUsuario);
			}else{
				contContainer++;
				setor3[i] = pesoContainer;
				fflush(stdin);
				printf("Deseja continuar? (s/n): ");
				gets(respostaUsuario);
			}
				
			funcaoLogica = strcmp(respostaUsuario, comparador);
		}
		
		i++;
	}while(funcaoLogica == 0);
	
	for(int j = 0; j<16; j++){
		pesoTotal += setor3[j];
	}
	
	return pesoTotal;
	
}

int setor4(){
	
	int setor4[16], contContainer = 0, i = 0, pesoContainer = 0, funcaoLogica = 1, pesoTotal = 0;
	char respostaUsuario[2], comparador[2] = "s";
	
	for(int j = 0; j<16; j++){
		setor4[j] = 0;
	}
	
	printf("\n---------- SETOR 4 ----------\n");
	
	do{
		if(contContainer >= 16){
			printf("\nVocê atingiu o limite de containers nesse setor\n");
			break;
		}else{
			printf("\nInforme o peso do container em toneladas (Min:1 - Max: 15): ");
			scanf("%d", &pesoContainer);
			
			if(pesoContainer < 1 || pesoContainer > 15){
				printf("\nValor inválido");
				fflush(stdin);
				printf("\nDeseja continuar? (s/n): ");
				gets(respostaUsuario);
			}else{
				contContainer++;
				setor4[i] = pesoContainer;
				fflush(stdin);
				printf("\nDeseja continuar? (s/n): ");
				gets(respostaUsuario);
			}
				
			funcaoLogica = strcmp(respostaUsuario, comparador);
		}
		
		i++;
	}while(funcaoLogica == 0);
	
	for(int j = 0; j<16; j++){
		pesoTotal += setor4[j];
	}
	
	return pesoTotal;
	
}

int verificarMaiorPeso(int pesoSetor1, int pesoSetor2, int pesoSetor3, int pesoSetor4){
	int vetorMaior[4], maior = 0;
	
	vetorMaior[0] = pesoSetor1;
	vetorMaior[1] = pesoSetor2;
	vetorMaior[2] = pesoSetor3;
	vetorMaior[3] = pesoSetor4;
	
	for(int i = 0; i<4; i++){
		if(vetorMaior[i] > maior){
			maior = vetorMaior[i];
		}else{
			maior = maior;
		}
	}
	
	return maior;
}

int verificarMenorPeso(int pesoSetor1, int pesoSetor2, int pesoSetor3, int pesoSetor4){
	
	int vetorMenor[4], menor = 250;
	vetorMenor[0] = pesoSetor1;
	vetorMenor[1] = pesoSetor2;
	vetorMenor[2] = pesoSetor3;
	vetorMenor[3] = pesoSetor4;
	
	for(int i = 0; i<4; i++){
		if(vetorMenor[i] < menor){
			menor = vetorMenor[i];
		}else{
			menor = menor;
		}
	}
	
	return menor;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int escolhaUsuario = 0, pesoSetor1 = 0, pesoSetor2 = 0, pesoSetor3 = 0, pesoSetor4 = 0, maiorPeso = 0, menorPeso = 0;
	printf("SETOR 1 - \nSETOR 2 - \nSETOR 3 - \nSETOR 4 - \nEsolha um setor: ");
	scanf("%d", &escolhaUsuario);
	
	switch(escolhaUsuario){
		case 1:
			pesoSetor1 = setor1();
			//break;
		case 2:
			pesoSetor2 = setor2();
			//break;
		case 3:
			pesoSetor3 = setor3();
			//break;
		case 4:
			pesoSetor4 = setor4();
			break;
		default:
			printf("Valor inválido\nDigite um valor de 1-4 correspondente ao setor desejado\n");
			break;
	}
	
	printf("\n\n ---------- ESTATÍSTICAS ----------\n");
	printf("Peso total do setor 1: %d\n", pesoSetor1);
	printf("Peso total do setor 2: %d\n", pesoSetor2);
	printf("Peso total do setor 3: %d\n", pesoSetor3);
	printf("Peso total do setor 4: %d\n", pesoSetor4);
	
	maiorPeso = verificarMaiorPeso(pesoSetor1, pesoSetor2, pesoSetor3, pesoSetor4);
	menorPeso = verificarMenorPeso(pesoSetor1, pesoSetor2, pesoSetor3, pesoSetor4);
	
	printf("\nMaior peso: %d\nMenor Peso: %d", maiorPeso, menorPeso);
	
	int difPesos = maiorPeso - menorPeso;
	
	if(difPesos > 15){
		printf("\n\nO navio corre risco de afundar. Reveja a distribuição dos containers!");
	}else{
		printf("\n\nCarregamento completo. Tudo de acordo");
	}
	
	return 0;
}
