#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i, j, L;
	char T[5];
	double M[12][12], soma=0.0;
	
	scanf("%i", &L);
	scanf("%s", &T);
	
	for(i=0; i<12; i++)
	for(j=0; j<12; j++)
	scanf("%lf", &M[i][j]);
	
	for(j=0; j<12; j++)
	soma += M[L][j];
	
	if(T[0]=='M')
	soma = soma/12.0;
	
	printf("%.1lf\n", soma);
	
	system("pause");
	return 0;
}
