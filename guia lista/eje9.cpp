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
/*void ascendente_recursivo(nodo *li,bool &band){
if(li->dato>li->sig->dato){
band=false;	
return;
}
else {
ascendente_recursivo(li->sig,band);
}
}	


void descendente_recursivo(nodo *li,bool &band){
if(li->dato<li->sig->dato){
band=false;	
return;
}
else {
descendente_recursivo(li->sig,band);
}
}*/


void descendiente(nodo_lista *li,bool &b){//Para agregar una lista
	nodo_lista *actual=li;//2 auxiliares para recorrer la lista
	nodo_lista *anterior=NULL;
	while (actual!=NULL){
		anterior=actual;//Aux 2 va a puntar a lo que antes apuntaba aux 1 un estado anterior
		actual=anterior->link;//Aux 1 va a apuntar siempre al sig
		if (actual>anterior){
			b=false;	
		}
	}
}
	
void ascendente(nodo_lista *li,bool &b){
	nodo_lista *actual=li;
	nodo_lista *anterior=NULL;
	while (actual!=NULL){
		anterior=actual;
		actual=anterior->link;
		if(actual!=NULL){
			if (actual->dato<anterior->dato){
				b=false;	
				return;
			}
		}
	}
	b=true;
	
}
void contar_iteraciones(nodo_lista*l){
	nodo_lista *actual=l;
	nodo_lista *anterior=NULL;
	int cont=1;
	int cont2=0;
	int v[10][10]={0};
	if(l!=NULL){
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			if(actual!=NULL){
			if(anterior->dato!=actual->dato){
				v[cont2][0]=anterior->dato;
				cont2++;
			}
			}
		}
		v[cont2++][0]=anterior->dato;
		actual=l;
		anterior=NULL;
		int cont3=0;
		while(actual!=NULL){
			anterior=actual;
			actual=actual->link;
			if(actual!=NULL){
				if(anterior->dato==actual->dato){
					cont++;
					v[cont3][1]=cont;
				}else if(anterior->dato!=actual->dato){
					cont=1;
					cont3++;
					v[cont3][1]=cont;
				}
			}
		}
		for(int i=0;i<cont2;i++) { 
			cout<<v[i][0]<<" "<<v[i][1]<<endl;
		}
	}
	else{
		cout<<"lista vacia";}
	
}
	
	

int main(int argc, char *argv[]) {
	nodo_lista *lista=NULL;
	bool aux;
	lista_agregar(lista,1);
	lista_agregar(lista,1);
	lista_agregar(lista,3);
	lista_agregar(lista,7);
	lista_agregar(lista,7);
	lista_agregar(lista,9);
	lista_agregar(lista,10);
	lista_agregar(lista,10);
	//mostrar_lista(lista);
	contar_iteraciones(lista);
	return 0;
}

