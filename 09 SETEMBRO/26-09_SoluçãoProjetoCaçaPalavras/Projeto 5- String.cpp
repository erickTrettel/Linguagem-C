#include <stdio.h>
#include <string.h>



//LIN e COL devem ser do mesmo tamanho
#define LIN 5
#define COL LIN
#define MAX LIN * COL


	
void recebeMatriz(char busca[LIN][COL]);
void imprimeMatriz(char matriz[LIN][COL]);
int  pesquisaMatriz(char busca[31],char matriz[LIN][COL]);
int  pesquisaLinhas(char busca[31],char matriz[LIN][COL]);
int  pesquisaColunas(char busca[31],char matriz[LIN][COL]);
int  pesquisaDiagonais(char busca[31],char matriz[LIN][COL]);
int  pesquisaDiagonalPrincipal(char busca[31],char matriz[LIN][COL]);
int  pesquisaDiagonalInferior(char busca[31],char matriz[LIN][COL]);
int  pesquisa(char busca[31],char linha[COL+1]);
int  pesquisaDiagonalSuperior(char busca[31],char matriz[LIN][COL]);
void inverteStr(char texto[31]);
	
		
int main()
{
        
	 char matriz[LIN][COL];
	 char pesquisa[31];
     int lin=0, col=0;
     int total=0;
	 int i,j;

	 recebeMatriz(matriz);
	   
     do{
        
	    imprimeMatriz(matriz);     		
	    
		printf("\nDigite a pesquisa: ");
       	gets(pesquisa);
        	
       	if(strcmp(pesquisa,"0") != 0) {
       	    total = pesquisaMatriz(pesquisa,matriz);
       		printf("\nO total de ocorrencias de %s na matriz e %i.", pesquisa, total);
		}
        	
	 }while(strcmp(pesquisa,"0") != 0);
       
     return 0;   
	}


/*
   Pesquisa de fato e retorna o total de ocorrencias
*/   
int  pesquisa(char busca[31], char linha[LIN+1])
{
     int i,j, tam, total=0;
     char dadosLinha[31];
	 
	 tam = strlen(busca);
	 
	 for(j=0; j + tam <= COL; j++){
	    	    
		memcpy(dadosLinha, &linha[j], tam); 	
	    dadosLinha[tam] = '\0';
	    		
	 			
	   	if(strcmp(busca,dadosLinha) ==0){
		    total++;
		}	
				
		inverteStr(dadosLinha);
				
		if(strcmp(busca,dadosLinha) ==0)
		{
			      total++;
		}
	 }
	 
	 return total;
}

/*
   Funcao principal para pesquisar na matriz
*/
int  pesquisaMatriz(char busca[31],char matriz[LIN][COL])
{
	int total=0;

	total += pesquisaLinhas (busca,matriz);
    total += pesquisaColunas(busca,matriz);
    total += pesquisaDiagonais(busca,matriz);
    
	return total;
}

/*
   Funcao que pesquisa somente nas linhas
*/
int  pesquisaLinhas(char busca[31],char matriz[LIN][COL])
{
	
	int  i;
	char dadosLinha[COL+1];
	int  total=0;
	   
	for(i=0; i<LIN; i++) {
	    memcpy(dadosLinha, &matriz[i][0], COL); 	
	    dadosLinha[COL+1]='\0';
	    total += pesquisa(busca, dadosLinha);
	}
	
	return total;
}

/* 
   Funcao que pesquisa nas colunas
*/
int  pesquisaColunas(char busca[31],char matriz[LIN][COL])
{
	char aux[LIN][COL];
	int i,j;
	
	//Inverte linha e coluna da matriz
	for(i=0; i < LIN; i++)
	   for(j=0; j < COL; j++)
	        aux[j][i] = matriz[i][j];
	       
	
	return pesquisaLinhas(busca, aux);
	
}


/*
   Inverte o texto recebido para fazer a busca inversa
*/
void inverteStr(char texto);
	char aux[31];
	int i;
	
	//Inverte
	for(i=0; i < tam; i++)
	{
		aux[i] = texto[tam-i-1];
	}
	
	//Altera
	for(i=0; i < tam; i++)
	{
		texto[i] = aux[i];
	}
	
}


/*
   Pesquisa nas diagonais
*/
int  pesquisaDiagonais(char busca[31],char matriz[LIN][COL])
{
	int total = 0;
	char aux[LIN][COL];
	int i,j;
	
	total += pesquisaDiagonalPrincipal(busca,matriz);
    total += pesquisaDiagonalInferior(busca,matriz);
    total += pesquisaDiagonalSuperior(busca,matriz);
    
    
    //Espelha linha e coluna da matriz
	for(i=0; i < LIN; i++)
	   for(j=0; j < COL; j++)
	        aux[i][COL-1-j] = matriz[i][j];
	
	
    total += pesquisaDiagonalPrincipal(busca,aux);
    total += pesquisaDiagonalInferior(busca,aux);
    total += pesquisaDiagonalSuperior(busca,aux);
	
	return total;
}

/*
  Pesquisa na Diagonal principal
*/

int  pesquisaDiagonalPrincipal(char busca[31],char matriz[LIN][COL])
{
	char aux[COL], i;
	
	for(i=0;i<COL;i++)
	     aux[i]=matriz[i][i];
	     
	aux[COL]='\0';
	
	return pesquisa(busca,aux);     
}


/*
  Pesquisa nas diagonais superior
*/
int  pesquisaDiagonalSuperior(char busca[31],char matriz[LIN][COL])
{
	int  lin,col,aux;
    int  total =0;
    char linha[COL];
    
    
    for(col=1;col<COL; col++)
    {
      
       lin=0;
       for(aux=col; aux <LIN; aux++)
       {
       	    linha[lin]=matriz[lin][col+lin];
       	    lin++;
       }
       linha[lin]='\0';
      
	      
       total += pesquisa(busca,linha);
  	}
     
	return total; 
	
}

/*
  Pesquisa nas diagonais inferior
*/		
int  pesquisaDiagonalInferior(char busca[31],char matriz[LIN][COL])
{

    int  lin,col,aux;
    int  total =0;
    char linha[COL];
    
    
    for(lin=1;lin<LIN; lin++)
    {
      
       col=0;
       for(aux=lin; aux <COL; aux++)
       {
       	    linha[col]=matriz[lin+col][col];
       	    col++;
       }
       linha[col]='\0';
          
       total += pesquisa(busca,linha);
  	}
     
	return total; 
	
}

/*
  Imprime a matriz
*/
void imprimeMatriz(char matriz[LIN][COL])
{
	int i, j;
	
	printf("\n");
	
	for(i=0; i < LIN; i++)
	{
	    for(j=0; j < COL; j++)
		{
	       printf("%c ", matriz[i][j]);
		}
		    
		printf("\n");
	}
	
	
}

/*
   Recebe a matriz ate o seu tamanho
*/
void recebeMatriz(char matriz[LIN][COL])
{
	char entrada[31];
	int lin=0, col=0, tam, i;
 	int total=0;
 	char letra=65;
         
	do
    {
       	printf("Digite um texto: ");
        gets(entrada);
        
		tam = strlen(entrada);
		
				 	
		for(i=0; i < tam && total < MAX; i++)
		{
			//Verifica se precisa incrementar uma linha
			if(col >= COL)
			{
				lin++;
				col=0;
			}
			 
			matriz[lin][col] = entrada[i];
			col++;
			total++;
		}
		
	}while(total < MAX);
         
	
}
