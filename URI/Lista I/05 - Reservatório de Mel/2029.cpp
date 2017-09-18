#include <stdio.h>
#include <stdlib.h>

int main(){
	double V, D, altura, area;
	
	while (scanf("%lf%lf", &V, &D) != EOF ) {
		
		area = 3.14 * ((D/2) * (D/2));

        altura = V / (3.14*((D/2) * (D/2)));
		
		printf("ALTURA = %.2lf\n", altura);
		printf("AREA = %.2lf\n", area);	
	}
	return 0;
}
