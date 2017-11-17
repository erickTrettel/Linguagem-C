	#include <stdio.h>
	#include <string.h>
	
	int main()
	{
         int i=0;
         char curso1[]="Analise e Desenvolvimento de Sistemas";
         char curso2[]="Gestao em Tecnologia da Informacao";
         char curso3[]="Mecatronica";
         char curso4[]="Eventos";
         
		 char letra = 'a';
		 
		 int asc = letra;
		 
		 
		 
		 printf("****** Codigo asc do a %i ******", asc);
		 printf("****** Codigo asc do a %i ******", 'a');
		 
		 do{
		    letra = curso1[i];
		    
		    
		    if(letra != '\0')
			printf("%c  ", letra);	
		 	i++;
		 }while(letra != '\0');	


		i=0;
 	    do{
		    letra = curso4[i];
			printf("%c-", letra);	
		 	printf("%c-", letra+1);	
		 	printf("%c \n", letra+2);	
		 	i++;
		 }while(letra != '\0');	

		
         
         printf("\nTamanho curso 1 %i",  strlen(curso1));
         
		 if(strstr(curso1,"Desen") != NULL )
             printf("\nTEM: Desen");
         
         if(strstr(curso1,"DESEN") == NULL )
             printf("\nNAO TEM: DESEN");
         
         
         printf("\n");
         
         printf("%s\n", curso1);
         printf("%s\n", curso2);
         printf("%s\n", curso3);
         printf("%s\n", curso4);
         
         
         
		 char FatecItu[][80]={
		                    "Analise e Desenvolvimento de Sistemas",
							"Gestao em Tecnologia da Informacao",
         					"Mecatronica",
         					"Eventos"
         					};
         
         
         for(i=0; i < 4; i ++)
         	printf("%s\n", FatecItu[i]);
         
         
         
         for(i=0; i < 4; i ++)
         {
         	printf("Digite o nome do curso: ");
         	gets(FatecItu[i]);
		 }
         	
         for(i=0; i < 4; i ++)
         	printf("%s\n", FatecItu[i]);
         
         
         
		 
		 
		 
		 return 0;   
	}
