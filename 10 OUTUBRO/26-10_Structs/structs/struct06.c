
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
   int tamanho, novoTamanho,i;

   printf("Digite o tamanho inicial: ");
   scanf("%i",&tamanho);
   p = (data *) malloc(tamanho * sizeof(data));

   if (!p){
          printf ("** Erro: Memoria Insuficiente **\n");
   }

   for(i=0; i < tamanho; i++)
   scanf("%i %i %i", &p[i].dia, &p[i].mes, &p[i].ano);

   for(i=0; i< tamanho; i++)
     printf("\n%i %i %i",  p[i].dia, p[i].mes, p[i].ano);

   printf("\nDigite um novo tamanho: ");
   scanf("%i",&novoTamanho);
   p = (data *) realloc(p, novoTamanho * sizeof(data));


   //Verifica se o novo tamanho e maior que o tamanho atual
   if(novoTamanho > tamanho)
   {
     for(i=tamanho; i < novoTamanho; i++)
       scanf("%i %i %i", &p[i].dia, &p[i].mes, &p[i].ano);
   }

   //Imprime o struct com o novo tamanho
   for(i=0; i< novoTamanho; i++)
     printf("\n%i %i %i",  p[i].dia, p[i].mes, p[i].ano);





   printf("\n");

   free(p);
   return 0;
}
