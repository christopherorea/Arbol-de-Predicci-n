#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include "hash.c"
#include "candidatos.c"
#include "arbol.c"

int bandera;

void leerDoc(Nodo *T,char *dato, nombres *estos){
	if(fopen(dato, "r")==0){
		return;
	}
	bandera=0;
	//raiz de arbol Rtw
	NodoTW *Rtw;
	Rtw=CreaNodoTW(&Rtw);
	strcpy(Rtw->palabra, "raiz");
	//sobrescritura de TW
	NodoTW *z;
	z=CreaNodoTW(&z);
	z->nleft=z;
	z->nright=z;
	//raiz de arbol Rtp
	NodoTP *Rtp;
	Rtp=CreaNodoTP(&Rtp);
	strcpy(Rtp->palabra, "raiz");
	//sobreescirtura de TP
	NodoTP *x;
	x=CreaNodoTP(&x);
	x->nleft=x;
	x->nright=x;
	//lectura de archivos
	FILE *fplc=0;
	fplc= fopen(dato, "r");
	char linea[500];
	unsigned y;
	while (!feof(fplc)){
		fscanf(fplc, " %s ", &linea);
		y=H(linea, 300);
		for (i=0;i<13;i++){
			if(strcmp(estos[i].nombreCan,linea)==0 ){
				//printf("encontre un candidato: %s\n", estos[i].nombreCan);
				strcpy(z->candidato, estos[i].nombreCan);
				strcpy(z->web, dato);
				strcpy(x->candidato, estos[i].nombreCan);
				bandera=1;			
			}
		}
		for(i=0;i<300;i++){
			if(strcmp(T[i].palabra, linea)==0){
				//printf("encontre una palabra: %s\n", T[i].palabra);
				strcpy(z->palabra, linea);
				strcpy(x->palabra, linea);
				if(bandera==1){
					//printf("va a entrar\n");
					InsertarNodoTW(Rtw,z);		
					InsertarNodoTP(Rtp,x);
				}
			}
		}
	}		
	fclose(fplc);
	printf("\nArbol de Tripleta de transacción:\n\n");
	ImprimirTW(Rtw);
	printf("\nArbol de Dupla para frecuencias:\n\n");
	ImprimirTP(Rtp);
	return;
}

//||strcmp(estos[i].nombreCan,linea)==0
//strcmp(T[i].palabra,linea)==0 ||

int main(){
	char reto[20];
	while(reto!=1){
		Nodo *T=0;
		T=initHash();
		leerArchivo(&T,"palabras.txt");
		nombres estos[14];
		BuscarCandidatos(&estos, "nombres.txt");
		/*for(i=0; i<14; i++){
			printf("%s\n", estos[i].nombreCan);
		}	*/
		printf("añade un archivo valido: ");
		scanf("%s", &reto);
		if(strcmp(reto,"salir")==0){
			break;	
		}
			leerDoc(&T, reto, &estos);
	}
	return 0;
}
