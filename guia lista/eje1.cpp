#include <iostream>
using namespace std;
struct nodo_lista{
	int dato;
	nodo_lista *link;
};
void lista_agregar2(nodo_lista*&l,int v[],int cantidad){
	for(int i=0;i<cantidad;i++) { 
		nodo_lista *actual=l;
		nodo_lista *anterior=NULL;
		nodo_lista *nnodo=new(nodo_lista);
		nnodo->dato=v[i];
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
	nodo_lista *lista;
	lista=NULL;
	int v[7]={9,1,3,2,8,7,6};
	lista_agregar2(lista,v,7);
	mostrar_lista(lista);
	return 0;
}

