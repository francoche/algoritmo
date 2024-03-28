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
float mostrar_lista_promedio(nodo_lista*l){
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
		return acu/cont;
	}else{
		return 0;
	}
}
void mostrar_lista_promedio2(nodo_lista*l){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	if(l!=NULL){
		float aux=mostrar_lista_promedio(actual);
		cout<<"promedio: "<<aux<<endl;
		cout<<"superan al promedio: ";
		int cont=0;
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			if(anterior->dato>aux){
				cout<<"->"<<anterior->dato;
				cont++;
			}
		}
		if(cont==0){
			cout<<"ninguno";
		}
	}else{
		cout<<"lista vacia";
	}
}

int main(int argc, char *argv[]) {
	nodo_lista *lista=NULL;
	lista_agregar(lista,100);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	lista_agregar(lista,5);
	mostrar_lista_promedio2(lista);
	return 0;
}

