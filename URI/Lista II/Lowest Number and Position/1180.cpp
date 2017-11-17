#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, N, menor=1000, pos=0;;
	
	scanf("%i", &N);
	
	if(N>1 && N<1000){
		int X[N];
		
		for(i=0; i<N-1; i++){
			scanf("%i ", &X[i]);
		}
		
		for(i=0; i<N; i++){
			if(menor < X[i]){
				menor=menor;
			}else{
				menor=X[i];
				pos=i;
			}
		}
		
		printf("Menor valor: %i\nPosicao: %i\n", menor, pos);
	}
	
	return 0;
}
