#include <iostream>
using namespace std;

struct NAbinario{
	int dato;
	NAbinario* der;
	NAbinario* izq;
};

struct nodo_pilaa{
	NAbinario* dato;
	int bandera;
	nodo_pilaa* sig;
};

void pila_poner (nodo_pilaa *&p, NAbinario *arbol,int b){
	nodo_pilaa* nuevo_nodo = new nodo_pilaa();
	nuevo_nodo->dato = arbol;
	nuevo_nodo->bandera = b;
	nuevo_nodo->sig = p;
	p = nuevo_nodo;
}
	
NAbinario * pila_sacar (nodo_pilaa *&p,int &b){
nodo_pilaa* nodo_anterior;
nodo_anterior = p;
NAbinario *dato = p->dato;
b = p->bandera;
p = p->sig;
delete nodo_anterior;
return dato;
}

bool nodo_pilaa_vacia(nodo_pilaa* p){
//return(p==NULL);
if(p==NULL){
return true;}
else{
return false;
}
}	

void barrido_postorden_iterativo(NAbinario *arbol){
NAbinario *aux;
nodo_pilaa *pila=NULL;
int bandera;
if (arbol!=NULL){
bandera=1;
pila_poner(pila,arbol,bandera);	
}
while (!nodo_pilaa_vacia(pila)){
aux=pila_sacar(pila,bandera);
if (bandera==1){
	pila_poner(pila,aux,2);
	if (aux->izq!=NULL){
		pila_poner(pila,aux->izq,1);	
	}
}
else if (bandera==2){
	pila_poner(pila,aux,3);	
	if (aux->der!=NULL){
		pila_poner(pila,aux->der,1);	
	}	
}
else if (bandera==3){
	cout<<aux->dato<<" ";	
}
}
}
void abinariob_alta_recursivo (NAbinario* &arbol, int nuevo_dato)
{
if (arbol == NULL)
{
	arbol = new (NAbinario);
	arbol->izq = NULL; arbol->der = NULL;
	arbol->dato = nuevo_dato;
}
else if (nuevo_dato < arbol->dato)
	abinariob_alta_recursivo (arbol->izq, nuevo_dato);
else if (nuevo_dato > arbol->dato)
	abinariob_alta_recursivo (arbol->der, nuevo_dato);
}
int main(int argc, char *argv[]) {
NAbinario*arbolito=NULL;
abinariob_alta_recursivo(arbolito,5);
abinariob_alta_recursivo(arbolito,6);
abinariob_alta_recursivo(arbolito,4);
abinariob_alta_recursivo(arbolito,2);
abinariob_alta_recursivo(arbolito,7);
abinariob_alta_recursivo(arbolito,3);
barrido_postorden_iterativo(arbolito);
return 0;
}

