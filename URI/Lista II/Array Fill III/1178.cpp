#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i;
	double N[100], Y;
	
	for(i=0; i<100; i++){
		N[i] = 0;
	}
	
	scanf("%lf", &N[0]);
	Y=N[0];
	for(i=0; i<100; i++){
		printf("N[%i] = %.4lf\n", i, Y);
		Y=Y/2;
	}
	
	return 0;
}
