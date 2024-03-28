#include <iostream>
#include <ctime>
using namespace std;
struct nodo_lista{
	int dato;
	nodo_lista *link;
};
void lista_crear_rand(nodo_lista*&l,int cantidad){
	srand(time(NULL));
	int aux,aux2;
	aux=rand()%100;
	aux2=rand()%100;
	int cont=0;
	cout<<aux<<" "<<aux2<<endl;
	while(cont<cantidad){
		nodo_lista *actual=l;
		nodo_lista *anterior=NULL;
		nodo_lista *nnodo=new(nodo_lista);
		int dato;
		int aux3=rand()%2;
		if(aux3==1){
			dato=aux;
		}else{
			dato=aux2;
		}
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
		cont++;
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
int main(int argc, char *argv[]) {
	srand(time(NULL));
	nodo_lista *lista=NULL;
	int cantidad=5;
	lista_crear_rand(lista,cantidad);
	mostrar_lista(lista);
	mostrar_lista_maximo(lista);
	mostrar_lista_minimo(lista);
	
	return 0;
}

