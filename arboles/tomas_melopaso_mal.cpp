#include <iostream>
using namespace std;
struct NAbinario{
	int dato;
	NAbinario* der;
	NAbinario* izq;
	NAbinario* padre;
};
void destruir_nodo(NAbinario *nodoEliminar){
	nodoEliminar->izq = NULL;
	nodoEliminar->der = NULL;
	delete nodoEliminar;
}
void reemplazar(NAbinario *arbol, NAbinario *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}
NAbinario *minimo(NAbinario *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{ //Si no tiene mas hijo izq
		return arbol;
	}
}
	
	
void eliminar_nodo(NAbinario *nodoEliminar){
if(nodoEliminar->izq && nodoEliminar->der){
	NAbinario *menor = minimo(nodoEliminar->der) ;
	nodoEliminar->dato = menor->dato;
	eliminar_nodo(menor);
}
else if(nodoEliminar->izq){  //Si tiene un hijo izq solamente
	reemplazar(nodoEliminar, nodoEliminar->izq);
	destruir_nodo(nodoEliminar);
}
else if(nodoEliminar->der){  //Si tiene un hijo der solamente
	reemplazar(nodoEliminar, nodoEliminar->der);
	destruir_nodo(nodoEliminar);
}
else{  //Si es una hoja
	reemplazar(nodoEliminar, NULL);
	destruir_nodo(nodoEliminar);
}
}
		
		
/*void destruir_nodo(NAbinario *nodoEliminar){
	nodoEliminar->izq = NULL;
	nodoEliminar->der = NULL;
	delete nodoEliminar;
}*/
void eliminar(NAbinario *arbol, int dato_eliminar){
if(arbol == NULL){
return;
}
else if(dato_eliminar < arbol->dato){
eliminar(arbol->izq, dato_eliminar);
}
else if(dato_eliminar > arbol->dato){
eliminar(arbol->der, dato_eliminar);
}
else{	// arbol->dato == dato_eliminar 
eliminar_nodo(arbol);
}
}

/*NAbinario *minimo(NAbinario *arbol){
if(arbol == NULL){
return NULL;
}
if(arbol->izq){
return minimo(arbol->izq);
}
else{ //Si no tiene mas hijo izq
return arbol;
}
}*/

/*void eliminar_nodo(NAbinario *nodoEliminar){
if(nodoEliminar->izq && nodoEliminar->der){
	NAbinario *menor = minimo(nodoEliminar->der) ;
	nodoEliminar->dato = menor->dato;
	eliminar_nodo(menor);
}
else if(nodoEliminar->izq){  //Si tiene un hijo izq solamente
	reemplazar(nodoEliminar, nodoEliminar->izq);
	destruir_nodo(nodoEliminar);
}
else if(nodoEliminar->der){  //Si tiene un hijo der solamente
	reemplazar(nodoEliminar, nodoEliminar->der);
	destruir_nodo(nodoEliminar);
}
else{  //Si es una hoja
	reemplazar(nodoEliminar, NULL);
	destruir_nodo(nodoEliminar);
}
}*/

/*void reemplazar(NAbinario *arbol, NAbinario *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}
	
/*void destruir_nodo(NAbinario *nodoEliminar){
	nodoEliminar->izq = NULL;
	nodoEliminar->der = NULL;
	delete nodoEliminar;
}*/
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
	eliminar(arbolito,2);
	return 0;
}

