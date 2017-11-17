#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *relatorio;
	relatorio = fopen("Relatorio.html", "w");
	
	char *titulo, *data, *nome;
	int numeroRegistros = 5, casa = 48, i;
	
	titulo = "RELATORIO";
	nome = "ERICK";
	data = __DATE__;
	
	fprintf(relatorio, "<html><head><title>%s</title></head><body><style>header{text-align: center; height: 100px; border: 1px solid #000} table, th, td{text-align: center; border: 1px solid #000; border-collapse: collapse} th{font-family: sans-serif; height: 30px; background: #f5f5f5} h1{font-family: sans-serif}</style>", titulo);
	fprintf(relatorio, "<header><h1>RELATORIO DE CONVIDADOS NO DIA: %s</h1></header><center><table style='margin-top: 10px; width: 1080px;'><tr><th>COD</th><th>NOME</th><th>CASA</th><th>DATA</th></tr>", data);
	
	for(i=0; i<numeroRegistros; i++){
		fprintf(relatorio, "<tr><td>%i</td><td>%s</td><td>%i</td><td>%s</td></tr>", i, nome, casa, data);
	}
	
	fprintf(relatorio, "</table></center></body></html>");
	fclose(relatorio);
	
	return 0;
}
