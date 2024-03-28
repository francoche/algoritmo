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
void preordeniterativo(NAbinario *&arbol){
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
NAbinario* clonar(NAbinario* arbol){
	if(arbol!=NULL){
		NAbinario *nuevo=new(NAbinario);
		nuevo->dato=arbol->dato;
		nuevo->izq=clonar(arbol->izq);
		nuevo->der=clonar(arbol->der);
		return nuevo;
	}else{
		return NULL;
	}
}
int main(int argc, char *argv[]) {
NAbinario *arbolito=NULL;
NAbinario *arbolito2;
agregar_arbol(arbolito,5);
agregar_arbol(arbolito,6);
agregar_arbol(arbolito,4);
agregar_arbol(arbolito,2);
agregar_arbol(arbolito,7);
agregar_arbol(arbolito,3);
preordeniterativo(arbolito);
arbolito2=clonar(arbolito);
cout<<endl;
preordeniterativo(arbolito2);
return 0;
}


