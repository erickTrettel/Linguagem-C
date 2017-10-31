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

   p = (data *) malloc(sizeof(data));

   if (!p){
          printf ("** Erro: Memoria Insuficiente **\n");
   }

   scanf("%i %i %i", &p->dia, &p->mes, &p->ano);


   printf("%i %i %i", p->dia, p->mes, p->ano);

   free(p);
   return 0;
}
