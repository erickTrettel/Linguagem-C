#include <stdio.h>
#include <stdlib.h>


typedef struct {
      int dia;
      int mes;
      int ano;
} data;



int main(void)
{
   data *p;
   int tamanho, i;

   scanf("%i",&tamanho);

   p = (data *) malloc(tamanho * sizeof(data));

   if (!p){
          printf ("** Erro: Memoria Insuficiente **\n");
   }

   for(i=0; i < tamanho; i++)
   scanf("%i %i %i", &p[i].dia, &p[i].mes, &p[i].ano);

   for(i=0; i< tamanho; i++)
     printf("\n%i %i %i",  p[i].dia, p[i].mes, p[i].ano);

   printf("\n");

   free(p);
   return 0;
}
