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
	nuevo_nodo=NULL;
}

int sacarpila(nodo_pila*&p){
	nodo_pila *nodo_anterior;
	nodo_anterior=p;
	int aux=p->dato;
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
	
int main(int argc, char *argv[]) {
	nodo_pila *p=NULL;
	agregarpila(p,3);
	agregarpila(p,4);
	agregarpila(p,5);
	cout<<sacarpila(p);
	cout<<sacarpila(p);
	cout<<sacarpila(p);
	cout<<pilavacia(p);
	return 0;
}

