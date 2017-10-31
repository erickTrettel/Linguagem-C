#include <stdio.h>
#include <stdlib.h>


//Struct
typedef struct {
      int dia;
      int mes;
      int ano;
} data;


//Funcao
data somaEvento (data *inicio);



int main(void)
{
    data a, b;

	scanf ("%d %d %d", &a.dia, &a.mes, &a.ano);

	b = somaEvento (&a);

	printf ("%d %d %d\n", a.dia, a.mes, a.ano);
	printf ("%d %d %d\n", b.dia, b.mes, b.ano);

   return 0;
}


data somaEvento (data * inicio) {
   data fim;

   fim.dia = inicio->dia + 1; //fim.dia = (*inicio).dia + 1;
   fim.mes = inicio->mes + 1; //fim.mes = (*inicio).mes + 1;
   fim.ano = inicio->ano + 1; //fim.ano = (*inicio).ano + 1;

   inicio->dia = inicio->dia + 10;

   return fim;
}
