#include <stdio.h>
#include <stdlib.h>


typedef struct{
      int dia;
      int mes;
      int ano;
} data;




data somaEvento (data inicio);



int main(void)
{

 	data a, b;

	scanf ("%d %d %d", &a.dia, &a.mes, &a.ano);

	b = somaEvento (a);

	printf ("%d %d %d\n", a.dia, a.mes, a.ano);
	printf ("%d %d %d\n", b.dia, b.mes, b.ano);

   return 0;
}


data somaEvento (data a) {
   data b;

   b.dia = a.dia + 1;
   b.mes = a.mes + 1;
   b.ano = a.ano + 1;

   a.dia = a.dia + 10;

   return b;
}
