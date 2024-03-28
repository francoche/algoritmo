#include <iostream>
using namespace std;

/*Postorden
si (arbol!=NULL)
pila<-(arbol,1)
mientras(!pila_vacia(pila))
aux,bandera)<-pila
si (bandera==1)
pila<-(aux,2)
si(izquierda(aux)!=null)
pila<-(izquierda(aux),1)
si(bandera==2)
pila<-(aux,3)
si (derecho(aux)!=NULL)
pila<-(derecho(aux),1)
si (bandera==3)
procesar(aux)
finmientras
*/

struct nodo_arbol_binario{
	int dato;
	nodo_arbol_binario* der;
	nodo_arbol_binario* izq;
};

struct pila{
	nodo_arbol_binario* dato;
	int bandera;
	pila* sig;
};

void pila_poner (pila *&p, nodo_arbol_binario *arbol,int b){
	pila* nuevo_nodo = new pila();
	nuevo_nodo->dato = arbol;
	nuevo_nodo->bandera = b;
	nuevo_nodo->sig = p;
	p = nuevo_nodo;
}
	
nodo_arbol_binario * pila_sacar (pila *&p,int &b){
	pila* nodo_anterior;
	nodo_anterior = p;
	nodo_arbol_binario *dato = p->dato;
	b = p->bandera;
	p = p->sig;
	delete nodo_anterior;
	return dato;
}
	
bool pila_vacia(pila* p){
	//return(p==NULL);
	if(p==NULL){
		return true;}
	else{
		return false;
	}
}	
		
void barrido_postorden_iterativo(nodo_arbol_binario *arbol){
	nodo_arbol_binario *aux;
	pila *pil=NULL;
	int bandera;
	if (arbol!=NULL){
		bandera=1;
		pila_poner(pil,arbol,bandera);	
	}
	while (!pila_vacia(pil)){
		aux=pila_sacar(pil,bandera);
		if (bandera==1){
			pila_poner(pil,aux,2);
			if (aux->izq!=NULL){
				pila_poner(pil,aux->izq,1);	
			}
		}
		else if (bandera==2){
			pila_poner(pil,aux,3);	
			if (aux->der!=NULL){
				pila_poner(pil,aux->der,1);	
			}	
		}
		else if (bandera==3){
			cout<<aux->dato<<" ";	
		}
	}
}
void abinariob_alta_recursivo (nodo_arbol_binario* &arbol, int nuevo_dato)
{
	if (arbol == NULL)
	{
		arbol = new (nodo_arbol_binario);
		arbol->izq = NULL; arbol->der = NULL;
		arbol->dato = nuevo_dato;
	}
	else if (nuevo_dato < arbol->dato)
		abinariob_alta_recursivo (arbol->izq, nuevo_dato);
	else if (nuevo_dato > arbol->dato)
		abinariob_alta_recursivo (arbol->der, nuevo_dato);
}
int main(int argc, char *argv[]) {
	nodo_arbol_binario*arbolito=NULL;
	abinariob_alta_recursivo(arbolito,5);
	abinariob_alta_recursivo(arbolito,6);
	abinariob_alta_recursivo(arbolito,4);
	abinariob_alta_recursivo(arbolito,2);
	abinariob_alta_recursivo(arbolito,7);
	abinariob_alta_recursivo(arbolito,3);
	barrido_postorden_iterativo(arbolito);
	return 0;
}
