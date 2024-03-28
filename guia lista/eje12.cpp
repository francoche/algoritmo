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
		cout<<endl;
	}else{
		cout<<"lista vacia";
	}
}
void concatenar(nodo_lista *&l1,nodo_lista *&l2){
	nodo_lista *actual=l1;
	nodo_lista *anterior=NULL;
	if(l1!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
		}
		anterior->link=l2;
	}
}

void ordenar_ascendentemente(nodo_lista *&li) {
	nodo_lista* actual = li;
	while (actual!=NULL){
		nodo_lista* anterior=actual;
		nodo_lista* siguiente=actual->link;
		while (siguiente!=NULL){
			if (siguiente->dato<anterior->dato) {
				anterior=siguiente;
			}
			siguiente = siguiente->link;
		}
		int aux = actual->dato;
		actual->dato=anterior->dato;
		anterior->dato=aux;
		actual = actual->link;
	}
	mostrar_lista(li);
}
int main(int argc, char *argv[]){
	nodo_lista *lista1=NULL;
	nodo_lista *lista2=NULL;
	lista_agregar(lista1,7);
	lista_agregar(lista1,7);
	lista_agregar(lista1,49);
	mostrar_lista(lista1);
	lista_agregar(lista2,8);
	lista_agregar(lista2,8);
	lista_agregar(lista2,9);
	mostrar_lista(lista1);
	concatenar(lista1,lista2);
	mostrar_lista(lista1);
	ordenar_ascendentemente(lista1);
	return 0;
	}

