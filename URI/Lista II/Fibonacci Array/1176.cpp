#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int T, N, i, j;
	int a, b, aux=0;
	scanf("%d", &T);

	for(i=0; i<T; i++){
		scanf("%d", &N);
		
		a = 1;
		b = 0;
		for(j=0; j<N; j++){
			aux = a + b;
			a = b;
			b = aux;
		}

		printf("Fib(%d) = %d\n", N, aux);
	}
	
	return 0;
}
