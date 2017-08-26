#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int entrada, rest;
	
	printf("Informe o ano: ");
	scanf("%i", &entrada);
	
	if(entrada > 1984){
		
		rest = (entrada - 1984) % 86;
		
		if(rest == 0){
			printf("\nPassa esse ano. \n", rest);
		}else if(rest == 1){
			printf("\nFalta %i ano.\n", 86-rest);
		}else{
			printf("\nFaltam %i anos.\n", 86-rest);
		}
		
	}
	
	return 0;
}
