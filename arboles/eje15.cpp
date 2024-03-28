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
int altura_arbol(NAbinario *arb){
	int izAlt,deAlt;
	if (arb==NULL){
		return 0;	
	}
	izAlt=altura_arbol(arb->izq);
	deAlt=altura_arbol(arb->der);
	if (izAlt>deAlt){
		return izAlt+1;	
	}
	else {
		return deAlt+1;	
	}   
}
	
void mostrar_hojas(NAbinario *&arbol){
NAbinario *anterior=NULL;	
NAbinario *aux=NULL;
NAbinario *aux2=NULL;
nodo_pila *pila=NULL;
if(arbol!=NULL){
pila_agregar(pila,arbol);}else{cout<<"arbol nulo";return;}
while(!pilavacia(pila)){
anterior=aux;	
aux=pila_sacar(pila);
if(aux->der==NULL && aux->izq==NULL){
delete aux;
anterior->der=NULL;
anterior->izq=NULL;
aux=arbol;
anterior=NULL;
while(!pilavacia(pila)){
	aux2=pila_sacar(pila);
	delete aux2;

}
}
if(arbol->der==NULL && arbol->izq==NULL){
	//cout<<arbol->dato;
	delete arbol;
	arbol=NULL;
	cout<<"arbol borrado ";
	return;
}
if(aux->der!=NULL){
pila_agregar(pila,aux->der);
}
if(aux->izq!=NULL){
pila_agregar(pila,aux->izq);
}
}
}

int main(int argc, char *argv[]) {
NAbinario *arbolito=NULL;
agregar_arbol(arbolito,5);
agregar_arbol(arbolito,6);
agregar_arbol(arbolito,4);
agregar_arbol(arbolito,2);
agregar_arbol(arbolito,8);
agregar_arbol(arbolito,7);
agregar_arbol(arbolito,9);
agregar_arbol(arbolito,10);
agregar_arbol(arbolito,1);
agregar_arbol(arbolito,200);
agregar_arbol(arbolito,3);
pre_orden_iterativo(arbolito);cout<<endl;
mostrar_hojas(arbolito);
pre_orden_iterativo(arbolito);


return 0;
}

