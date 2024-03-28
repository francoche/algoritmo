#include <iostream>
using namespace std;
struct NAbinario{
	int dato;
	NAbinario* der;
	NAbinario* izq;
};
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
void abinario_preorden_recursivo_menor (NAbinario* arbol,int &menor)
{
	if (arbol != NULL)
	{
		cout << arbol->dato << "  ";
		if(arbol->dato<menor){
			menor=arbol->dato;
		}
		abinario_preorden_recursivo_menor (arbol->izq,menor);
		abinario_preorden_recursivo_menor  (arbol->der,menor);
	}
}
int main(int argc, char *argv[]) {
	NAbinario *arbolito=NULL;
	int menor=100000000000;
	agregar_arbol(arbolito,5);
	agregar_arbol(arbolito,6);
	agregar_arbol(arbolito,4);
	agregar_arbol(arbolito,2);
	agregar_arbol(arbolito,7);
	agregar_arbol(arbolito,3);
	abinario_preorden_recursivo_menor (arbolito,menor);
	cout<<"el menor dato es: "<<menor;
	return 0;
}

