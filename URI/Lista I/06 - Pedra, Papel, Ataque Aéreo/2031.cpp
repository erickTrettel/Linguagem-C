#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, i;
	char jogador1[10], jogador2[10];
	
	scanf("%i", &N);
	
	if(N>1 || N<1000){
		for(i=0; i<N; i++){
			scanf("%s", jogador1);
			scanf("%s", jogador2);
		
			if(strcmp(jogador1, "ataque")==0 && strcmp(jogador2, "ataque")==0)
				printf("Aniquilacao mutua\n");
			else if(strcmp(jogador1, "pedra")==0 && strcmp(jogador2, "pedra")==0)
				printf("Sem ganhador\n");
			else if(strcmp(jogador1, "papel")==0 && strcmp(jogador2, "papel")==0)
				printf("Ambos venceram\n");
			else if(strcmp(jogador1, "ataque")==0 && strcmp(jogador2, "papel")==0 || strcmp(jogador1, "ataque")==0 && strcmp(jogador2, "pedra")==0 || strcmp(jogador1, "pedra")==0 && strcmp(jogador2, "papel")==0)
				printf("Jogador 1 venceu\n");
			else if(strcmp(jogador2, "ataque")==0 && strcmp(jogador1, "papel")==0 || strcmp(jogador2, "ataque")==0 && strcmp(jogador1, "pedra")==0 || strcmp(jogador2, "pedra")==0 && strcmp(jogador1, "papel")==0)
				printf("Jogador 2 venceu\n");
		}	
	}
	
	return 0;
}
