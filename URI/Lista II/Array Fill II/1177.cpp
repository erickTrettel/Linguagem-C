#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int T, N[1000], i, j=0;
	
	for(i=0; i<1000; i++){
		N[i]=0;
	}
	
	scanf("%i", &T);
	
	if(T>=2 && T<=50){
		for(i=0; i<1000; i++, j++){
			if(j==T){
				j=0;
				N[i]=j;
			}else{
				N[i] = j;
			}
		}
		
		for(i=0; i<1000; i++){
			printf("N[%i] = %i\n", i, N[i]);
		}
	}
	
	return 0;
}
