#include <iostream>
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
void sacarpila(nodo_pila*&p){
	nodo_pila *nodo_anterior;
	nodo_anterior=p;
	int aux=p->dato;
	p=p->link;
	delete nodo_anterior;
	cout<< aux;
	}	
void dec2bin(int n){
	int divisor=2;int aux;nodo_pila *p=NULL;int cont=0;
	while(n>=divisor){
		aux=n%divisor;
		agregarpila(p,aux);
		n/=divisor;
		if(n==1){
			agregarpila(p,n);
			
		}
	}
	while(p!=NULL){
		sacarpila(p);
	}
}

int main(int argc, char *argv[]) {
	int c=4;
	dec2bin(c);
	return 0;
}

