#include <stdio.h>
#include <stdlib.h>

int main(){
	int valor, anos, meses, dias;
	
	scanf("%i", &valor);
	
	anos = valor/365;
	meses = (valor%365)/30;
	dias = (valor%365)-(30*meses);
	
	printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n", anos, meses, dias);
	
	return 0;	
}
