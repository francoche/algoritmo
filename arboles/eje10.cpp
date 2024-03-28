#include <iostream>
using namespace std;
struct NAbinario{
int dato;
NAbinario* der;
NAbinario* izq;
};
struct nodo_pila{
NAbinario *dato;
nodo_pila * link;
};
void pila_agregar(nodo_pila*&p,NAbinario * n){
nodo_pila *nuevo_nodo=new nodo_pila();
nuevo_nodo->dato=n;
nuevo_nodo->link=p;
p=nuevo_nodo;
}

NAbinario * pila_sacar(nodo_pila*&p){
nodo_pila *nodo_anterior;
nodo_anterior=p;
NAbinario *aux=p->dato;
p=p->link;
delete nodo_anterior;
return aux;
}

bool pilavacia(nodo_pila *p){
//return(p == NULL);
if(p==NULL){
return true;}
else{
return false;
}
}
void pre_orden_iterativo(NAbinario*&arbol){
NAbinario *aux=NULL;
nodo_pila *pila=NULL;
if(arbol!=NULL){
pila_agregar(pila,arbol);}
while(!pilavacia(pila)){
aux=pila_sacar(pila);
cout<<aux->dato<<" ";
if(aux->der!=NULL){
pila_agregar(pila,aux->der);
}
if(aux->izq!=NULL){
pila_agregar(pila,aux->izq);
}
}
}

void agregar_arbol(NAbinario *&arbol,int dato){
NAbinario *aux=new(NAbinario);
NAbinario *actual=arbol;
NAbinario *anterior=NULL;
aux->dato=dato;
if(arbol!=NULL){
while (actual!=NULL){
	anterior=actual;
	if (dato<actual->dato){
		actual=actual->izq;	
	}
	else {
		actual=actual->der;
	}	
}
if (dato<anterior->dato){
	anterior->izq=aux;	
}
else {
	anterior->der=aux;	
}	
}else{
arbol=aux;}

aux->izq=NULL;
aux->der=NULL;
}
void pre_orden_iterativo_nodos_hijos_suma_padre(NAbinario*&arbol){
	NAbinario *aux=NULL;
	nodo_pila *pila=NULL;
	if(arbol!=NULL){
		pila_agregar(pila,arbol);}
	while(!pilavacia(pila)){
		aux=pila_sacar(pila);
		if(aux->der!=NULL && aux->izq!=NULL){
			int suma=(aux->der->dato+aux->izq->dato);
			if(suma!= aux->dato){
				cout<<"los hijos no son la suma del padre XXX";
				return;
			}
		}
		if(aux->der!=NULL && aux->izq==NULL){
			if(aux->der->dato!=aux->dato){
				cout<<"los hijos no son la suma del padre VVV";
				return;
			}
		}
		if(aux->izq!=NULL && aux->der==NULL){
			if(aux->izq->dato!=aux->dato){
				cout<<"los hijos no son la suma del padre ZZZ";
				return;
			}
		}
		if(aux->der!=NULL){
			pila_agregar(pila,aux->der);
		}
		if(aux->izq!=NULL){
			pila_agregar(pila,aux->izq);
		}
	}
	cout<<"los hijos son la suma del padre";
}
int main(int argc, char *argv[]) {
	NAbinario *arbolito=NULL;
	agregar_arbol(arbolito,10);
	agregar_arbol(arbolito,9);
	agregar_arbol(arbolito,8);
	pre_orden_iterativo(arbolito);
	pre_orden_iterativo_nodos_hijos_suma_padre(arbolito);
	return 0;
}

