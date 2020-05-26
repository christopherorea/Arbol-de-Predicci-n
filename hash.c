#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

int i;

typedef struct{
	char palabra[20];
	int status;
}Nodo;


Nodo *initHash(){
	Nodo *apnodo=0;
	if(apnodo=malloc(sizeof(Nodo)*300)==0){
		return apnodo;	
	}
	return apnodo;
}

unsigned H(char *palabra, unsigned b){
	unsigned s=0;
	for (i=0; i<strlen(palabra); i++){
		//printf("valor actual de u =%u\n", s);
		s+=palabra[i];	
	}
	return (s%b);
}


void leerArchivo(Nodo *T, char *dato){
	FILE *fpl=0;
	fpl= fopen(dato, "r");
	char linea[20];
	unsigned y;
	while (!feof(fpl)){
		fscanf(fpl, "%s\n", &linea);
		y=H(linea, 300);
		i=0;
		while(T[y % 300].status==1 && i<300){
			y=y+i;
			i++;
		}
		y=y%300;
		T[y].status=1;
		strcpy(T[y].palabra, linea);
		//printf("palabra: %s\n",T[y].palabra);
	}		
	fclose(fpl);
	return;
}

/*int main(){
	Nodo *T;
	unsigned y;
	T=initHash();
	/*char sal[20]="animal";	
	y=H(sal, 300);
	printf("\nvalor final de u= %u con palabra= %s\n", y, sal);
	//leerArchivo(&T, sal, y);
	leerArchivo(&T, "palabras.txt");	
	return 0;
}*/
