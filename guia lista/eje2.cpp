#include <iostream>
using namespace std;
struct nodo_lista{
	int dato;
	nodo_lista *link;
};
void lista_agregar(nodo_lista*&l,int dato){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	nodo_lista *nnodo=new(nodo_lista);
	nnodo->dato=dato;
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
		}
		anterior->link=nnodo;
	}else{
		l=nnodo;
	}
	nnodo->link=actual;
}
void mostrar_lista_promedio(nodo_lista*l){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	int cont=0;
	int acu=0;
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			cont++;
			acu=acu+anterior->dato;
		}
		cout<<"proemdio: "<<acu/cont;
	}else{
		cout<<"promedio 0";
	}
}
int main(int argc, char *argv[]) {
	nodo_lista *lista=NULL;
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	mostrar_lista_promedio(lista);
	return 0;
}

