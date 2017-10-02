	#include <stdio.h>
	#include <stdlib.h>
	
	void imprimir(int *p, int tamanho);
	
	int main()
	{
	   int *p, tamanho, i;
	   
	   printf("Digite o tamanho do vetor: ");
	   scanf("%i", &tamanho);
	  
	   p = (int *) malloc(tamanho * sizeof(int));
	  
	   if (!p){
          printf ("** Erro: Memoria Insuficiente **\n");
          exit;
       }else{
          printf ("** Memoria Alocada com Sucesso **\n");
       } 
	   
	   for(i=0; i < tamanho; i ++)
	   {
	   	       //*(p+i) = i;
   	           p[i] = i;
	   }
	  
	   imprimir(p, tamanho);
	   
	   free(p);
	   printf ("\n** Memoria Liberada com Sucesso **\n");
    }




    void imprimir(int *ptr, int tamanho)
    {
    	int i;
    	
    	for(i=0; i < tamanho; i++)
    	   //printf(" %i ", *ptr++);
    	   printf(" %i ", ptr[i]);
	}
 
