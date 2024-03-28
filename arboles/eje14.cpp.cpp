#include <iostream>
using namespace std;

struct nodo_arbol_binario{
	int dato;
	struct nodo_arbol_binario* izq;
	struct nodo_arbol_binario* der;
	struct nodo_arbol_binario* padre;
};
typedef struct nodo_arbol_binario NABinario;

void abinariob_alta_recursivo(NABinario *&, int, NABinario *);
NABinario *crearNodo(int, NABinario *padre);

void abinario_mostrar_recursivo(NABinario*, int tabulado = 0);

bool busqueda(NABinario *, int);

void abinario_preorden(NABinario *);
void abinario_inorden(NABinario *);
void abinario_postorden(NABinario *);
void abinario_mayor_menor(NABinario *);

void eliminar(NABinario *, int);
void eliminar_nodo(NABinario *);
NABinario *minimo(NABinario *);
void reemplazar(NABinario *, NABinario *);
void destruir_nodo(NABinario *);

int main(int argc, char *argv[]) {
	NABinario *arbol = NULL;
	int dato, opcion, nBuscar, dato_eliminar, tabulado = 0;
	
	abinariob_alta_recursivo(arbol, 8, NULL);
	abinariob_alta_recursivo(arbol, 3, NULL);
	abinariob_alta_recursivo(arbol, 6, NULL);
	abinariob_alta_recursivo(arbol, 1, NULL);
	abinariob_alta_recursivo(arbol, 4, NULL);
	abinariob_alta_recursivo(arbol, 7, NULL);
	abinariob_alta_recursivo(arbol, 10, NULL);
	abinariob_alta_recursivo(arbol, 14, NULL);
	abinariob_alta_recursivo(arbol, 13, NULL);
	do{
		cout<<"1.Insertar nuevo nodo."<<endl;
		cout<<"2.Mostrar arbol."<<endl;
		cout<<"3.Buscar elemento en el arbol."<<endl;
		cout<<"4.Preorden."<<endl;
		cout<<"5.Inorden."<<endl;
		cout<<"6.Postorden."<<endl;
		cout<<"7.Eliminar un nodo del arbol."<<endl;
		cout<<"8.Salir."<<endl;
		cin>>opcion;
		
		switch(opcion){
		case 1:
			cout<<"\nDigite un numero: ";
			cin>>dato;
			abinariob_alta_recursivo(arbol, dato, NULL);
			cout<<endl;
			break;
		case 2: 
			cout<<"\nEl arbol es: "<<endl;
			abinario_mostrar_recursivo(arbol, tabulado);
			cout<<endl;
			break;
		case 3: 
			cout<<"\nIngrese elemento que desea buscar: "<<endl;
			cin>>nBuscar;
			if(busqueda(arbol, nBuscar) == true){
				cout<<"El dato ingresado se encuentra en el arbol.";
			}
			else{
				cout<<"El dato ingresado no se encuentra en el arbol.";
			}
			cout<<"\n\n";
			break;
		case 4:
			cout<<"Poreorden(RID): ";
			abinario_preorden(arbol);
			cout<<"\n\n";
			break;
		case 5:
			cout<<"Inorden(IRD): ";
			abinario_inorden(arbol);
			cout<<"\n\n";
			break;
		case 6:
			cout<<"Postorden(IDR): ";
			abinario_postorden(arbol);
			cout<<"\n\n";
			break;
		case 7: 
			cout<<"Ingrese dato que desea eliminar: ";
			cin>>dato_eliminar;
			eliminar(arbol, dato_eliminar);
			cout<<"\n\n";
			break;
		}
	}while(opcion != 8);
	return 0;
}

NABinario *crearNodo(int n,NABinario *padre){
	NABinario *nuevo_nodo = new NABinario();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}
	
void abinariob_alta_recursivo(NABinario *&arbol, int nuevo_dato, NABinario *padre){

	if (arbol == NULL){ //Si el arbol esta vacio, crea un nuevo nodo
		NABinario *nuevo_nodo = crearNodo(nuevo_dato, padre);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if (nuevo_dato < valorRaiz){
			abinariob_alta_recursivo (arbol->izq, nuevo_dato, arbol);
		}
		else if(nuevo_dato > valorRaiz){
			abinariob_alta_recursivo (arbol->der, nuevo_dato, arbol);
		}
	}
}

void abinario_mostrar_recursivo(NABinario* arbol, int tabulado){
	if (arbol != NULL)
	{		
		cout << "Nodo: " << arbol->dato << " | " << "Izq-> ";
		if (arbol->izq != NULL)
			cout << arbol->izq->dato;
		else
			cout << "NULL";
		cout << "  " << "Der-> ";
		if (arbol->der != NULL)
			cout << arbol->der->dato;
		else
			cout << "NULL";
		cout << endl;
		
		tabulado++;
		abinario_mostrar_recursivo (arbol->izq, tabulado);
		abinario_mostrar_recursivo (arbol->der, tabulado);
	}
}
	
bool busqueda(NABinario *arbol, int datoBuscar){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == datoBuscar){
		return true;
	}
	else if(datoBuscar < arbol->dato){
		return busqueda(arbol->izq, datoBuscar);
	}
	else{
		return busqueda(arbol->der, datoBuscar);
	}
}

void abinario_preorden(NABinario *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout << arbol->dato <<"  ";
		abinario_preorden(arbol->izq);
		abinario_preorden(arbol->der);
	}
}

void abinario_inorden(NABinario *arbol){	//de menor a mayor 
	if(arbol == NULL){
		return;
	}
	else{
		abinario_inorden(arbol->izq);
		cout << arbol->dato << "  ";
		abinario_inorden(arbol->der);
	}
}

void abinario_postorden(NABinario *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		abinario_postorden(arbol->izq);
		abinario_postorden(arbol->der);
		cout << arbol->dato << "  ";
	}
}

void eliminar(NABinario *arbol, int dato_eliminar){
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
	
NABinario *minimo(NABinario *arbol){
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

void eliminar_nodo(NABinario *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		NABinario *menor = minimo(nodoEliminar->der) ;
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

void reemplazar(NABinario *arbol, NABinario *nuevoNodo){
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
void destruir_nodo(NABinario *nodoEliminar){
	nodoEliminar->izq = NULL;
	nodoEliminar->der = NULL;
	delete nodoEliminar;
}

	
