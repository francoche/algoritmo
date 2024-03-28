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
	struct cola{
		NAbinario *dato;
		cola *sig;
	};
	
	void cola_agregar (cola*&fr,cola *&fo,NAbinario *arbol){
		cola *aux = new(cola);
		aux->dato=arbol;
		aux->sig=NULL;
		if(fr==NULL){
			fr=aux;
		}
		else{
			fo->sig=aux;
		}
		fo=aux;
	}
		
		NAbinario *cola_obtener (cola *&fr,cola *&fo){
			NAbinario *dato = fr->dato;
			cola *aux = fr;
			fr = fr->sig;
			delete aux;
			if(fr==NULL){
				fo=NULL;	
			}
			return dato;
		}
			
			bool cola_vacia(cola *fr){
				return(fr==NULL);
			}

void altura_arbol_iterativo_por_niveles(NAbinario *arbol) {
	
	cola *frente = NULL;
	cola *fondo = NULL;
	NAbinario *aux = NULL;
	int altura = 0;  // Variable para almacenar la altura del árbol
	
	cola_agregar(frente, fondo, arbol);
	cola_agregar(frente, fondo, NULL);  // Marca el final del nivel actual
	
	while (!cola_vacia(frente)) {
		aux = cola_obtener(frente, fondo);
		
		// Verifica si se alcanzó el final del nivel actual
		if (aux == NULL) {
			if (!cola_vacia(frente)) {
				cola_agregar(frente, fondo, NULL);  // Marca el final del siguiente nivel
			}
			altura++;  // Incrementa la altura del árbol
		} else {
			if (aux->izq != NULL) {
				cola_agregar(frente, fondo, aux->izq);
			}
			if (aux->der != NULL) {
				cola_agregar(frente, fondo, aux->der);
			}
		}
	}
	cout << "La altura del árbol es: " << altura << endl;
}

int main(int argc, char *argv[]) {
	NAbinario *arbolito=NULL;
	agregar_arbol(arbolito,5);
	agregar_arbol(arbolito,6);
	agregar_arbol(arbolito,4);
	agregar_arbol(arbolito,2);
	agregar_arbol(arbolito,7);
	agregar_arbol(arbolito,3);
	int altura2=altura(arbolito);
	cout<<"la altura es: "<<altura2<<endl;
	int altura3=altura_arbol(arbolito);
	cout<<"la altura es: "<<altura3<<endl;
	altura_arbol_iterativo_por_niveles(arbolito);
	return 0;
}

