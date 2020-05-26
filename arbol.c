#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>

typedef struct NodoTW{
	char candidato[17];
	char palabra[20];
	char web[20];
	struct NodoTW *nleft;
	struct NodoTW *nright;

}NodoTW;

typedef struct NodoTP{
	char candidato[17];
	char palabra[20];
	int indice;
	struct NodoTP *nleft;
	struct NodoTP *nright;

}NodoTP;

NodoTW *CreaNodoTW(NodoTW *x){
	NodoTW *nuevonodo;
	nuevonodo=malloc(sizeof(NodoTW));
	strcpy(nuevonodo->candidato,x->candidato);
	//printf("%s\n", nuevonodo->candidato);
	strcpy(nuevonodo->palabra,x->palabra);
	strcpy(nuevonodo->web,x->web);	
	nuevonodo->nleft=nuevonodo;
	nuevonodo->nright=nuevonodo;
	return nuevonodo;
}

NodoTP *CreaNodoTP(NodoTP *x){
	NodoTP *nuevonodo;
	nuevonodo=malloc(sizeof(NodoTP));
	strcpy(nuevonodo->candidato,x->candidato);
	strcpy(nuevonodo->palabra,x->palabra);
	nuevonodo->indice=1;
	nuevonodo->nleft=nuevonodo;
	nuevonodo->nright=nuevonodo;
	return nuevonodo;
}

void InsertarNodoTW(NodoTW *R, NodoTW *x){
	if(strcmp(R->palabra,"raiz")==0 ){
		strcpy(R->palabra, x->palabra);
		strcpy(R->web, x->web);
		strcpy(R->candidato, x->candidato);
		//printf("entro aqui\n");
		return;
	}
	if(strcmp(R->palabra,x->palabra)==0 ){
		//printf("%s %s %d\n",R->candidato,R->palabra, R->indice);
		return;
	}
	NodoTW *nuevonodo;
	if(strcmp(R->palabra,x->palabra)>0 ){
		if(R->nleft==R){
			//printf("al menos intento 1\n");
			nuevonodo=malloc(sizeof(NodoTW));
			strcpy(nuevonodo->palabra, x->palabra);
			strcpy(nuevonodo->web, x->web);
			strcpy(nuevonodo->candidato, x->candidato);
			R->nleft=nuevonodo;
			nuevonodo->nleft=nuevonodo;
			nuevonodo->nright=nuevonodo;
			//printf("%s\n", nuevonodo->palabra);
			return;
		}
		else{
			//printf("se fue a izquierda\n");
			InsertarNodoTW(R->nleft,x);
		}
	}
	else{
		if(R->nright==R){
			//printf("al menos intento 2\n");
			nuevonodo=malloc(sizeof(NodoTW));
			strcpy(nuevonodo->palabra, x->palabra);
			strcpy(nuevonodo->web, x->web);
			strcpy(nuevonodo->candidato, x->candidato);
			R->nright=nuevonodo;
			nuevonodo->nleft=nuevonodo;
			nuevonodo->nright=nuevonodo;
			//printf("%s\n", nuevonodo->palabra);
			return;
		}
		else{
			//printf("se fue a derecha\n");
			InsertarNodoTW(R->nright,x);		
		}
	}
}

int prueba(NodoTW *x){
	printf("%s", x->palabra);
}

void InsertarNodoTP(NodoTP *R, NodoTP *x){
	if(strcmp(R->palabra,"raiz")==0 ){
		strcpy(R->palabra, x->palabra);
		R->indice=1;
		strcpy(R->candidato, x->candidato);
		//printf("entro aqui\n");
		return;
	}
	if(strcmp(R->palabra,x->palabra)==0 && strcmp(R->candidato,x->candidato)==0){
		R->indice++;
		//printf("%s %s %d\n",R->candidato,R->palabra, R->indice);
		return;
	}
	NodoTP *nuevonodo;	
	if(strcmp(R->palabra,x->palabra)>0){
		if(R->nleft==R){
			nuevonodo=malloc(sizeof(NodoTP));
			strcpy(nuevonodo->palabra, x->palabra);
			nuevonodo->indice=x->indice;
			strcpy(nuevonodo->candidato, x->candidato);
			R->nleft=nuevonodo;
			nuevonodo->nleft=nuevonodo;
			nuevonodo->nright=nuevonodo;
			return;
		}
		else{
			InsertarNodoTP(R->nleft,x);
		}
	}
	else{
		if(R->nright==R){
			nuevonodo=malloc(sizeof(NodoTP));
			strcpy(nuevonodo->palabra, x->palabra);
			nuevonodo->indice=x->indice;
			strcpy(nuevonodo->candidato, x->candidato);
			R->nright=nuevonodo;
			nuevonodo->nleft=nuevonodo;
			nuevonodo->nright=nuevonodo;
			return;
		}
		else{
			InsertarNodoTP(R->nright,x);		
		}
	}
}

void ImprimirTW(NodoTW *Rtw){
	if(Rtw->nleft!=Rtw){
		ImprimirTW(Rtw->nleft);
	}
	if(Rtw->nright!=Rtw){
		ImprimirTW(Rtw->nright);
	}
	printf("%s %s %s\n", Rtw->web, Rtw->candidato, Rtw->palabra);
}

void ImprimirTP(NodoTP *Rtp){
	if(Rtp->nleft!=Rtp){
		ImprimirTP(Rtp->nleft);
	}
	if(Rtp->nright!=Rtp){
		ImprimirTP(Rtp->nright);
	}
	printf("%s %s %d\n", Rtp->candidato, Rtp->palabra, Rtp->indice);
}

/*int main(){
	NodoTW *R;
	R=CreaNodoTW(&R);
	strcpy(R->palabra, "raiz");
	NodoTW *z;
	z=CreaNodoTW(&z);
	z->nleft=z;
	z->nright=z;
	strcpy(z->palabra,"perro");
	InsertarNodoTW(R,z);
	//printf("%s\n", R->palabra);	

	NodoTW *y;
	y=CreaNodoTW(&y);
	y->nleft=y;
	y->nright=y;
	strcpy(y->palabra,"gato");
	InsertarNodoTW(R,y);

	NodoTW *j;
	j=CreaNodoTW(&j);
	j->nleft=j;
	j->nright=j;
	strcpy(j->palabra,"pez");
	InsertarNodoTW(R,j);

	NodoTW *h;
	h=CreaNodoTW(&h);
	h->nleft=h;
	h->nright=h;
	strcpy(h->palabra,"ardilla");
	InsertarNodoTW(R,h);
	
	NodoTW *i;
	h=CreaNodoTW(&i);
	i->nleft=i;
	i->nright=i;
	strcpy(i->palabra,"zal");
	InsertarNodoTW(R,i);
	/*NodoTW *y;
	strcpy(z->palabra,"perro");
	strcpy(x->candidato,"gatito");
	//printf("%s\n",x.candidato);
	strcpy(x->palabra,"corre");
	strcpy(x->web,"www");
	y=CreaNodoTW(&x);
	//printf("%s\n", y->candidato);
	printf("%s\n", z->nleft->nleft->nright->palabra);
	InsertarNodoTW(z,*y);
}*/
