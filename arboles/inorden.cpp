#include <iostream>
using namespace std;

/*Inorden
si (arbol!=NULL)
pila<-(arbol,1)
mientras(!pila_vacia(pila))
(aux,bandera)<-pila
si (bandera==1)
pila<-(aux,2)
si(izquierda(aux)!=null)
pila<-(izquierda(aux),1)
sino
procesar(aux)
si (derecha(aux)!=NULL)
pila<-(derecha,1)
finmientras
bandera=se ve las veces que pasa por el nodo;
barrido inorden en un arbol binarios de búsqueda da los resultados acomodados en resultado ascendente, el resultado inverso está dado por dri, se invierte el lugar de la derecha por la izquierda
*/


struct NAbinario{
	int dato;
	NAbinario* der;
	NAbinario* izq;
};

struct pila{
	NAbinario* dato;
	int bandera;
	pila* sig;
};

void pila_poner (pila *&p, NAbinario *arbol,int b){
	pila* nuevo_nodo = new(pila);
	nuevo_nodo->dato = arbol;
	nuevo_nodo->bandera = b;
	nuevo_nodo->sig = p;
	p = nuevo_nodo;
}
	
NAbinario * pila_sacar(pila *&p,int &b){
	pila* nodo_anterior = p;
	NAbinario *dato = p->dato;
	b = p->bandera;
	p = p->sig;
	delete nodo_anterior;
	return dato;
}
	
bool pila_vacia(pila* p){
	return(p==NULL);
}
	
void barrido_inorden_iterativo(NAbinario *arbol){
	NAbinario *aux;
	pila *pila=NULL;
	int bandera;
	if (arbol!=NULL){
		bandera=1;
		pila_poner(pila,arbol,bandera);	
	}
	while (!pila_vacia(pila)){
		aux=pila_sacar(pila,bandera);
		if (bandera==1){
			pila_poner(pila,aux,2);
			if (aux->izq!=NULL){
				pila_poner(pila,aux->izq,1);	
			}
		}
		else  {
			cout<<aux->dato<<" ";
			if(aux->der!=NULL){
				pila_poner(pila,aux->der,1);
			}
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
	barrido_inorden_iterativo(arbolito);
	return 0;
}

