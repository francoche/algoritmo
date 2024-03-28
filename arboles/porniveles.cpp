#include <iostream>
using namespace std;

/*Por niveles
cola<-arbol
mientras(!cola_vacia(cola))
aux<-cola
procesar(aux)
si(izquierda(aux)!=NULL)
cola<-izquierda(aux)
si(derecha(aux)!=NULL)
cola<-derecho(aux)
finmientras	
usa una cola, prestar atencion a eso
*/

struct NAbinario{
	int dato;
	NAbinario *der;
	NAbinario *izq;
};
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
			
void barrido_por_niveles_iterativo(NAbinario *arbol){
	cola *frente=NULL;
	cola *fondo=NULL;
	NAbinario *aux;
	
	cola_agregar(frente,fondo,arbol);
	while (!cola_vacia(frente)){
		aux=cola_obtener(frente,fondo);	
		cout<<aux->dato<<" ";
		if (aux->izq!=NULL){
			cola_agregar(frente,fondo,aux->izq);	
			
		}
		if (aux->der!=NULL){
			cola_agregar(frente,fondo,aux->der);
			
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
	abinariob_alta_recursivo(arbolito,10);
	abinariob_alta_recursivo(arbolito,7);
	abinariob_alta_recursivo(arbolito,12);
	abinariob_alta_recursivo(arbolito,6);
	abinariob_alta_recursivo(arbolito,8);
	abinariob_alta_recursivo(arbolito,11);
	abinariob_alta_recursivo(arbolito,13);
	barrido_por_niveles_iterativo(arbolito);
	return 0;
}

