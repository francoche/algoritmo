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
void pre_orden_iterativo_cant_nodos(NAbinario*&arbol){
	NAbinario *aux=NULL;
	nodo_pila *pila=NULL;
	int cont=0;
	if(arbol!=NULL){
		pila_agregar(pila,arbol);}
	while(!pilavacia(pila)){
		aux=pila_sacar(pila);
		cout<<aux->dato<<" ";
		cont++;
		if(aux->der!=NULL){
			pila_agregar(pila,aux->der);
		}
		if(aux->izq!=NULL){
			pila_agregar(pila,aux->izq);
		}
	}
	cout<<"cant nodos: "<<cont;
}
void abinario_preorden_recursivo_cant_nodos (NAbinario* arbol,int &cont)
{if (arbol != NULL)
	{
		
		cout << arbol->dato << "  ";
		cont++;
		abinario_preorden_recursivo_cant_nodos (arbol->izq,cont);
		abinario_preorden_recursivo_cant_nodos (arbol->der,cont);
		
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
int main(int argc, char *argv[]) {
	NAbinario *arbolito=NULL;
	agregar_arbol(arbolito,5);
	agregar_arbol(arbolito,6);
	agregar_arbol(arbolito,4);
	agregar_arbol(arbolito,2);
	agregar_arbol(arbolito,7);
	agregar_arbol(arbolito,3);
	cout<<endl;
	pre_orden_iterativo_cant_nodos(arbolito);
	cout<<endl;
	int cont=0;
	abinario_preorden_recursivo_cant_nodos(arbolito,cont);
	cout<<"cant nodos: "<<cont;
	return 0;
}

