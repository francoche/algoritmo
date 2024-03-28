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
void mostrar_lista(nodo_lista*l){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			cout<<anterior->dato;
		}
	}else{
		cout<<"lista vacia";
	}
}

int main(int argc, char *argv[]) {
	nodo_lista *lista=NULL;
	lista_agregar(lista,1);
	lista_agregar(lista,2);
	lista_agregar(lista,3);
	lista_agregar(lista,4);
	lista_agregar(lista,5);
	lista_agregar(lista,6);
	mostrar_lista(lista);
	return 0;
}

