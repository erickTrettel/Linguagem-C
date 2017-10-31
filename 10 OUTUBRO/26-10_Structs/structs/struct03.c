#include <stdio.h>
#include <stdlib.h>

typedef struct {
      int dia;
      int mes;
      int ano;
} data;

void imprimeData(data *inicio, int tam);

int main(void)
{
    data a[5];
    int i;

    for(i=0; i < 5; i++){
    	scanf ("%d %d %d", &a[i].dia, &a[i].mes, &a[i].ano);
	}

	imprimeData(a, 5);

   return 0;
}

void imprimeData(data * a, int tam) {

   int i;

   for(i=0; i< tam; i++){
   	   printf ("%d %d %d\n", a[i].dia, a[i].mes, a[i].ano);
   }

}
