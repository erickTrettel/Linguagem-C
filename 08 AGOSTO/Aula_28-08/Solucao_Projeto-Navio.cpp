#include <stdio.h>
	
#define TAM_SETOR      			16
#define QUANT_SETOR    			4
#define TAM_NAVIO      			TAM_SETOR * QUANT_SETOR
#define PESO_MIN_CONTAINER  	1
#define PESO_MAX_CONTAINER  	15
#define MAX_DIFERENCA_SETOR  	15

//Funcoes	
void imprimirSetores(float navio[TAM_NAVIO]);
float calculaPesoMaiorSetor(float navio[TAM_NAVIO]);
int verificaDisponibilidadeSetor(float navio[TAM_NAVIO], int setor);
float calculaPesoSetor(float navio[TAM_NAVIO],int setor);
int armazenaContainer(float navio[TAM_NAVIO],float container, int setor);
int pesquisaSetorMaisLeve(float navio[TAM_NAVIO], int index);
		
/* Funcao main */
int main(void)
{

    float navio[TAM_NAVIO];
		 
 	int i, setorMaisLeveDisponivel, continua, afunda, index, totalContainersArmazenados=0;
	float container=1, pesoMaiorSetor, pesoSetor;
		 
	 //Inicializa navio com 0
	for(i=0; i < TAM_NAVIO; i++)
	 	navio[i]=0;
		 
		 
	//Carrega o navio	
	while(container != 0 && totalContainersArmazenados < TAM_NAVIO)
	{
	
	 	//Imprime setores do navio
	 	imprimirSetores(navio);
		 	
	 	//L? um novo container
	   	printf("\n\nDigite o peso do container ou zero para sair: ");
	   	scanf("%f", &container);

        //Verifica se o peso do container e' valido
	  	if(container >= PESO_MIN_CONTAINER && container <= PESO_MAX_CONTAINER)
	 	{
	 		printf("Tenta guarda o container de peso = %f.", container);
		 	   
		 	    
			//Acha o setor mais pesado do navio 
			pesoMaiorSetor = calculaPesoMaiorSetor(navio);
		 	    
	 	    printf("\nPeso do maior setor %f", pesoMaiorSetor);
				
			index=0; 
			continua = 1;
				
			//Tenta armazenar o container no navio
			while(index < QUANT_SETOR  && continua == 1)
			{
			
				//Encontra o setor mais leve do navio pelo
				//Se index = 0 retorna o primeiro setor mais leve
   				//Se index = 1 retorna o segundo setor mais leve
   				//Se index = 2 retorna o terceiro setor mais leve
   				//Se index = 3 retorna o quarto e ultimo setor mais leve
				setorMaisLeveDisponivel = pesquisaSetorMaisLeve(navio,index);
		             
				 //Verifica se tem espaco no setor
				if(verificaDisponibilidadeSetor(navio, setorMaisLeveDisponivel))
				{
		                  
		            afunda = 0;
				    pesoSetor = calculaPesoSetor(navio, setorMaisLeveDisponivel);
						  
					float aux;
						  
					//Verifica se afunda o navio
					for(i=0; i < QUANT_SETOR; i++)
					{
					  	aux = calculaPesoSetor(navio, i);
						
					    if(pesoSetor + container  - aux > MAX_DIFERENCA_SETOR)
						  afunda = 1; 
					} 
		             
				    //Pode armazenar  ?
					if(afunda == 0)     	  
					{
					  	armazenaContainer(navio,container, setorMaisLeveDisponivel);
					    continua = 0;
					  	totalContainersArmazenados++;
					}
				}
				else
				{
				 	printf("\nErro: Setor %i cheio.", setorMaisLeveDisponivel);
				}	            
			    index++;
			}
				
			if(continua == 0)
			   printf("\nContainer armazenado com sucesso no setor %i", setorMaisLeveDisponivel);			    
			else
			{
			    //Se container tiver peso 1 ent?o ent?o n?o ? possivel armazenar mais container no navio
			   	if(container == 1)
				{
			   		
			       printf("\nNao foi possivel qualquer novo container no navio pois ele afunda");	
			   
				   //Zera para finalizar a aplica??o
				   container = 0;		    	 	
				}
				else
				{
					printf("\nNao foi possivel armazenar no container no navio pois ele afunda");			    	
				   	printf("\nDigite um valor menor");			    	
				}
			}
				   
		    if(totalContainersArmazenados == TAM_NAVIO)
			   	printf("\nFIM: O NAVIO ESTA COM A CARGA COMPLETA!!!!");			    			    
		}
		else
		{
		    if(container != 0)
		        printf("\nPeso do container invalido!!!");
		}	 			
	}
	return 0;   
}

/*
   Pesquisa o setor mais leve disponivel a partir do setor indicado pelo index
   Se index = 0 retorna o primeiro setor mais leve
   Se index = 1 retorna o segundo setor mais leve
   Se index = 2 retorna o terceiro setor mais leve
   Se index = 3 retorna o quarto e ultimo setor mais leve
*/
int pesquisaSetorMaisLeve(float navio[TAM_NAVIO], int index){
	
	int i,j;
    float pesos[QUANT_SETOR], pesosOrdenados[QUANT_SETOR], troca;
    int setor;
	
	//Soma todos os pesos de cada setor
	for(i=0; i < QUANT_SETOR; i++)
	{
	    pesos[i]=calculaPesoSetor(navio, i);
    	pesosOrdenados[i]=pesos[i];
   	}
   	
   	//ordena setores pelo peso
   	for(i=0; i < QUANT_SETOR; i++)
   	    for(j=i+1; j < QUANT_SETOR; j++)
   	    	if(pesosOrdenados[i] > pesosOrdenados[j])
		 	{
   	     		troca    = pesosOrdenados[i];
   	     		pesosOrdenados[i] = pesosOrdenados[j];
   	     		pesosOrdenados[j] = troca;
			}
		
	//Busca pelo setor mais leve uando a regra do index
	for(i=0; i < TAM_SETOR; i ++)
	{
		if(pesos[i] == pesosOrdenados[index])
		{
			setor = i;
			break;
		}
	}
	return setor;	
}

/* Armazena o containe no navio no setor informado

return 1 se armazenou com sucesso no setor
return 0 se NAO armazenou no setor

*/
int armazenaContainer(float navio[TAM_NAVIO], float container, int setor)
{
	int disponivel;
	int sucesso = 0;
	 
	if(verificaDisponibilidadeSetor(navio,setor))
	{
	 	 //Posiciona o vetor no inicio do setor
	 	 disponivel = setor * TAM_SETOR;
	 	 
	 	 //Acha a posicao disponivel no setor informado
	 	while(navio[disponivel] != 0)
		{
	 		disponivel++;
	 	}
	 	
		navio[disponivel] = container;
	 	
		sucesso = 1;
   }
	 
	 //Retorna se conseguiu armazenar o container no setor
	 return sucesso;
}


/* 
  Verifica disponivilidade do setor
  
  return 1 se disponivel
  return 0 se nao disponivel
  
*/
int verificaDisponibilidadeSetor(float navio[TAM_NAVIO], int setor)
{
   	
   	int cont=0, i;
   	   
   	i=TAM_SETOR*setor;
   	   
   	while(navio[i] != 0 && cont < TAM_SETOR)
	{
   	    i++;	
   	    cont ++;
	}  
   	   
   	return cont != TAM_SETOR;
}

/*
  Imprime os dados de todos os setores
*/
void imprimirSetores(float navio[TAM_NAVIO])
{
		
	int i, j;
	float soma;
		
	for(j=0; j < QUANT_SETOR; j++)
	{
		printf("\n\n\t\tNavio Setor %i: ", j+1); 
	    soma = 0;
		    
		for(i=TAM_SETOR*j;  i < TAM_SETOR*j+TAM_SETOR;   i++)
		{
			   printf("%.2f ", navio[i]);
			   soma = soma + navio[i];
		}
		printf("\n\t\tPeso Total do Setor %i: %.2f", j+1, soma);
	}
		 
}



/*
   Devolve o peso do maior setor do navio
*/
float calculaPesoMaiorSetor(float navio[TAM_NAVIO])
{
	float maior=0 , soma;
    int i,j;
    
    
    //Defini o peso do setor 1 como o mais pesado inicialmente
    maior = calculaPesoSetor(navio, 0);

    //Controla o setor, comecando pelo segundo setor	
	for(int i=1; i < QUANT_SETOR; i++)
	{
	   
	   soma = calculaPesoSetor(navio,i);
	   
	   //Verifica se e o maior
	   if(maior < soma)
	       maior = soma;
	}
	   	      
	return maior;

}

/*
  Calcula o peso de um setor
*/
float calculaPesoSetor(float navio[TAM_NAVIO],int setor)
{
	
    float soma = 0;
	   
	//Soma o peso total do setor
	for(int j =0; j < TAM_SETOR; j++)
	{
	    soma = soma + navio[j+(setor*TAM_SETOR)];	
	}	
	
	return soma;
}
