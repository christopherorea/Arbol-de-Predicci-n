#include <stdio.h>
#include <string.h>
#include <memory.h>

typedef struct{
	char nombreCan[17];
}nombres;	

int i;

nombres *IniCan(){
	nombres *estos;
	if(estos=malloc(sizeof(nombres)*10)==0){
		return estos;
	}	
	return estos;
}

void BuscarCandidatos(nombres *estos,char *dato){
	FILE *cnd=0;
	cnd=fopen(dato,"r");
	char linea[17];
	i=0;
	while (!feof(cnd)){
		fscanf(cnd, "%s\n", &linea);
		strcpy(estos[i].nombreCan, linea);
		//printf("%s\n", linea);
		i++;
	}
	//printf("va a cerrar\n");
	fclose(cnd);
	//printf("cerro\n");
	return;
}

/*int main(){
	nombres estos[14]; 
	BuscarCandidatos(&estos,"nombres.txt");
	//printf("no se vato :v\n");
	return 0;
}*/
