#include <iostream>
#include<ctime>
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
void mesclarlista(nodo_lista *&l){
	srand(time(NULL));
	int aux=0;
	int aux2=0;
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	nodo_lista *auxanterior1=NULL;
	nodo_lista *auxanterior2=NULL;
	nodo_lista *primernodo=NULL;
	nodo_lista *segundonodo=NULL;
	nodo_lista *auxi=NULL;
	int cont=1;
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			cont++;
		}
		cont=cont-1;
		while(aux==aux2){
			aux=1+rand()%cont;
			aux2=1+rand()%cont;
		}
		actual=l;
		anterior=NULL;
		cout<<aux<<" "<<aux2<<" "<<cont<<endl;
		int cont2=1;
		while(cont2<aux){
			anterior=actual;
			actual=actual->link;
			cont2++;
			if(cont2==aux){
				auxanterior1=anterior;
				primernodo=actual;
			}
		}
		actual=l;
		anterior=NULL;
		cont2=1;
		while(cont2<aux2){
			anterior=actual;
			actual=actual->link;
			cont2++;
			if(cont2==aux2){
				auxanterior2=anterior;
				segundonodo=actual;
			}
		}
		if(aux==1){
			primernodo=l;
		}
		if(aux2==1){
			segundonodo=l;
		}
		cout<<primernodo->dato<<" "<<segundonodo->dato<<endl;
		if(aux==1){
			primernodo=l;
			if(aux2-aux==1){
				primernodo->link= segundonodo->link;
				segundonodo->link=primernodo;
				l=segundonodo;
				mostrar_lista(l);
				return;
			}else{
				auxi=primernodo->link;
				primernodo->link=segundonodo->link;
				segundonodo->link=auxi;
				l=segundonodo;
				auxanterior2->link=primernodo;
				mostrar_lista(l);
				return;
			}
		}
		if(aux2==1){
			segundonodo=l;
			if(aux-aux2==1){
				segundonodo->link= primernodo->link;
				primernodo->link=segundonodo;
				l=primernodo;
				mostrar_lista(l);
				return;
			}else{
				auxi=segundonodo->link;
				segundonodo->link=primernodo->link;
				primernodo->link=auxi;
				l=primernodo;
				auxanterior1->link=segundonodo;
				mostrar_lista(l);
				return;
			}
		}
		if(aux>aux2 && aux-aux2==1){
			segundonodo->link= primernodo->link;
			primernodo->link=segundonodo;
			auxanterior2->link=primernodo;
			mostrar_lista(l);
			return;
		}
		if(aux2>aux && aux2-aux==1){
			primernodo->link= segundonodo->link;
			segundonodo->link=primernodo;
			auxanterior1->link=segundonodo;
			mostrar_lista(l);
			return;
		}
		if(aux!=1 && aux2!=1){
			auxi=primernodo->link;
			primernodo->link=segundonodo->link;
			segundonodo->link=auxi;
			auxanterior1->link=segundonodo;
			auxanterior2->link=primernodo;
		}
		mostrar_lista(l);
		
		
	}
	else{
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
		lista_agregar(lista,7);
		lista_agregar(lista,8);
		lista_agregar(lista,9);
		mesclarlista(lista);
	return 0;
}

