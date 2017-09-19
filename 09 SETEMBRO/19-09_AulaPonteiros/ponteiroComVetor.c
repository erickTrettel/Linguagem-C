	#include <stdio.h>

	int somaVetor(int *vet, int tam);

	int main(void)
	{
         int vet1[10], vet2[20], i;
         int somaVet1, somaVet2;

         for(i=0; i < 10; i++){
            vet1[i] = 1;
         }

         for(i=0; i < 20; i++){
            vet2[i] = 1;
         }

         //Passagem por referencia
         somaVet1 = somaVetor(vet1, 10);
         somaVet2 = somaVetor(vet2, 20);

         printf("\nO somatorio do vetor 1 e %i", somaVet1);
         printf("\nO somatorio do vetor 2 e %i", somaVet2);


        printf("\n*****************************\n");
        for(i=0; i < 10; i++){
          printf(" %i", vet2[i]);
	    }
        printf("\n*****************************\n");
        for(i=0; i < 20; i++){
          printf(" %i", vet2[i]);
	    }

		 return 0;
	}

	int somaVetor(int *vet, int tam){
	   int i, soma=0;

	   for(i=0; i < tam; i++){
          soma = soma + vet[i];
	   }

	   return soma;
	}













