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
	void mostrar_lista_maximo(nodo_lista*l){
		nodo_lista *actual=l;
		nodo_lista *anterior=NULL;
		int max=0;
		if(l!=NULL){
			while(actual!=NULL){
				anterior=actual;
				actual=actual->link;
				if(anterior->dato>=max){
					max=anterior->dato;
				}
			}
			cout<<"el maximo es "<<max;
		}else{
			cout<<"lista vacia";
		}
	}
		void mostrar_lista_minimo(nodo_lista*l){
			nodo_lista *actual=l;
			nodo_lista *anterior=NULL;
			int min=100000000;
			if(l!=NULL){
				while(actual!=NULL){
					anterior=actual;
					actual=actual->link;
					if(anterior->dato<min){
						min=anterior->dato;
					}
				}
				cout<<"el minimo es "<<min;
			}else{
				cout<<"lista vacia";
			}
		}
void maximo_recursivo(nodo *li,int &may){
if(li->dato>may){
may=li->dato;
maximo_recursivo(li->sig,may);
}
}	

void minimo_recursivo(nodo *li,int &men){
if(li->dato<men){
men=li->dato;
minimo_recursivo(li->sig,men);
}
}
void maximo_recursivo_ordenar(nodo_lista *p,int &max,int &mayor){
	nodo_lista *aux=p;
	if (aux==NULL){
		return;	
	}
	else {
		if (aux->dato>mayor){
			mayor=aux->dato;
			max=aux->dato;
		}
		maximo_recursivo(aux->sig,max,mayor);	
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
	//mostrar_lista_maximo(lista);
	//mostrar_lista_minimo(lista);
	nodo_lista * aux=recu_max(lista);
	cout<<aux->dato;
	return 0;
}

