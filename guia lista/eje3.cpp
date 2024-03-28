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
void mostrar_lista_x2(nodo_lista*l){
	nodo_lista *reset=l;
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	cout<<"L";
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			cout<<"->"<<anterior->dato;
		}
	}else{
		cout<<"lista vacia";
	}
	actual=reset;
	cout<<endl;
	cout<<"L";
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			cout<<"->"<<anterior->dato*2;
		}
	}else{
		cout<<"lista vacia";
	}
}
int main(int argc, char *argv[]) {
	nodo_lista *lista=NULL;
	lista_agregar(lista,5);
	lista_agregar(lista,6);
	lista_agregar(lista,7);
	lista_agregar(lista,8);
	lista_agregar(lista,9);
	lista_agregar(lista,10);
	mostrar_lista_x2(lista);
	return 0;
}

