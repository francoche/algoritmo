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
}
void lista_agregar_pos(nodo_lista*&l,int dato,int pos){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	nodo_lista *nnodo=new(nodo_lista);
	nnodo->dato=dato;
	int cont=1;
	if(l!=NULL){
		if(pos>0){
			while(actual!=NULL){
				anterior=actual;
				actual=actual->link;
				if(cont==pos && cont==1){
					nnodo->link=l;
					l=nnodo;
					return;
				}
				if(cont==pos-1 && actual!=NULL){
					anterior->link=nnodo;
					nnodo->link=actual;
					return;
				}
				cont++;
			}
		}
	}else{
		l=nnodo;
		nnodo->link=actual;
	}
	if(pos>=cont && actual==NULL){
		anterior->link=nnodo;
		nnodo->link=actual;
		return;
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
	lista_agregar_pos(lista,7,7);
	mostrar_lista(lista);
	return 0;
}

