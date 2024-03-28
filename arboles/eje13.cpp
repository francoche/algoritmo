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
void mostrar_hojas(NAbinario *&arbol){
NAbinario *aux=NULL;
nodo_pila *pila=NULL;
if(arbol!=NULL){
pila_agregar(pila,arbol);}
while(!pilavacia(pila)){
aux=pila_sacar(pila);
if(aux->der==NULL && aux->izq==NULL){
cout<<aux->dato<<" ";
}
if(aux->der!=NULL){
pila_agregar(pila,aux->der);
}
if(aux->izq!=NULL){
pila_agregar(pila,aux->izq);
}
}
}
int maximo(int a, int b){
if(a>b){
return a;
}
if(a<b){
return b;
}
return a;
}						
int altura(NAbinario *arbol){
if(arbol == NULL){
return 0;
}
int aux = 1 + maximo(altura(arbol->izq), altura(arbol->der));
return aux;
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

int profundidadNodo(NAbinario *arbol, int datoBuscar, int cont){
	if(arbol == NULL){
		return -1;
	}
	else if(arbol->dato == datoBuscar){
		return cont;
	}
	else if(datoBuscar < arbol->dato){
		cont++;
		return profundidadNodo(arbol->izq, datoBuscar, cont);
	}
	else{
		cont++;
		return profundidadNodo(arbol->der, datoBuscar, cont);
	}
}
void mostrar_hojas_altura_igual_al_arbol(NAbinario *arbol){
	NAbinario *aux=NULL;
	nodo_pila *pila=NULL;
	int altura1=altura_arbol(arbol);
	int alturahoja;
	int cont;
	if(arbol!=NULL){
		pila_agregar(pila,arbol);}
	while(!pilavacia(pila)){
		cont=0;
		aux=pila_sacar(pila);
		alturahoja=profundidadNodo(arbol,aux->dato,cont);
		alturahoja++;
		if(altura1==alturahoja){
			cout<<aux->dato<<" ";
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
	agregar_arbol(arbolito,7);
	agregar_arbol(arbolito,3);
	agregar_arbol(arbolito,1);
	mostrar_hojas_altura(arbolito);
	/*int altura2=altura(arbolito);
	cout<<"la altura es: "<<altura2<<endl;
	int altura3=altura_arbol(arbolito);
	cout<<"la altura es: "<<altura3<<endl;
	barrido_por_niveles_iterativo(arbolito);*/
	return 0;
}

