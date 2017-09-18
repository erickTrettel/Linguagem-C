#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int S, T, F, res=0;
	
	scanf("%i %i %i", &S, &T, &F);
	
	res = S+T+F;
	
	res = res%24;
	
	if(res<0){
		res = res+24;
	}
	
	printf("%i\n", res);
	
	return 0;
}
