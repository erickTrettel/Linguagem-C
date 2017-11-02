#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cada contato possui um nome e telefone.
typedef struct {
  char nome[100];
  int  telefone;
} Contato;

//Funcoes

void novoContato  (Contato *agenda, int *n, int *cap);
void exibeContatos(Contato *agenda, int n);
void apagaContato (Contato *agenda, int *n);

void salvarArquivo(Contato *contatos, int n);
Contato * abrirArquivo (int *n, int *cap);


/****************************************************
Funcao principal
*/
int main(){
  //Ponteiro para estrutura. Vai ser o nosso vetor de
  //estruturas dinamicas com os dados da agenda.
  Contato *agenda;
  int cap; //Capacidade do vetor (tamanho real do vetor).
  int n;   //Numero de contatos cadastrados (tamanho usado).
  int opc; //Opcao do menu selecionada.


  agenda = abrirArquivo(&n, &cap);

  do{
    //Exibe o menu de op��es.
    printf("*** Menu ***\n");
    printf("1) Cadastrar contato.\n");
    printf("2) Exibir contatos.\n");
    printf("3) Apagar.\n");
    printf("4) Sair.\n");
    //Le a opcao selecionada.
    scanf("%d",&opc);

	switch(opc){
	      case 1: novoContato  (agenda, &n, &cap); 	break;
	      case 2: exibeContatos(agenda, n); 		break;
	      case 3: apagaContato (agenda, &n); 		break;
	}

    //Enquanto nao for opcao de saida continua mostrando menu.
  }while(opc!=4);

  salvarArquivo(agenda, n);

  //Libera a memoria alocada do vetor.
  free(agenda);

  return 0;
}


/**********************************************************
Salvar contatos em arquivo
*/
void salvarArquivo(Contato *agenda, int n){

   if(n>0){
    //Se existe algum contato cadastrado
    //entao grava para o disco.

    //Abre arquivo em modo de gravacao ("w" = write).
    FILE *fp = fopen("agenda.dat","w");

    //Grava o numero de contatos no inicio do arquivo.
    fwrite(&n, sizeof(int), 1, fp);

    //Grava os dados do vetor no arquivo.
    fwrite(agenda, sizeof(Contato), n, fp);

    //Fecha arquivo apos a gravacao.
    fclose(fp);
  }

}

/**********************************************************
Funcao abre arquivo
*/
Contato * abrirArquivo (int *n, int *cap){

  Contato *agenda;

  //Abrindo arquivo em modo de leitura ("r" = read).
  FILE *fp = fopen("agenda.dat","r");


  //Se retorna NULL eh pq nao encontrou o arquivo.
  //Isso acontece na primeira vez que rodamos o programa.
  if(fp==NULL){
    *n = 0;    //Base de dados inicialmente vazia.
    *cap = 20; //Fixamos uma capacidade inicial (ex: 20).
   //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (Contato *)malloc(sizeof(Contato)* (*cap));
  }
  else{ //Arquivo encontrado, logo procedemos com a leitura.

    //Le o numero de registros.
  	fread(n, sizeof(int), 1, fp);

    //A capacidade deve ser maior ou igual a "n" (ex: n*2).
    *cap = (*n) * 2;

    //Alocammos o vetor de estruturas de forma
    //dinamica conforme a capacidade.
    agenda = (Contato *)malloc(sizeof(Contato)* (*cap));

    //Leitura dos dados dos registros do arquivo para o vetor.
    fread(agenda, sizeof(Contato), *n, fp);

    //Fecha arquivo apos leitura.
    fclose(fp);
  }

  return agenda;
}


/**********************************************************
Funcao exibe todos os contatos
*/
void exibeContatos(Contato *agenda, int n){
    //Exibe todos contatos cadastrados.
    int i;

    for(i=0; i<n; i++){
	    printf("*** Contato %d ***\n",i+1);
        printf("Nome: %s\n",agenda[i].nome);
	    printf("Telefone: %d\n",agenda[i].telefone);
    }
}


/**********************************************************
Funcao apaga contato
*/
void apagaContato (Contato *agenda, int *n){

	  char nome[100];
      int j, i;
      fflush(stdin);
      printf("Digite o nome a ser removido: ");
      gets(nome);
      for(i=0; i < *n; i++){
             if (strcmp(agenda[i].nome, nome)==0){
         		for(j=i; j < *n; j++){
            	  agenda[j] = agenda[j+1];
                 }
                (*n) --;
                i  = *n;
              }
      }
}

/**********************************************************
Funcao cadastra novo contato
*/
void novoContato(Contato *agenda, int  *n, int *cap){

      if(*n==*cap){
		 //Capacidade esgotada, devemos aumentar o
		 //vetor usando "realloc" (ex: dobrar capacidade).
	      *cap = *cap * 2;
          agenda = (Contato*)realloc(agenda, sizeof(Contato) * (*cap));
      }

      //Leitura dos dados.
      printf("Digite o nome: ");
      fflush(stdin);
      gets(agenda[*n].nome);
      printf("Digite o telefone: ");
      scanf("%d",&agenda[*n].telefone);

      //Incrementa numero de registros cadastrados.
	  (*n) ++;
}
