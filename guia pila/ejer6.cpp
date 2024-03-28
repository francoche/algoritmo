#include <iostream>

#include <cmath>
using namespace std;
struct nodo_pila
{ int dato;
nodo_pila* link;
};
void agregarpila(nodo_pila*&p,int n){
	nodo_pila *nuevo_nodo=new nodo_pila();
	nuevo_nodo->dato=n;
	nuevo_nodo->link=p;
	p=nuevo_nodo;
}
	
	int sacarpila(nodo_pila*&p){
		nodo_pila *nodo_anterior;
		nodo_anterior=p;
		int aux=p->dato;
		p=p->link;
		delete nodo_anterior;
		return aux;
	}
	
	bool capicua(int numero){
		nodo_pila *p=NULL;int primero;int ultimo;
		int aux=numero;int cont=0;int aux2;
		if(numero<10){
			return true;
		}
		while(aux>1){
			aux=aux/10;
			agregarpila(p,aux);
			if(cont==0){
			aux2=aux;}
			primero=sacarpila(p);
			cont++;
			if(aux<10){
				aux=0;
			}
		}
		aux2=aux2*10;
		ultimo=numero-aux2;
		
		if(primero==ultimo){
			return true;
		}else{
			return false;
		}
	
	}
	

int main(int argc, char *argv[]) {
	int c=3532321342311232133;
	bool aux=capicua(c);
	cout<<aux;
	return 0;
}

